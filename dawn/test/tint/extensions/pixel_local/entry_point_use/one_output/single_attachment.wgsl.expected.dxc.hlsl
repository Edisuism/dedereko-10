RasterizerOrderedTexture2D<uint4> pixel_local_a : register(u1);

struct PixelLocal {
  uint a;
};

static PixelLocal P = (PixelLocal)0;

void load_from_pixel_local_storage(float4 my_input) {
  const uint2 rov_texcoord = uint2(my_input.xy);
  P.a = pixel_local_a.Load(rov_texcoord).x;
}

void store_into_pixel_local_storage(float4 my_input) {
  const uint2 rov_texcoord = uint2(my_input.xy);
  pixel_local_a[rov_texcoord] = uint4((P.a).xxxx);
}

struct f_res {
  float4 output_0;
};
struct tint_symbol_1 {
  float4 my_pos : SV_Position;
};
struct tint_symbol_2 {
  float4 output_0 : SV_Target0;
};

float4 f_inner() {
  P.a = (P.a + 42u);
  return (2.0f).xxxx;
}

f_res f_inner_1(float4 my_pos) {
  const float4 hlsl_sv_position = my_pos;
  load_from_pixel_local_storage(hlsl_sv_position);
  const float4 result = f_inner();
  store_into_pixel_local_storage(hlsl_sv_position);
  const f_res tint_symbol_3 = {result};
  return tint_symbol_3;
}

tint_symbol_2 f(tint_symbol_1 tint_symbol) {
  const f_res inner_result = f_inner_1(tint_symbol.my_pos);
  tint_symbol_2 wrapper_result = (tint_symbol_2)0;
  wrapper_result.output_0 = inner_result.output_0;
  return wrapper_result;
}
