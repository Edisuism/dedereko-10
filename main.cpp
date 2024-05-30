#include <GLFW/glfw3.h>
#include <webgpu/webgpu_cpp.h>
#include <iostream>
#if defined(__EMSCRIPTEN__)
#include <emscripten/emscripten.h>
#else
#include <webgpu/webgpu_glfw.h>
#endif

wgpu::Instance instance;
wgpu::Device device;
wgpu::RenderPipeline pipeline;

wgpu::SwapChain swapChain;
const uint32_t kWidth = 512;
const uint32_t kHeight = 512;

wgpu::BufferDescriptor bufferDesc;
wgpu::Buffer vertexBuffer;

std::vector<float> vertexData = {
    -0.5, -0.5, 1.0, 0.0, 0.0,

    +0.5, -0.5, 0.0, 1.0, 0.0,

    +0.0,   +0.5, 0.0, 0.0, 1.0,
};

int vertexCount = static_cast<int>(vertexData.size() / 5);

void SetupSwapChain(wgpu::Surface surface) {
  wgpu::SwapChainDescriptor scDesc{
      .usage = wgpu::TextureUsage::RenderAttachment,
      .format = wgpu::TextureFormat::BGRA8Unorm,
      .width = kWidth,
      .height = kHeight,
      .presentMode = wgpu::PresentMode::Fifo};
  swapChain = device.CreateSwapChain(surface, &scDesc);
}

void GetDevice(void (*callback)(wgpu::Device)) {
  instance.RequestAdapter(
      nullptr,
      // TODO(https://bugs.chromium.org/p/dawn/issues/detail?id=1892): Use
      // wgpu::RequestAdapterStatus, wgpu::Adapter, and wgpu::Device.
      [](WGPURequestAdapterStatus status, WGPUAdapter cAdapter,
         const char* message, void* userdata) {
        if (status != WGPURequestAdapterStatus_Success) {
          exit(0);
        }
        wgpu::Adapter adapter = wgpu::Adapter::Acquire(cAdapter);
        adapter.RequestDevice(
            nullptr,
            [](WGPURequestDeviceStatus status, WGPUDevice cDevice,
               const char* message, void* userdata) {
              wgpu::Device device = wgpu::Device::Acquire(cDevice);
              device.SetUncapturedErrorCallback(
                  [](WGPUErrorType type, const char* message, void* userdata) {
                    std::cout << "Error: " << type << " - message: " << message;
                  },
                  nullptr);
              reinterpret_cast<void (*)(wgpu::Device)>(userdata)(device);
            },
            userdata);
      },
      reinterpret_cast<void*>(callback));
}

const char shaderCode[] = R"(
struct VertexInput {
	@location(0) position: vec2f,
	@location(1) color : vec3f,
};

struct VertexOutput {
    @builtin(position) position: vec4f,
    // The location here does not refer to a vertex attribute, it just means
    // that this field must be handled by the rasterizer.
    // (It can also refer to another field of another struct that would be used
    // as input to the fragment shader.)
    @location(0) color: vec3f,
};


// The `@location(0)` attribute means that this input variable is described
// by the vertex buffer layout at index 0 in the `pipelineDesc.vertex.buffers`
// array.
// The type `vec2f` must comply with what we will declare in the layout.
// The argument name `in_vertex_position` is up to you, it is only internal to
// the shader code!
@vertex
fn vs_main(in: VertexInput) -> VertexOutput {
	var out: VertexOutput;
    out.position = vec4f(in.position, 0.0, 1.0);
    out.color = in.color; // forward to the fragment shader
    return out;
}

@fragment
fn fs_main(in: VertexOutput) -> @location(0) vec4f {
    return vec4f(in.color, 1.0);
}
)";

