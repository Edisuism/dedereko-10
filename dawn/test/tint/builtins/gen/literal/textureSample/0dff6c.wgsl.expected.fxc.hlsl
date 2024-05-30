Texture2D arg_0 : register(t0, space1);
SamplerState arg_1 : register(s1, space1);
RWByteAddressBuffer prevent_dce : register(u0, space2);

void textureSample_0dff6c() {
  float res = arg_0.Sample(arg_1, (1.0f).xx, int2((1).xx)).x;
  prevent_dce.Store(0u, asuint(res));
}

void fragment_main() {
  textureSample_0dff6c();
  return;
}
