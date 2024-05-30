[numthreads(1, 1, 1)]
void unused_entry_point() {
  return;
}

cbuffer cbuffer_U : register(b0) {
  uint4 U[1];
};

void f() {
  float3 v = asfloat(U[0].xyz);
  float x = asfloat(U[0].x);
  float y = asfloat(U[0].y);
  float z = asfloat(U[0].z);
  float2 xx = asfloat(U[0].xyz).xx;
  float2 xy = asfloat(U[0].xyz).xy;
  float2 xz = asfloat(U[0].xyz).xz;
  float2 yx = asfloat(U[0].xyz).yx;
  float2 yy = asfloat(U[0].xyz).yy;
  float2 yz = asfloat(U[0].xyz).yz;
  float2 zx = asfloat(U[0].xyz).zx;
  float2 zy = asfloat(U[0].xyz).zy;
  float2 zz = asfloat(U[0].xyz).zz;
  float3 xxx = asfloat(U[0].xyz).xxx;
  float3 xxy = asfloat(U[0].xyz).xxy;
  float3 xxz = asfloat(U[0].xyz).xxz;
  float3 xyx = asfloat(U[0].xyz).xyx;
  float3 xyy = asfloat(U[0].xyz).xyy;
  float3 xyz = asfloat(U[0].xyz).xyz;
  float3 xzx = asfloat(U[0].xyz).xzx;
  float3 xzy = asfloat(U[0].xyz).xzy;
  float3 xzz = asfloat(U[0].xyz).xzz;
  float3 yxx = asfloat(U[0].xyz).yxx;
  float3 yxy = asfloat(U[0].xyz).yxy;
  float3 yxz = asfloat(U[0].xyz).yxz;
  float3 yyx = asfloat(U[0].xyz).yyx;
  float3 yyy = asfloat(U[0].xyz).yyy;
  float3 yyz = asfloat(U[0].xyz).yyz;
  float3 yzx = asfloat(U[0].xyz).yzx;
  float3 yzy = asfloat(U[0].xyz).yzy;
  float3 yzz = asfloat(U[0].xyz).yzz;
  float3 zxx = asfloat(U[0].xyz).zxx;
  float3 zxy = asfloat(U[0].xyz).zxy;
  float3 zxz = asfloat(U[0].xyz).zxz;
  float3 zyx = asfloat(U[0].xyz).zyx;
  float3 zyy = asfloat(U[0].xyz).zyy;
  float3 zyz = asfloat(U[0].xyz).zyz;
  float3 zzx = asfloat(U[0].xyz).zzx;
  float3 zzy = asfloat(U[0].xyz).zzy;
  float3 zzz = asfloat(U[0].xyz).zzz;
  float4 xxxx = asfloat(U[0].xyz).xxxx;
  float4 xxxy = asfloat(U[0].xyz).xxxy;
  float4 xxxz = asfloat(U[0].xyz).xxxz;
  float4 xxyx = asfloat(U[0].xyz).xxyx;
  float4 xxyy = asfloat(U[0].xyz).xxyy;
  float4 xxyz = asfloat(U[0].xyz).xxyz;
  float4 xxzx = asfloat(U[0].xyz).xxzx;
  float4 xxzy = asfloat(U[0].xyz).xxzy;
  float4 xxzz = asfloat(U[0].xyz).xxzz;
  float4 xyxx = asfloat(U[0].xyz).xyxx;
  float4 xyxy = asfloat(U[0].xyz).xyxy;
  float4 xyxz = asfloat(U[0].xyz).xyxz;
  float4 xyyx = asfloat(U[0].xyz).xyyx;
  float4 xyyy = asfloat(U[0].xyz).xyyy;
  float4 xyyz = asfloat(U[0].xyz).xyyz;
  float4 xyzx = asfloat(U[0].xyz).xyzx;
  float4 xyzy = asfloat(U[0].xyz).xyzy;
  float4 xyzz = asfloat(U[0].xyz).xyzz;
  float4 xzxx = asfloat(U[0].xyz).xzxx;
  float4 xzxy = asfloat(U[0].xyz).xzxy;
  float4 xzxz = asfloat(U[0].xyz).xzxz;
  float4 xzyx = asfloat(U[0].xyz).xzyx;
  float4 xzyy = asfloat(U[0].xyz).xzyy;
  float4 xzyz = asfloat(U[0].xyz).xzyz;
  float4 xzzx = asfloat(U[0].xyz).xzzx;
  float4 xzzy = asfloat(U[0].xyz).xzzy;
  float4 xzzz = asfloat(U[0].xyz).xzzz;
  float4 yxxx = asfloat(U[0].xyz).yxxx;
  float4 yxxy = asfloat(U[0].xyz).yxxy;
  float4 yxxz = asfloat(U[0].xyz).yxxz;
  float4 yxyx = asfloat(U[0].xyz).yxyx;
  float4 yxyy = asfloat(U[0].xyz).yxyy;
  float4 yxyz = asfloat(U[0].xyz).yxyz;
  float4 yxzx = asfloat(U[0].xyz).yxzx;
  float4 yxzy = asfloat(U[0].xyz).yxzy;
  float4 yxzz = asfloat(U[0].xyz).yxzz;
  float4 yyxx = asfloat(U[0].xyz).yyxx;
  float4 yyxy = asfloat(U[0].xyz).yyxy;
  float4 yyxz = asfloat(U[0].xyz).yyxz;
  float4 yyyx = asfloat(U[0].xyz).yyyx;
  float4 yyyy = asfloat(U[0].xyz).yyyy;
  float4 yyyz = asfloat(U[0].xyz).yyyz;
  float4 yyzx = asfloat(U[0].xyz).yyzx;
  float4 yyzy = asfloat(U[0].xyz).yyzy;
  float4 yyzz = asfloat(U[0].xyz).yyzz;
  float4 yzxx = asfloat(U[0].xyz).yzxx;
  float4 yzxy = asfloat(U[0].xyz).yzxy;
  float4 yzxz = asfloat(U[0].xyz).yzxz;
  float4 yzyx = asfloat(U[0].xyz).yzyx;
  float4 yzyy = asfloat(U[0].xyz).yzyy;
  float4 yzyz = asfloat(U[0].xyz).yzyz;
  float4 yzzx = asfloat(U[0].xyz).yzzx;
  float4 yzzy = asfloat(U[0].xyz).yzzy;
  float4 yzzz = asfloat(U[0].xyz).yzzz;
  float4 zxxx = asfloat(U[0].xyz).zxxx;
  float4 zxxy = asfloat(U[0].xyz).zxxy;
  float4 zxxz = asfloat(U[0].xyz).zxxz;
  float4 zxyx = asfloat(U[0].xyz).zxyx;
  float4 zxyy = asfloat(U[0].xyz).zxyy;
  float4 zxyz = asfloat(U[0].xyz).zxyz;
  float4 zxzx = asfloat(U[0].xyz).zxzx;
  float4 zxzy = asfloat(U[0].xyz).zxzy;
  float4 zxzz = asfloat(U[0].xyz).zxzz;
  float4 zyxx = asfloat(U[0].xyz).zyxx;
  float4 zyxy = asfloat(U[0].xyz).zyxy;
  float4 zyxz = asfloat(U[0].xyz).zyxz;
  float4 zyyx = asfloat(U[0].xyz).zyyx;
  float4 zyyy = asfloat(U[0].xyz).zyyy;
  float4 zyyz = asfloat(U[0].xyz).zyyz;
  float4 zyzx = asfloat(U[0].xyz).zyzx;
  float4 zyzy = asfloat(U[0].xyz).zyzy;
  float4 zyzz = asfloat(U[0].xyz).zyzz;
  float4 zzxx = asfloat(U[0].xyz).zzxx;
  float4 zzxy = asfloat(U[0].xyz).zzxy;
  float4 zzxz = asfloat(U[0].xyz).zzxz;
  float4 zzyx = asfloat(U[0].xyz).zzyx;
  float4 zzyy = asfloat(U[0].xyz).zzyy;
  float4 zzyz = asfloat(U[0].xyz).zzyz;
  float4 zzzx = asfloat(U[0].xyz).zzzx;
  float4 zzzy = asfloat(U[0].xyz).zzzy;
  float4 zzzz = asfloat(U[0].xyz).zzzz;
}
