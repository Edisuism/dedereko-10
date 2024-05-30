#version 310 es
#extension GL_AMD_gpu_shader_half_float : require

layout(binding = 0, std430) buffer prevent_dce_block_ssbo {
  f16vec2 inner;
} prevent_dce;

void atan2_93febc() {
  f16vec2 res = f16vec2(0.78515625hf);
  prevent_dce.inner = res;
}

vec4 vertex_main() {
  atan2_93febc();
  return vec4(0.0f);
}

void main() {
  gl_PointSize = 1.0;
  vec4 inner_result = vertex_main();
  gl_Position = inner_result;
  gl_Position.y = -(gl_Position.y);
  gl_Position.z = ((2.0f * gl_Position.z) - gl_Position.w);
  return;
}
#version 310 es
#extension GL_AMD_gpu_shader_half_float : require
precision highp float;

layout(binding = 0, std430) buffer prevent_dce_block_ssbo {
  f16vec2 inner;
} prevent_dce;

void atan2_93febc() {
  f16vec2 res = f16vec2(0.78515625hf);
  prevent_dce.inner = res;
}

void fragment_main() {
  atan2_93febc();
}

void main() {
  fragment_main();
  return;
}
#version 310 es
#extension GL_AMD_gpu_shader_half_float : require

layout(binding = 0, std430) buffer prevent_dce_block_ssbo {
  f16vec2 inner;
} prevent_dce;

void atan2_93febc() {
  f16vec2 res = f16vec2(0.78515625hf);
  prevent_dce.inner = res;
}

void compute_main() {
  atan2_93febc();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  compute_main();
  return;
}