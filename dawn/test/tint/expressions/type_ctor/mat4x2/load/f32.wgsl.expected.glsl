#version 310 es

layout(binding = 0, std430) buffer tint_symbol_block_ssbo {
  mat4x2 inner;
} tint_symbol;

void f() {
  mat4x2 m = mat4x2(vec2(0.0f), vec2(0.0f), vec2(0.0f), vec2(0.0f));
  tint_symbol.inner = mat4x2(m);
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  f();
  return;
}
