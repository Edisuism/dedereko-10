[numthreads(1, 1, 1)]
void f() {
  const uint4 a = uint4(1073757184u, 3288351232u, 3296724992u, 987654321u);
  const int4 b = asint(a);
  return;
}
