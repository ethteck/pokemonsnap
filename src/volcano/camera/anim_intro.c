#include <common.h>
#include <anim_script.h>

Vec3f volcano_camera_intro_eye_path_points[] = {
    { -161.230103, 699.551941, 980.259216 },
    { -593.412903, 699.551941, 457.417206 },
    { -253.980545, 443.857849, 493.390076 },
    { 49.900002, 419.100006, 677.500000 },
    { 73.699997, 416.800018, 690.899963 },
};

f32 volcano_camera_intro_eye_path_timestamps[] = {
    0.000000,
    0.455752,
    0.742291,
    0.981584,
    1.000000,
};

InterpData volcano_camera_intro_eye_path = {
    HAL_INTERP_LINEAR,
    5,
    0.5,
    volcano_camera_intro_eye_path_points,
    14.883971,
    volcano_camera_intro_eye_path_timestamps,
    NULL
};

Vec3f volcano_camera_intro_at_path_points[] = {
    { -89.026993, 583.723145, 589.565674 },
    { -86.569946, 451.035309, 595.385559 },
    { -55.339577, 430.026306, 613.968384 },
    { 67.199997, 419.100006, 687.200012 },
    { 91.000000, 416.800018, 700.899963 },
};

f32 volcano_camera_intro_at_path_timestamps[] = {
    0.000000,
    0.384432,
    0.505911,
    0.920249,
    1.000000
};

InterpData volcano_camera_intro_at_path = {
    HAL_INTERP_LINEAR,
    5,
    0.5,
    volcano_camera_intro_at_path_points,
    3.455443,
    volcano_camera_intro_at_path_timestamps,
    NULL
};

asBegin_ptr2_ns(volcano_camera_anim_intro)
    asSetCamPath_f(volcano_camera_intro_eye_path, volcano_camera_intro_at_path);
    asSetBlock_3(0, EYE_PATH_PARAM, 0.0, AT_PATH_PARAM, 0.0, FOVY, 60.0);
    asSet_2(120, EYE_PATH_PARAM, 0.2, FOVY, 60.0);
    asSetBlock_1(60, AT_PATH_PARAM, 0.0);
    asSetTargetRate_1(0, AT_PATH_PARAM, 0.00040094496);
    asSetWithRateBlock_2(60, AT_PATH_PARAM, 0.38, 0.018720841);
    asSetTargetRate_3(0, EYE_PATH_PARAM, 0.010923434, AT_PATH_PARAM, 0.018720834, FOVY, -0.5123);
    asSetAfterBlock_3(1, EYE_PATH_PARAM, 0.78, AT_PATH_PARAM, 0.7, FOVY, 40.0);
    asSetTargetRate_1(0, EYE_PATH_PARAM, 0.01056219);
    asSet_2(29, AT_PATH_PARAM, 1.0, FOVY, 40.0);
    asSetWithRateBlock_2(25, EYE_PATH_PARAM, 0.976, 0.0070981365);
    asSetTargetRate_1(0, EYE_PATH_PARAM, 0.0013474334);
    asSetBlock_1(4, EYE_PATH_PARAM, 1.0);
asEnd();
