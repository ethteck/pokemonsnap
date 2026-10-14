/* ROM 0xA71DC; native animation_stream. */
struct PokemonCommonAnimationBulbasaur80129DBC D_80129DBC_A71DC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 4.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 80 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80129DBC_A71DC },
};
