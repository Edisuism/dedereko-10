enable f16;

fn select_86f9bd() {
  var arg_0 = vec2<f16>(1.0h);
  var arg_1 = vec2<f16>(1.0h);
  var arg_2 = true;
  var res : vec2<f16> = select(arg_0, arg_1, arg_2);
  prevent_dce = res;
}

@group(2) @binding(0) var<storage, read_write> prevent_dce : vec2<f16>;

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  select_86f9bd();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  select_86f9bd();
}

@compute @workgroup_size(1)
fn compute_main() {
  select_86f9bd();
}
