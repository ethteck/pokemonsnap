#ifndef REMAINING_UI_AE0510_DATA_H
#define REMAINING_UI_AE0510_DATA_H

#include "common.h"

/* Same serialized ABI as PhotoData. The union at 0x004 is represented by its
 * capture-time f32 member so C89/IDO can initialize the original finite times
 * directly, rather than storing opaque integer representations of floats.
 * Header bitfields deliberately use the same base types as PhotoData.
 */
typedef struct RemainingUiAe0510Photo {
    /* 0x000 */ s8 levelID : 7;
    /* 0x000 */ u8 photoFlag : 1;
    /* 0x001 */ u32 blockAndSubjectFlags : 8;
    /* 0x002 */ char reserved[2];
    /* 0x004 */ f32 captureTime;
    /* 0x008 */ Vec3f cameraEye;
    /* 0x014 */ Vec3f cameraAt;
    /* 0x020 */ PokemonPhotoData pokemons[12];
    /* 0x140 */ ItemPhotoData items[6];
    /* 0x1A0 */ EffectPhotoData effects[32];
} RemainingUiAe0510Photo;

typedef struct RemainingUiAe0510AlbumPhoto {
    /* 0x000 */ RemainingUiAe0510Photo photo;
    /* 0x3A0 */ AlbumComment comment;
} RemainingUiAe0510AlbumPhoto;

/* The final two arrays of the save file, without its preceding save header/report
 * data or trailing four bytes. This complete ROM-resident example-photo bank
 * is retained even though no direct ROM-loading caller is named in the code.
 */
typedef struct RemainingUiAe0510PhotoBank {
    /* 0x0000 */ RemainingUiAe0510Photo reportPhotos[4];
    /* 0x0E80 */ RemainingUiAe0510AlbumPhoto albumPhotos[60];
} RemainingUiAe0510PhotoBank;

typedef char remaining_ui_ae0510_assert_time[(offsetof(RemainingUiAe0510Photo, captureTime) == offsetof(PhotoData, unk_04)) ? 1 : -1];
typedef char remaining_ui_ae0510_assert_eye[(offsetof(RemainingUiAe0510Photo, cameraEye) == offsetof(PhotoData, unk_08)) ? 1 : -1];
typedef char remaining_ui_ae0510_assert_at[(offsetof(RemainingUiAe0510Photo, cameraAt) == offsetof(PhotoData, unk_14)) ? 1 : -1];
typedef char remaining_ui_ae0510_assert_pokemons[(offsetof(RemainingUiAe0510Photo, pokemons) == offsetof(PhotoData, pokemons)) ? 1 : -1];
typedef char remaining_ui_ae0510_assert_items[(offsetof(RemainingUiAe0510Photo, items) == offsetof(PhotoData, items)) ? 1 : -1];
typedef char remaining_ui_ae0510_assert_effects[(offsetof(RemainingUiAe0510Photo, effects) == offsetof(PhotoData, effects)) ? 1 : -1];
typedef char remaining_ui_ae0510_assert_photo_size[(sizeof(RemainingUiAe0510Photo) == sizeof(PhotoData)) ? 1 : -1];
typedef char remaining_ui_ae0510_assert_comment[(offsetof(RemainingUiAe0510AlbumPhoto, comment) == offsetof(AlbumPhotoData, comment)) ? 1 : -1];
typedef char remaining_ui_ae0510_assert_album_size[(sizeof(RemainingUiAe0510AlbumPhoto) == sizeof(AlbumPhotoData)) ? 1 : -1];
typedef char remaining_ui_ae0510_assert_album_offset[(offsetof(RemainingUiAe0510PhotoBank, albumPhotos) == 0xE80) ? 1 : -1];
typedef char remaining_ui_ae0510_assert_bank_size[(sizeof(RemainingUiAe0510PhotoBank) == 0xF700) ? 1 : -1];

extern RemainingUiAe0510PhotoBank remaining_ui_ae0510_photo_bank;

#endif
