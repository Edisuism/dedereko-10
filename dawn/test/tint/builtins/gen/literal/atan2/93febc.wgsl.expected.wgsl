enable f16;

fn atan2_93febc() {
  var res : vec2<f16> = atan2(vec2<f16>(1.0h), vec2<f16>(1.0h));
  prevent_dce = res;
}

@group(2) @binding(0) var<storage, read_write> prevent_dce : vec2<f16>;

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  atan2_93febc();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  atan2_93febc();
}

@compute @workgroup_size(1)
fn compute_main() {
  atan2_93febc();
}
