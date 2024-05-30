enable f16;
var<private> m = mat3x2<f16>();

@group(0) @binding(0)
var<storage, read_write> out : mat3x2<f16>;

@compute @workgroup_size(1)
fn f() {
  out = m;
}
