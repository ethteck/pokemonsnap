/* ROM 26F2AC, VRAM 801A34FC: complete native animation command stream. */
struct Cave_Animation801A34FC D_801A34FC_26F2AC = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 28, { -0.2617993950843811f, -0.004848137032240629f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 26, { -0.2617993950843811f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 6, { -0.2617993950843811f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 30, { -0.2617993950843811f, 0.006233318243175745f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 12, { 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801A34FC_26F2AC },
};
