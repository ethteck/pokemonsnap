#include "types.h"
#include "PR/gbi.h"

void hal_mtx_f2l(Mtx4f src, Mtx* dst);
void hal_mtx_f2l_fixed_w(Mtx4f src, Mtx* dst);
void hal_look_at_f(Mtx4f mf, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);
void hal_look_at(Mtx* m, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);
void hal_look_at_roll(Mtx* m, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 roll, f32 xUp, f32 yUp, f32 zUp);
void hal_look_at_roll_f(Mtx4f mf, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 roll, f32 xUp, f32 yUp,
                       f32 zUp);
void hal_look_at_reflect_f(Mtx4f mf, LookAt* l, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp,
                           f32 yUp, f32 zUp);
void hal_look_at_reflect(Mtx* m, LookAt* l, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp,
                         f32 zUp);
void hal_look_at_reflect_roll_f(Mtx4f mf, LookAt* l, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 roll,
                               f32 xUp, f32 yUp, f32 zUp);
void hal_look_at_reflect_roll(Mtx* m, LookAt* l, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 roll,
                             f32 xUp, f32 yUp, f32 zUp);
void hal_ortho_f(Mtx4f mf, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale);
void hal_ortho(Mtx* m, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale);
void hal_perspective_fast_f(Mtx4f mf, u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
void hal_perspective_fast(Mtx* m, u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
void hal_perspective_f(Mtx4f mf, u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
void hal_perspective(Mtx* m, u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
void hal_scale_f(Mtx4f mf, f32 x, f32 y, f32 z);
void hal_scale(Mtx* m, f32 x, f32 y, f32 z);
void hal_translate_f(Mtx4f mf, f32 x, f32 y, f32 z);
void hal_translate(Mtx* m, f32 x, f32 y, f32 z);
void hal_rotate_f(Mtx4f mf, f32 a, f32 x, f32 y, f32 z);
void hal_rotate(Mtx* m, f32 a, f32 x, f32 y, f32 z);
void hal_rotate_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 angle, f32 rx, f32 ry, f32 rz);
void hal_rotate_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 angle, f32 rx, f32 ry, f32 rz);
void hal_rotate_translate_scale_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 angle, f32 rx, f32 ry, f32 rz, f32 sx,
                                     f32 sy, f32 sz);
void hal_rotate_translate_scale(Mtx* m, f32 dx, f32 dy, f32 dz, f32 angle, f32 rx, f32 ry, f32 rz, f32 sx, f32 sy,
                                   f32 sz);
void hal_rotate_rpy_f(Mtx4f mf, f32 r, f32 p, f32 h);
void hal_rotate_rpy(Mtx* m, f32 r, f32 p, f32 h);
void hal_rotate_rpy_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h);
void hal_rotate_rpy_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h);
void hal_rotate_rpy_translate_scale_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h, f32 sx, f32 sy, f32 sz);
void hal_rotate_rpy_translate_scale(Mtx* m, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h, f32 sx, f32 sy, f32 sz);
void hal_rotate_pyr_f(Mtx4f mf, f32 r, f32 p, f32 h);
void hal_rotate_pyr(Mtx* m, f32 r, f32 p, f32 h);
void hal_rotate_pyr_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h);
void hal_rotate_pyr_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h);
void hal_rotate_pyr_translate_scale_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h, f32 sx, f32 sy, f32 sz);
void hal_rotate_pyr_translate_scale(Mtx* m, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h, f32 sx, f32 sy, f32 sz);
void hal_rotate_py_f(Mtx4f mf, f32 p, f32 h);
void hal_rotate_py(Mtx* m, f32 p, f32 h);
void hal_rotate_py_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 p, f32 h);
void hal_rotate_py_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 p, f32 h);
void hal_rotate_rp_f(Mtx4f mf, f32 r, f32 p);
void hal_rotate_rp(Mtx* m, f32 p, f32 h);
void hal_rotate_rp_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 r, f32 p);
void hal_rotate_rp_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 r, f32 p);
void hal_rotate_yaw_f(Mtx4f mf, f32 h);
void hal_rotate_yaw(Mtx* m, f32 h);
void hal_rotate_yaw_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 h);
void hal_rotate_yaw_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 h);
void hal_rotate_pitch_f(Mtx4f mf, f32 p);
void hal_rotate_pitch(Mtx* m, f32 p);
void hal_rotate_pitch_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 p);
void hal_rotate_pitch_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 p);
void hal_rotate_f_deg(Mtx4f mf, f32 a, f32 x, f32 y, f32 z);
void hal_rotate_deg(Mtx* m, f32 a, f32 x, f32 y, f32 z);
void hal_rotate_translate_f_deg(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 a, f32 rx, f32 ry, f32 rz);
void hal_rotate_translate_deg(Mtx* m, f32 dx, f32 dy, f32 dz, f32 a, f32 rx, f32 ry, f32 rz);
void hal_rotate_rpy_f_deg(Mtx4f mf, f32 r, f32 p, f32 h);
void hal_rotate_rpy_deg(Mtx* m, f32 r, f32 p, f32 h);
void hal_rotate_rpy_translate_f_deg(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h);
void hal_rotate_rpy_translate_deg(Mtx* m, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h);
void func_8001ECD0(Mtx* m, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
