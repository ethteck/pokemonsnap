/**************************************************************************
 *									  *
 *		 Copyright (C) 1994, Silicon Graphics, Inc.		  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/

/**************************************************************************
 *
 * Sprite library include file
 *
 *  $Revision: 1.16 $
 *  $Date: 1998/04/17 05:03:46 $
 *  $Source: /exdisk2/cvs/N64OS/Master/cvsmdev2/PR/include/sp.h,v $
 *
 **************************************************************************/

#ifndef _SP_H_
#define _SP_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/mbi.h>
#include <PR/ultratypes.h>

struct bitmap {
	/* 0x00 */ s16	width;		/* Size across to draw in texels */
				/* Done if width = 0		*/

	/* 0x02 */ s16	width_img;	/* Size across of bitmap in texels */
				/* Done if width = 0		*/

	/* 0x04 */ s16	s;		/* Horizontal offset into bitmap */
				/* if (s > width), then load only! */

	/* 0x06 */ s16	t;		/* Vertical offset into base	*/

	/* 0x08 */ void	*buf;		/* Pointer to bitmap data	*/
				/* Don't re-load if new buf	*/
				/* is the same as the old one   */
				/* Skip if NULL */

	/* 0x0C */ s16	actualHeight;	/* True Height of this bitmap piece */

	/* 0x0E */ s16	LUToffset;	/* LUT base index		*/
}; // size = 0x10

typedef struct bitmap Bitmap;

struct sprite {
	/* 0x00 */ s16	x,y;		/* Target position		*/

	/* 0x04 */ s16	width, height;	/* Target size			*/

	/* 0x08 */ f32	scalex, scaley;	/* Texel to Pixel scale factor	*/

	/* 0x10 */ s16	expx, expy;	/* Explosion spacing		*/

	/* 0x14 */ u16 	attr;		/* Attribute Flags		*/
	/* 0x16 */ s16	zdepth;		/* Z Depth 			*/

	/* 0x18 */ u8	red;		/* Red component		*/
	/* 0x19 */ u8	green;		/* Green component		*/
	/* 0x1A */ u8	blue;		/* Blue component		*/
	/* 0x1B */ u8	alpha;		/* Alpha component		*/

	/* 0x1C */ s16	startTLUT;	/* Lookup Table Entry Starting index */
	/* 0x1E */ s16	nTLUT;		/* Total number of Lookup Table Entries */

	/* 0x20 */ int	*LUT;		/* Pointer to Lookup Table	*/

	/* 0x24 */ s16	istart;		/* Starting bitmap index	*/
	/* 0x26 */ s16	istep;		/* Bitmaps index step (see SP_INCY) */
				/* if 0, then variable width bitmaps */

	/* 0x28 */ s16	nbitmaps;	/* Total number of bitmaps	*/
	/* 0x2A */ s16	ndisplist;	/* Total number of display-list words */

	/* 0x2C */ s16	bmheight;	/* Bitmap Texel height (Used)	*/
	/* 0x2E */ s16	bmHreal;	/* Bitmap Texel height (Real)	*/
	/* 0x30 */ u8	bmfmt;		/* Bitmap Format	 	*/
	/* 0x31 */ u8	bmsiz;		/* Bitmap Texel Size		*/

	/* 0x34 */ Bitmap	*bitmap;	/* Pointer to first bitmap	*/

	/* 0x38 */ Gfx	*rsp_dl;	/* Pointer to RSP display list	*/

	/* 0x3C */ Gfx	*rsp_dl_next;	/* Pointer to next RSP display entry	*/

	/* 0x40 */ s16	frac_s,		/* Fractional Texture offsets */
					frac_t;		/* These have 5 fraction bits */
}; // size = 0x44

typedef struct sprite Sprite;

/*
 * DANGER!
 * This is bad programming. Where the *heck* do these numbers come
 * from?
 *
 * They are obviously 'maximums' from the sprite library, but since
 * the sprite library is built on top of gbi.h, which includes macros
 * that decode into multiple macros, etc., it is nearly impossible to
 * know what these maximums should be.
 *
 * Worse, there are some gbi macros (texture alignment mostly) that
 * decode into *many* macros, so if we choose that as a maximum, we
 * are wasting TONS of space...
 *
 * These numbers work for "reasonable" sprite library usage, and
 * there is an assert() in the library to detect when they aren't
 * enough. (use the debug version)
 */
#define DL_BM_OVERHEAD (12)
#define DL_SPRITE_OVERHEAD (24)

#define NUM_DL(nb)      ((nb)*DL_BM_OVERHEAD +DL_SPRITE_OVERHEAD)

/*
 * Misc constants
 */

#ifndef NULL
#define NULL			0
#endif

#ifndef TRUE
#define TRUE			1
#endif

#ifndef FALSE
#define FALSE			0
#endif

/*
 * For sprite->attr
 */

#define SP_TRANSPARENT		0x00000001
#define SP_CUTOUT		0x00000002
#define SP_HIDDEN		0x00000004
#define SP_Z			0x00000008
#define SP_SCALE		0x00000010
#define SP_FASTCOPY		0x00000020
#define SP_OVERLAP		0x00000040
#define SP_TEXSHIFT		0x00000080
#define SP_FRACPOS		0x00000100
#define SP_TEXSHUF		0x00000200
#define SP_EXTERN		0x00000400

/*
 * Function wrapper
 */
#if	defined(F3DEX_GBI_2)
#define	spMove			spX2Move
#define	spSetZ			spX2SetZ
#define	spScissor		spX2Scissor
#define	spDraw			spX2Draw
#define	spInit			spX2Init
#define	spFinish		spX2Finish
#elif	defined(F3DEX_GBI)
#define	spMove			spXMove
#define	spSetZ			spXSetZ
#define	spScissor		spXScissor
#define	spDraw			spXDraw
#define	spInit			spXInit
#define	spFinish		spXFinish
#endif

/*
 * Function prototypes
 */

void spSetAttribute (Sprite *sp, s32 attr);
void spClearAttribute (Sprite *sp, s32 attr);
void spMove (Sprite *sp, s32 x, s32 y);
void spScale (Sprite *sp, f32 sx, f32 sy);
void spSetZ  (Sprite *sp, s32 z );
void spColor (Sprite *sp, u8 red, u8 green, u8 blue, u8 alpha);
Gfx *spDraw (Sprite *sp);
void spInit( Gfx **glistp );
void spScissor( s32 xmin, s32 xmax, s32 ymin, s32 ymax );
void spFinish( Gfx **glistp );

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* _SP_H_ */
