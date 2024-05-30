@group(1) @binding(0) var arg_0 : texture_storage_1d<rgba8sint, read>;

fn textureLoad_c9cc40() {
  var res : vec4<i32> = textureLoad(arg_0, 1i);
  prevent_dce = res;
}

@group(2) @binding(0) var<storage, read_write> prevent_dce : vec4<i32>;

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  textureLoad_c9cc40();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  textureLoad_c9cc40();
}

@compute @workgroup_size(1)
fn compute_main() {
  textureLoad_c9cc40();
}
