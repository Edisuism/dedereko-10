fn transpose_66fce8() {
  var res = transpose(mat3x3(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0));
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  transpose_66fce8();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  transpose_66fce8();
}

@compute @workgroup_size(1)
fn compute_main() {
  transpose_66fce8();
}
