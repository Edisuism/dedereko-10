enable f16;

fn frexp_5f47bf() {
  var arg_0 = vec2<f16>(1.0h);
  var res = frexp(arg_0);
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  frexp_5f47bf();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  frexp_5f47bf();
}

@compute @workgroup_size(1)
fn compute_main() {
  frexp_5f47bf();
}
