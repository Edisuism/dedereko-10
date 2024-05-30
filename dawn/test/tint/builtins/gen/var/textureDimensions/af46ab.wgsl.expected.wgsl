@group(1) @binding(0) var arg_0 : texture_storage_2d_array<rg32sint, write>;

fn textureDimensions_af46ab() {
  var res : vec2<u32> = textureDimensions(arg_0);
  prevent_dce = res;
}

@group(2) @binding(0) var<storage, read_write> prevent_dce : vec2<u32>;

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  textureDimensions_af46ab();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  textureDimensions_af46ab();
}

@compute @workgroup_size(1)
fn compute_main() {
  textureDimensions_af46ab();
}
