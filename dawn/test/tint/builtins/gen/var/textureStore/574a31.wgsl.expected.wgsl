@group(1) @binding(0) var arg_0 : texture_storage_1d<rg32sint, read_write>;

fn textureStore_574a31() {
  var arg_1 = 1u;
  var arg_2 = vec4<i32>(1i);
  textureStore(arg_0, arg_1, arg_2);
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  textureStore_574a31();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  textureStore_574a31();
}

@compute @workgroup_size(1)
fn compute_main() {
  textureStore_574a31();
}
