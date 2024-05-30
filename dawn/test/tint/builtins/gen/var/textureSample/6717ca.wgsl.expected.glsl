#version 310 es
precision highp float;

uniform highp sampler2DArray arg_0_arg_1;

layout(binding = 0, std430) buffer prevent_dce_block_ssbo {
  vec4 inner;
} prevent_dce;

void textureSample_6717ca() {
  vec2 arg_2 = vec2(1.0f);
  int arg_3 = 1;
  vec4 res = texture(arg_0_arg_1, vec3(arg_2, float(arg_3)));
  prevent_dce.inner = res;
}

void fragment_main() {
  textureSample_6717ca();
}

void main() {
  fragment_main();
  return;
}
