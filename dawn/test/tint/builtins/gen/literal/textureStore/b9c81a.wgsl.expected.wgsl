@group(1) @binding(0) var arg_0 : texture_storage_3d<rg32uint, read_write>;

fn textureStore_b9c81a() {
  textureStore(arg_0, vec3<i32>(1i), vec4<u32>(1u));
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  textureStore_b9c81a();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  textureStore_b9c81a();
}

@compute @workgroup_size(1)
fn compute_main() {
  textureStore_b9c81a();
}