void CreateRenderPipeline() {
  wgpu::ShaderModuleWGSLDescriptor wgslDesc{};
  wgslDesc.code = shaderCode;

  wgpu::ShaderModuleDescriptor shaderModuleDescriptor{
      .nextInChain = &wgslDesc};
  wgpu::ShaderModule shaderModule =
      device.CreateShaderModule(&shaderModuleDescriptor);

  std::vector<wgpu::VertexAttribute> vertexAttribs(2);
  // Position attribute
  vertexAttribs[0].shaderLocation = 0;
  vertexAttribs[0].format = wgpu::VertexFormat::Float32x2;
  vertexAttribs[0].offset = 0;
  // Color attribute
  vertexAttribs[1].shaderLocation = 1;
  vertexAttribs[1].format = wgpu::VertexFormat::Float32x3; 
  vertexAttribs[1].offset = 2 * sizeof(float); 

  wgpu::VertexBufferLayout vertexBufferLayout;
  vertexBufferLayout.attributeCount = static_cast<uint32_t>(vertexAttribs.size());
  vertexBufferLayout.attributes = vertexAttribs.data();
  vertexBufferLayout.arrayStride = 5 * sizeof(float);
  vertexBufferLayout.stepMode = wgpu::VertexStepMode::Vertex;

  wgpu::BlendState blendState{
      .color = {.operation = wgpu::BlendOperation::Add,
                .srcFactor = wgpu::BlendFactor::SrcAlpha,
                .dstFactor = wgpu::BlendFactor::OneMinusSrcAlpha},
      .alpha = {.operation = wgpu::BlendOperation::Add,
                .srcFactor = wgpu::BlendFactor::Zero,
                .dstFactor = wgpu::BlendFactor::One}
  };

  wgpu::ColorTargetState colorTargetState{
      .format = wgpu::TextureFormat::BGRA8Unorm,
      .blend = &blendState,
      .writeMask = wgpu::ColorWriteMask::All};

  wgpu::FragmentState fragmentState{.module = shaderModule,
                                    .entryPoint = "fs_main",
                                    .constantCount = 0,
                                    .constants = nullptr,
                                    .targetCount = 1,
                                    .targets = &colorTargetState};

  wgpu::PipelineLayoutDescriptor layoutDescriptor{
    .bindGroupLayoutCount = 0,
    .bindGroupLayouts = nullptr
  };
  wgpu::PipelineLayout layout = device.CreatePipelineLayout(&layoutDescriptor);

  wgpu::RenderPipelineDescriptor descriptor{
      .layout = layout,
      .vertex = {.module = shaderModule,
                 .entryPoint = "vs_main",
                 .constantCount = 0,
                 .constants = nullptr,
                 .bufferCount = 1,
                 .buffers = &vertexBufferLayout},
      .primitive = {.topology = wgpu::PrimitiveTopology::TriangleList,
                    .stripIndexFormat = wgpu::IndexFormat::Undefined,
                    .frontFace = wgpu::FrontFace::CCW,
                    .cullMode = wgpu::CullMode::None},
      .depthStencil = {nullptr},
      .multisample = {.count = 1,
                      .mask = ~0u,
                      .alphaToCoverageEnabled = false},
      .fragment = {&fragmentState},
  };

  pipeline = device.CreateRenderPipeline(&descriptor);
}

void Render() {
  wgpu::RenderPassColorAttachment attachment{
      .view = swapChain.GetCurrentTextureView(),
      .loadOp = wgpu::LoadOp::Clear,
      .storeOp = wgpu::StoreOp::Store};

  wgpu::RenderPassDescriptor renderpass{.colorAttachmentCount = 1,
                                        .colorAttachments = &attachment};

  wgpu::CommandEncoder encoder = device.CreateCommandEncoder();
  wgpu::RenderPassEncoder pass = encoder.BeginRenderPass(&renderpass);
  pass.SetPipeline(pipeline);
  pass.SetVertexBuffer(0, vertexBuffer, 0, vertexData.size() * sizeof(float));
  pass.Draw(vertexCount, 1, 0, 0);
  pass.End();
  wgpu::CommandBuffer commands = encoder.Finish();
  device.GetQueue().Submit(1, &commands);
}

void InitGraphics(wgpu::Surface surface) {
  SetupSwapChain(surface);
  CreateRenderPipeline();
}

void Start() {
  if (!glfwInit()) {
    return;
  }

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  GLFWwindow* window =
      glfwCreateWindow(kWidth, kHeight, "WebGPU window", nullptr, nullptr);

#if defined(__EMSCRIPTEN__)
  wgpu::SurfaceDescriptorFromCanvasHTMLSelector canvasDesc{};
  canvasDesc.selector = "#canvas";

  wgpu::SurfaceDescriptor surfaceDesc{.nextInChain = &canvasDesc};
  wgpu::Surface surface = instance.CreateSurface(&surfaceDesc);
#else
  wgpu::Surface surface = wgpu::glfw::CreateSurfaceForWindow(instance, window);
#endif

  InitGraphics(surface);

  bufferDesc.size = vertexData.size() * sizeof(float);
  bufferDesc.usage = wgpu::BufferUsage::CopyDst | wgpu::BufferUsage::Vertex;
  bufferDesc.mappedAtCreation = false;
  vertexBuffer = device.CreateBuffer(&bufferDesc);

  device.GetQueue().WriteBuffer(vertexBuffer, 0, vertexData.data(), bufferDesc.size);

#if defined(__EMSCRIPTEN__)
  emscripten_set_main_loop(Render, 0, false);
#else
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    Render();
    swapChain.Present();
    instance.ProcessEvents();
  }
#endif
}

int main() {
  instance = wgpu::CreateInstance();
  GetDevice([](wgpu::Device dev) {
    device = dev;
    Start();
  });
}
