[numthreads(1, 1, 1)]
void f() {
  const int4 a = int4(1073757184, -1006616064, -998242304, 987654321);
  const float4 b = asfloat(a);
  return;
}
