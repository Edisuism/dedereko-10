#version 310 es

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void unused_entry_point() {
  return;
}
vec2 arr[2] = vec2[2](vec2(1.0f), vec2(2.0f));
void f() {
  vec2 v[2] = arr;
}

