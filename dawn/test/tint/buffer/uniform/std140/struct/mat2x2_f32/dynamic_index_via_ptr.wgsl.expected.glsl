#version 310 es

struct Inner {
  mat2 m;
  uint pad;
  uint pad_1;
  uint pad_2;
  uint pad_3;
  uint pad_4;
  uint pad_5;
  uint pad_6;
  uint pad_7;
  uint pad_8;
  uint pad_9;
  uint pad_10;
  uint pad_11;
};

struct Inner_std140 {
  vec2 m_0;
  vec2 m_1;
  uint pad;
  uint pad_1;
  uint pad_2;
  uint pad_3;
  uint pad_4;
  uint pad_5;
  uint pad_6;
  uint pad_7;
  uint pad_8;
  uint pad_9;
  uint pad_10;
  uint pad_11;
};

struct Outer {
  Inner a[4];
};

struct Outer_std140 {
  Inner_std140 a[4];
};

layout(binding = 0, std140) uniform a_block_std140_ubo {
  Outer_std140 inner[4];
} a;

int counter = 0;
int i() {
  counter = (counter + 1);
  return counter;
}

Inner conv_Inner(Inner_std140 val) {
  return Inner(mat2(val.m_0, val.m_1), val.pad, val.pad_1, val.pad_2, val.pad_3, val.pad_4, val.pad_5, val.pad_6, val.pad_7, val.pad_8, val.pad_9, val.pad_10, val.pad_11);
}

Inner[4] conv_arr4_Inner(Inner_std140 val[4]) {
  Inner arr[4] = Inner[4](Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u));
  {
    for(uint i = 0u; (i < 4u); i = (i + 1u)) {
      arr[i] = conv_Inner(val[i]);
    }
  }
  return arr;
}

Outer conv_Outer(Outer_std140 val) {
  return Outer(conv_arr4_Inner(val.a));
}

Outer[4] conv_arr4_Outer(Outer_std140 val[4]) {
  Outer arr[4] = Outer[4](Outer(Inner[4](Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u))), Outer(Inner[4](Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u))), Outer(Inner[4](Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u))), Outer(Inner[4](Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u), Inner(mat2(0.0f, 0.0f, 0.0f, 0.0f), 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u))));
  {
    for(uint i = 0u; (i < 4u); i = (i + 1u)) {
      arr[i] = conv_Outer(val[i]);
    }
  }
  return arr;
}

mat2 load_a_inner_p0_a_p1_m(uint p0, uint p1) {
  uint s_save = p0;
  uint s_save_1 = p1;
  return mat2(a.inner[s_save].a[s_save_1].m_0, a.inner[s_save].a[s_save_1].m_1);
}

vec2 load_a_inner_p0_a_p1_m_p2(uint p0, uint p1, uint p2) {
  switch(p2) {
    case 0u: {
      return a.inner[p0].a[p1].m_0;
      break;
    }
    case 1u: {
      return a.inner[p0].a[p1].m_1;
      break;
    }
    default: {
      return vec2(0.0f);
      break;
    }
  }
}

float load_a_inner_p0_a_p1_m_p2_p3(uint p0, uint p1, uint p2, uint p3) {
  switch(p2) {
    case 0u: {
      return a.inner[p0].a[p1].m_0[p3];
      break;
    }
    case 1u: {
      return a.inner[p0].a[p1].m_1[p3];
      break;
    }
    default: {
      return 0.0f;
      break;
    }
  }
}

void f() {
  Outer p_a[4] = conv_arr4_Outer(a.inner);
  int tint_symbol = i();
  Outer p_a_i = conv_Outer(a.inner[tint_symbol]);
  Inner p_a_i_a[4] = conv_arr4_Inner(a.inner[tint_symbol].a);
  int tint_symbol_1 = i();
  Inner p_a_i_a_i = conv_Inner(a.inner[tint_symbol].a[tint_symbol_1]);
  mat2 p_a_i_a_i_m = load_a_inner_p0_a_p1_m(uint(tint_symbol), uint(tint_symbol_1));
  int tint_symbol_2 = i();
  vec2 p_a_i_a_i_m_i = load_a_inner_p0_a_p1_m_p2(uint(tint_symbol), uint(tint_symbol_1), uint(tint_symbol_2));
  Outer l_a[4] = conv_arr4_Outer(a.inner);
  Outer l_a_i = conv_Outer(a.inner[tint_symbol]);
  Inner l_a_i_a[4] = conv_arr4_Inner(a.inner[tint_symbol].a);
  Inner l_a_i_a_i = conv_Inner(a.inner[tint_symbol].a[tint_symbol_1]);
  mat2 l_a_i_a_i_m = load_a_inner_p0_a_p1_m(uint(tint_symbol), uint(tint_symbol_1));
  vec2 l_a_i_a_i_m_i = load_a_inner_p0_a_p1_m_p2(uint(tint_symbol), uint(tint_symbol_1), uint(tint_symbol_2));
  int tint_symbol_3 = i();
  float l_a_i_a_i_m_i_i = load_a_inner_p0_a_p1_m_p2_p3(uint(tint_symbol), uint(tint_symbol_1), uint(tint_symbol_2), uint(tint_symbol_3));
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  f();
  return;
}
