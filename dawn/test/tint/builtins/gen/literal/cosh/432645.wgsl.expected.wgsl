fn cosh_432645() {
  var res = cosh(vec2(0.0));
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  cosh_432645();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  cosh_432645();
}

@compute @workgroup_size(1)
fn compute_main() {
  cosh_432645();
}
