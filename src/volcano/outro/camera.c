#include <common.h>
#include <anim_script.h>

Vec3f volcano_camera_end_eye_path_points[] = {
    { 2193.066162, 971.093750, 2384.148926 },
    { 2146.076416, 861.328125, 1885.366821 },
};

f32 volcano_camera_end_eye_path_timestamps[] = {
    0.000000,
    1.000000,
};

InterpData volcano_camera_end_eye_path = {
    HAL_INTERP_LINEAR,
    2,
    0.5,
    volcano_camera_end_eye_path_points,
    5.128744,
    volcano_camera_end_eye_path_timestamps,
    NULL
};

Vec3f volcano_camera_end_at_path_points[] = {
    { 1629.912720, 527.588867, 1162.906128 },
    { 1795.387207, 836.898621, 1900.753784 },
    { 1960.861816, 1146.208374, 2638.601562 },
    { 2126.336182, 1455.518188, 3376.449219 },
};

f32 volcano_camera_end_at_path_timestamps[] = {
    0.000000,
    1.000000,
};

FittingParams volcano_camera_end_at_path_speed_data[] = {
    { 0.000000, 0.000000, 0.000000, -0.000068, 66.747360 },
};

InterpData volcano_camera_end_at_path = {
    HAL_INTERP_CATROM,
    2,
    0.5,
    volcano_camera_end_at_path_points,
    8.169905,
    volcano_camera_end_at_path_timestamps,
    volcano_camera_end_at_path_speed_data
};

asBegin_ptr2_ns(volcano_camera_anim_end)
    asSetCamPath_f(volcano_camera_end_eye_path, volcano_camera_end_at_path);
asSetAfter_1(0, FOVY, 50.0);
asSetZeroRate_1(0, EYE_PATH_PARAM, 0.0);
asSetBlock_1(0, AT_PATH_PARAM, 0.0);
asSetZeroRate_1(150, EYE_PATH_PARAM, 1.0);
asSetBlock_1(150, AT_PATH_PARAM, 1.0);
asEnd();
