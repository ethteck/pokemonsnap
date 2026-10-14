/* ROM 25EA6C, VRAM 80192CBC: complete native animation command stream. */
struct Cave_Animation80192CBC D_80192CBC_25EA6C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { -1.0344314575195312f, 0.9794211387634277f, -0.022814413532614708f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80192CBC_25EA6C },
};
