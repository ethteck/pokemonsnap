#include "common.h"

extern s32* D_803A6640_879DF0; // prev_bmbuf
extern u16 D_803A6644_879DF4; // sp_attr
extern s32 D_803A6648_879DF8; // scissor_xmin
extern s32 D_803A664C_879DFC; // scissor_ymin
extern s32 D_803A6650_879E00; // scissor_xmax
extern s32 D_803A6654_879E04; // scissor_ymax

void func_80371F30_8456E0(s32 xMin, s32 xMax, s32 yMin, s32 yMax) {
    D_803A6648_879DF8 = xMin;
    D_803A664C_879DFC = yMin;
    D_803A6650_879E00 = xMax;
    D_803A6654_879E04 = yMax;
}

#ifdef NON_MATCHING
static void
func_80371F54_845704 (Gfx **glp, Sprite *s, Bitmap *b,
	    s32 x, s32 y, s32 xx, s32 yy, s32 fs, s32 ft, s32 sx, s32 sy)
{
    s32 rs, rt;
    s32 rxh, ryh;
    s32 rxl, ryl;
    Gfx *gl;
    s32 tex_width, tex_height;
    Gtexrect gt, *g;
    s32 s_clamp, t_clamp,
	s_mask,  t_mask,
	s_lod,   t_lod;

    g = &gt;

    tex_width = b->width_img;
    tex_height= s->bmHreal;

#ifdef rmDEBUG
    rmonPrintf("\tdrawbitmap (buf= 0x%08x; x,y= %d,%d; w,h= %d,%d )\n",
	    b->buf, x, y, b->width, s->bmheight );
#endif
    gl = *glp;

    /* Scissoring */
    if( (x >= D_803A6650_879E00) || (y >= D_803A6654_879E04) ) {
#ifdef DEBUG_SCISSOR
	emPrintf("Sprite Scissoring: Upper Left corner (%d,%d) beyond range (%d,%d)\n",
		x, y, D_803A6650_879E00, D_803A6654_879E04 );
#endif
	return;
    }

    if( (xx < D_803A6648_879DF8) || (yy < D_803A664C_879DFC) ) {
#ifdef DEBUG_SCISSOR
	emPrintf("Sprite Scissoring: Lower Right corner (%d,%d) not in range (%d,%d)\n",
		xx, yy, D_803A6648_879DF8, D_803A664C_879DFC );
#endif
	return;
    }


	if (x < D_803A6648_879DF8) {
	    rxh = D_803A6648_879DF8*4;
	    rs = (b->s<<5) + fs + (((D_803A6648_879DF8 - x)*sx)>>5);
#ifdef DEBUG_SCISSOR
	emPrintf("Sprite Scissoring: Left Edge (%d) not in range (%d,%d)\n",
		x, D_803A6648_879DF8, D_803A6650_879E00 );
#endif
	} else {
	    rxh = x*4;
	    rs = (b->s<<5) + fs;
	};

	if (y < D_803A664C_879DFC) {
	    ryh = D_803A664C_879DFC*4;
	    rt = (b->t<<5) + ft + (((D_803A664C_879DFC-y)*sy)>>5);
#ifdef DEBUG_SCISSOR
	emPrintf("Sprite Scissoring: Top Edge (%d) not in range (%d,%d)\n",
		y, D_803A664C_879DFC, D_803A6654_879E04 );
#endif
	} else {
	    ryh = y*4;
	    rt = (b->t<<5) + ft;
	}

	if( xx >= D_803A6650_879E00 ) {
	    rxl = D_803A6650_879E00*4;
#ifdef DEBUG_SCISSOR
	emPrintf("Sprite Scissoring: Right Edge (%d) not in range (%d,%d)\n",
		xx, scissor_xmin, D_803A6650_879E00 );
#endif
	} else {
	    rxl = xx*4;
	};

	if( yy >= D_803A6654_879E04 ) {
	    ryl = D_803A6654_879E04*4;
#ifdef DEBUG_SCISSOR
	emPrintf("Sprite Scissoring: Bottom Edge (%d) not in range (%d,%d)\n",
		yy, scissor_ymin, D_803A6654_879E04 );
#endif
	} else {
	    ryl = yy*4;
	};

	s_clamp = G_TX_CLAMP;	t_clamp = G_TX_CLAMP;
	s_mask  = G_TX_NOMASK;	t_mask  = G_TX_NOMASK;
	s_lod   = G_TX_NOLOD;	t_lod   = G_TX_NOLOD;

#define LOAD_TEX

#ifdef LOAD_TEX
    if( b->buf != D_803A6640_879DF0 ) {
	switch(s->bmsiz)
	  {
#if BUILD_VERSION >= VERSION_J
	  case G_IM_SIZ_DD:
		gDPLoadTextureTile_4b(gl++, b->buf, s->bmfmt, tex_width, tex_height,
							  b->s, b->t,
							  b->s + b->width,b->t + b->actualHeight,
							  0,
							  s_clamp, t_clamp,
							  s_mask,  t_mask,
							  s_lod,   t_lod);
		break;
#endif
	  case G_IM_SIZ_4b:
		if (s->attr & SP_TEXSHUF) {
		  gDPLoadTextureBlock_4bS(gl++, b->buf, s->bmfmt,
								  tex_width, tex_height, 0,
								  s_clamp, t_clamp,
								  s_mask,  t_mask,
								  s_lod,   t_lod);
		} else {
		  gDPLoadTextureBlock_4b(gl++, b->buf, s->bmfmt,
								 tex_width, tex_height, 0,
								 s_clamp, t_clamp,
								 s_mask,  t_mask,
								 s_lod,   t_lod);
		};
	    break;

	  case G_IM_SIZ_8b:
	    if (s->attr & SP_TEXSHUF) {
		gDPLoadTextureBlockS(gl++, b->buf, s->bmfmt, G_IM_SIZ_8b,
				    tex_width, tex_height, 0,
				       s_clamp, t_clamp,
				       s_mask,  t_mask,
				       s_lod,   t_lod);
	    } else {
		gDPLoadTextureBlock(gl++, b->buf, s->bmfmt, G_IM_SIZ_8b,
				    tex_width, tex_height, 0,
				       s_clamp, t_clamp,
				       s_mask,  t_mask,
				       s_lod,   t_lod);
	    };
	    break;
	  case G_IM_SIZ_16b:
	    if (s->bmfmt == G_IM_FMT_YUV ) {
		if (s->attr & SP_TEXSHUF) {
		    gDPLoadTextureBlockYuvS(gl++, b->buf, s->bmfmt, G_IM_SIZ_16b,
					tex_width, tex_height, 0,
					   s_clamp, t_clamp,
					   s_mask,  t_mask,
					   s_lod,   t_lod);
		} else {
		    if( b->LUToffset != 0 ) { /* Split Y and UV areas */
			unsigned char *uv, *addr;
			int j;
			s32 tmem, siz;

			gDPSetTextureImage( gl++, G_IM_FMT_I, G_IM_SIZ_8b, 1, b->buf);
			gDPSetTile( gl++, G_IM_FMT_I, G_IM_SIZ_8b, 0, 256, G_TX_LOADTILE, 0,
					t_clamp, t_mask, t_lod,
					s_clamp, s_mask, s_lod );
			gDPLoadSync( gl++ );
			gDPLoadBlock( gl++, G_TX_LOADTILE, 0,0, tex_width*tex_height -1,
				      CALC_DXT(tex_width,1) );
			gDPLoadSync( gl++ );

			uv = ((unsigned char *)b->buf) +
				((tex_width*tex_height)/2)*b->LUToffset;

			for( j=0; j<=(tex_height/2); j++ ) {
			    addr = uv + ((tex_height/2) -2 -j)*tex_width;
			    siz = 3*tex_width;
			    tmem = (tex_width/8)*(tex_height - 2 - 2*j);
			    if( tmem < 0 ) {
				addr += (-tmem)*8;
				siz -= (-tmem)*8;
				tmem = 0;
			    };
			    if( j == 0 )
				siz = 2*tex_width;

			    gDPSetTextureImage( gl++, G_IM_FMT_I, G_IM_SIZ_8b, 1, addr);
			    gDPSetTile( gl++, G_IM_FMT_I, G_IM_SIZ_8b, 0, tmem,
					    G_TX_LOADTILE, 0,
					    t_clamp, t_mask, t_lod,
					    s_clamp, s_mask, s_lod );
			    gDPLoadSync( gl++ );
			    gDPLoadBlock( gl++, G_TX_LOADTILE, 0,0, siz -1,
					  CALC_DXT(tex_width,1) );
			    gDPLoadSync( gl++ );
			};

			gDPSetTile( gl++, s->bmfmt, G_IM_SIZ_16b, (((tex_width) * 1)+7)>>3, 0,
				    G_TX_RENDERTILE, 0,
				    t_clamp, t_mask, t_lod,
				    s_clamp, s_mask, s_lod );
			gDPSetTileSize( gl++, G_TX_RENDERTILE, 0, 0,
					((tex_width)-1) << G_TEXTURE_IMAGE_FRAC,
					((tex_height)-1) << G_TEXTURE_IMAGE_FRAC );

		    } else {
			gDPLoadTextureBlockYuv(gl++, b->buf, s->bmfmt, G_IM_SIZ_16b,
					    tex_width, tex_height, 0,
					       s_clamp, t_clamp,
					       s_mask,  t_mask,
					       s_lod,   t_lod);
		    };
		};
	    } else {
		if (s->attr & SP_TEXSHUF) {
		    gDPLoadTextureBlockS(gl++, b->buf, s->bmfmt, G_IM_SIZ_16b,
					tex_width, tex_height, 0,
					   s_clamp, t_clamp,
					   s_mask,  t_mask,
					   s_lod,   t_lod);
		} else {
		    gDPLoadTextureBlock(gl++, b->buf, s->bmfmt, G_IM_SIZ_16b,
					tex_width, tex_height, 0,
					   s_clamp, t_clamp,
					   s_mask,  t_mask,
					   s_lod,   t_lod);
		};
	    };
	    break;
	  case G_IM_SIZ_32b:
	    if (s->attr & SP_TEXSHUF) {
		gDPLoadTextureBlockS(gl++, b->buf, s->bmfmt, G_IM_SIZ_32b,
				    tex_width, tex_height, 0,
				       s_clamp, t_clamp,
				       s_mask,  t_mask,
				       s_lod,   t_lod);
	    } else {
		gDPLoadTextureBlock(gl++, b->buf, s->bmfmt, G_IM_SIZ_32b,
				    tex_width, tex_height, 0,
				       s_clamp, t_clamp,
				       s_mask,  t_mask,
				       s_lod,   t_lod);
	    };
	    break;
       }
       D_803A6640_879DF0 = b->buf;
    }
#endif /* LOAD_TEX */


	g->cmd = G_TEXRECT;
	g->tile = 0;

	g->xh = rxh;
	g->xl = rxl;
	g->yh = ryh;
	g->yl = ryl;

	g->s = rs;
	g->t = rt;

	if ((s->attr & SP_FASTCOPY) && (s->bmfmt != G_IM_FMT_YUV) )
	    g->dsdx = sx * 4;
	else
	    g->dsdx = sx;

	g->dtdy = sy;

#ifdef rmDEBUG
    rmonPrintf("\trect (xh,l= %d,%d, yh,l= %d,%d, s,t= %d,%d, dsdx=%d, dtdy=%d )\n",
	    rxh,rxl,ryh,ryl,rs,rt,g->dsdx,sy );
#endif

    gSPTextureRectangle(gl++,g->xh,g->yh,g->xl,g->yl,g->tile,g->s,g->t,g->dsdx,g->dtdy);

    gDPPipeSync(gl++);

    *glp = gl;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/window/8456E0/func_80371F54_845704.s")
void func_80371F54_845704(Gfx** glp, Sprite* s, Bitmap* b,
                          s32 x, s32 y, s32 xx, s32 yy, s32 fs, s32 ft, s32 sx, s32 sy);
#endif

#define SPRITE_SURF G_RM_TEX_EDGE
#define SPRITE_SURF2 G_RM_TEX_EDGE2

// slightly modified spDraw
Gfx* func_80373670_846E20(Sprite* s) {
    int i;
    s32 x, y;
    float sx, sy;
    Bitmap* b;
    Bitmap* b_end;
    Gfx* gl;
#ifndef NDEBUG
    Gfx* ogl;
#endif
    Gfx* dl_start;
    s32 isx, isy;
    s32 tx, ty;
    s32 tx2, ty2;
    s32 x2, y2;
    float ftx, fty;
    s32 fs, ft;
    s32 ex, ey;
    s32 unused;

#ifdef rmDEBUG
    rmonPrintf("spDraw (Sprite 0x%08x )\n", s);
#endif

    if (s->attr & SP_HIDDEN)
        return (NULL);

    D_803A6640_879DF0 = NULL;

    gl = s->rsp_dl_next;
    if (gl == NULL)
        gl = s->rsp_dl;
    dl_start = gl;

#ifndef NDEBUG
    ogl = gl;
#endif

    b = s->bitmap + s->istart;
    b_end = b + s->nbitmaps;
    ex = 0;
    ey = 0;

    if (D_803A6644_879DF4 & SP_EXTERN) /* previous attr was extern? */
        D_803A6644_879DF4 = ~s->attr;  /* Assume previous modes are all different
                                  from new ones */

    if (s->attr & SP_EXTERN)         /* current attr is extern? */
        D_803A6644_879DF4 = s->attr; /* Assume all settings should remain the same */

    if (s->attr != D_803A6644_879DF4) {
        if ((s->attr & SP_TRANSPARENT) && !(D_803A6644_879DF4 & SP_TRANSPARENT)) {
            gDPSetRenderMode(gl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        } else if (!(s->attr & SP_TRANSPARENT) &&
                   (D_803A6644_879DF4 & SP_TRANSPARENT)) {
            gDPSetRenderMode(gl++,
                             SPRITE_SURF, SPRITE_SURF2);
        }

        if ((s->attr & SP_CUTOUT) && !(D_803A6644_879DF4 & SP_CUTOUT)) {
            gDPSetBlendColor(gl++, 0xff, 0xff, 0xff, 0x01);
            gDPSetAlphaCompare(gl++, G_AC_THRESHOLD);
        } else if (!((s->attr & SP_CUTOUT) && (D_803A6644_879DF4 & SP_CUTOUT))) {
            gDPSetAlphaCompare(gl++, G_AC_NONE);
        }

        if ((s->attr & SP_TEXSHIFT) && !(D_803A6644_879DF4 & SP_TEXSHIFT)) {
            gDPSetTextureFilter(gl++, G_TF_AVERAGE);
        } else if (!(s->attr & SP_TEXSHIFT) && (D_803A6644_879DF4 & SP_TEXSHIFT)) {
            gDPSetTextureFilter(gl++, G_TF_BILERP);
        };
    };

    D_803A6644_879DF4 = s->attr;

    if (D_803A6644_879DF4 & SP_Z) {
        gDPSetPrimDepth(gl++, s->zdepth, 0);
    };

    gDPSetPrimColor(gl++, 0, 0, s->red, s->green, s->blue, s->alpha);

    if (s->bmfmt == G_IM_FMT_IA || s->bmfmt == G_IM_FMT_I) {
        if (s->alpha == 255) {
            gDPSetCombineMode(gl++,
                              G_CC_MODULATEIDECALA_PRIM,
                              G_CC_MODULATEIDECALA_PRIM);
        } else {
            gDPSetCombineMode(gl++,
                              G_CC_MODULATEIA_PRIM,
                              G_CC_MODULATEIA_PRIM);
        };
    } else {
        if (s->alpha == 255) {
            gDPSetCombineMode(gl++,
                              G_CC_MODULATEIDECALA_PRIM,
                              G_CC_MODULATEIDECALA_PRIM);
        } else {
            gDPSetCombineMode(gl++,
                              G_CC_MODULATERGBA_PRIM,
                              G_CC_MODULATERGBA_PRIM);
        };
    }

    if (s->bmfmt == G_IM_FMT_CI) {
        gDPSetTextureLUT(gl++, G_TT_RGBA16);
        gDPLoadTLUT(gl++, s->nTLUT, 256 + s->startTLUT, s->LUT);
        gDPLoadSync(gl++);
    };

#define MY_K0 (175 & 0x1ff)
#define MY_K1 (-43 & 0x1ff)
#define MY_K2 (-89 & 0x1ff)
#define MY_K3 (222 & 0x1ff)
#define MY_K4 (114 & 0x1ff)
#define MY_K5 (42 & 0x1ff)

    if ((s->bmfmt == G_IM_FMT_YUV) && (s->attr & SP_FASTCOPY)) {
        gDPSetTextureConvert(gl++, G_TC_CONV);
        gDPSetTextureFilter(gl++, G_TF_POINT);
        gDPSetCombineMode(gl++, G_CC_1CYUV2RGB, G_CC_1CYUV2RGB);
        gDPSetConvert(gl++, MY_K0, MY_K1, MY_K2, MY_K3, MY_K4, MY_K5);
    } else if (s->bmfmt == G_IM_FMT_YUV) {
        gDPSetCycleType(gl++, G_CYC_2CYCLE);
        gDPSetTextureFilter(gl++, G_TF_BILERP);
        gDPSetTextureConvert(gl++, G_TC_FILTCONV);
        gDPSetConvert(gl++, MY_K0, MY_K1, MY_K2, MY_K3, MY_K4, MY_K5);
        gDPSetCombineMode(gl++, G_CC_YUV2RGB, G_CC_PASS2);
    }

    if (s->attr & SP_SCALE) {
        sx = s->scalex;
        sy = s->scaley;
    } else {
        sx = 1.0F;
        sy = 1.0F;
    }

    isx = (int) ((1 << 10) / sx + 0.5F);
    isy = (int) ((1 << 10) / sy + 0.5F);

    if (b) {

        if ((s->attr & SP_FASTCOPY) && (s->bmfmt != G_IM_FMT_YUV))
            gDPSetCycleType(gl++, G_CYC_COPY);

        x = 0.0F;
        y = 0.0F;

        fty = s->y + y * sy;
        ty = (int) (fty + 0.99999F);
        ft = (int) (isy * (ty - fty));
        ft = (ft + 16) >> 5;
        if (s->attr & SP_TEXSHIFT)
            ft += 16; /* 1/2 Texel for AntiAliasing */

        if (s->attr & SP_FRACPOS)
            ft += s->frac_t; /* Micro-positioning */

        y2 = y + s->bmheight;
        ty2 = (int) (s->y + y2 * sy + 0.99999F);

        if ((s->attr & SP_FASTCOPY) && (s->bmfmt != G_IM_FMT_YUV))
            ty2--;

#ifdef rmDEBUG
        rmonPrintf("\tiscale=(%d,%d), %d bitmaps, sprite_size=(%d,%d)\n",
                   isx, isy, s->nbitmaps, s->width, s->height);
#endif

        for (; (b < b_end) && (b->width > 0); i++, b += s->istep) {

            if ((x + b->width) > s->width) { /* Next bitmap hits edge? */
                int bh;

                x = 0;
                fs = 0;
                ex = 0;
                ey += s->expy;
                y += s->bmheight;     /* Wrap to next line */
                y2 = y + s->bmheight; /* Wrap to next line */

                fty = s->y + y * sy;
                ty = (int) (fty + 0.9999F);
                ft = (int) (isy * (ty - fty));
                ft = (ft + 16) >> 5;
                if (s->attr & SP_TEXSHIFT)
                    ft += 16; /* 1/2 Texel for AntiAliasing */

                if (s->attr & SP_FRACPOS)
                    ft += s->frac_t; /* Micro-positioning */

                ty2 = (int) (s->y + y2 * sy + 0.9999F);

                ty += ey;
                ty2 += ey;

                if ((s->attr & SP_FASTCOPY) && (s->bmfmt != G_IM_FMT_YUV))
                    ty2--;

                /* Fill out to rect. bdy? */

                if ((b->actualHeight != 0))
                    bh = b->actualHeight;
                else
                    bh = s->bmheight;

                if ((y + bh) > s->height) /* Can't wrap any more? */
                    break;
            };

#ifdef rmDEBUG
            rmonPrintf("bm# %d, x,y=(%d,%d) width=%d \n", i, x, y, b->width);
#endif

            ftx = s->x + x * sx;
            tx = (s32) (ftx + 0.9999F);
            fs = (s32) (isx * (tx - ftx));
            fs = (fs + 16) >> 5;
            if (s->attr & SP_TEXSHIFT)
                fs += 16; /* 1/2 Texel for AntiAliasing */

            if (s->attr & SP_FRACPOS)
                fs += s->frac_s; /* Micro-positioning */

            x2 = x + b->width;
            tx2 = (int) (s->x + x2 * sx + 0.9999F);

            if ((b->actualHeight != 0)) {
                y2 = y + b->actualHeight;
                ty2 = (s32) (s->y + y2 * sy + 0.9999F);
                ty2 += ey;

                if ((s->attr & SP_FASTCOPY) && (s->bmfmt != G_IM_FMT_YUV))
                    ty2--;
            };

#ifdef rmDEBUG
            rmonPrintf("\tfull(%g,%g) = int(%d,%d) + frac(%d,%d)\n",
                       ftx, fty, tx, ty, fs, ft);
#endif

            tx += ex;
            tx2 += ex;

            if ((s->attr & SP_FASTCOPY) && (s->bmfmt != G_IM_FMT_YUV))
                tx2--;

            if (b->buf != NULL) /* Skip over null bitmaps (blanks) */
                func_80371F54_845704(&gl, s, b, tx, ty, tx2, ty2, fs, ft, isx, isy);

            x += b->width;
            ex += s->expx;
        }

        if (s->attr & SP_FASTCOPY)
            gDPSetCycleType(gl++, G_CYC_1CYCLE);

        if (s->bmfmt == G_IM_FMT_YUV) {
            gDPSetCycleType(gl++, G_CYC_1CYCLE);
            gDPSetTextureFilter(gl++, G_TF_BILERP);
            gDPSetTextureConvert(gl++, G_TC_FILT);
        };

    } else {
        int rgba;

        x = (s32) s->x;
        y = (s32) s->y;
        x2 = s->x + (s->width * sx) - 1;
        y2 = s->y + (s->height * sy) - 1;

        if ((x >= D_803A6650_879E00) || (y >= D_803A6654_879E04)) {
#ifdef DEBUG_SCISSOR
            emPrintf("Sprite Scissoring: FILL Upper Left corner (%d,%d) beyond range (%d,%d)\n",
                     x, y, D_803A6650_879E00, D_803A6654_879E04);
#endif
        } else if ((x2 < D_803A6648_879DF8) || (y2 < D_803A664C_879DFC)) {
#ifdef DEBUG_SCISSOR
            emPrintf("Sprite Scissoring: FILL Lower Right corner (%d,%d) below range (%d,%d)\n",
                     x2, y2, D_803A6648_879DF8, D_803A664C_879DFC);
#endif
        } else {

            if (x < D_803A6648_879DF8)
                x = D_803A6648_879DF8;

            if (x2 >= D_803A6650_879E00)
                x2 = D_803A6650_879E00 - 1;

            if (y < D_803A664C_879DFC)
                y = D_803A664C_879DFC;

            if (y2 >= D_803A6654_879E04)
                y2 = D_803A6654_879E04 - 1;

            rgba = GPACK_RGBA5551((s->red), (s->green), (s->blue), (s->alpha >> 7));

            gSPTexture(gl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
            gDPSetCycleType(gl++, G_CYC_FILL);
            gDPSetFillColor(gl++, (rgba << 16) | (rgba));

            gDPFillRectangle(gl++, x, y, x2, y2);
            gDPSetCycleType(gl++, G_CYC_1CYCLE);
            gSPTexture(gl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
        }
    }

    if (s->bmfmt == G_IM_FMT_CI) {
        gDPSetTextureLUT(gl++, G_TT_NONE);
    };

    gSPEndDisplayList(gl++);

    s->rsp_dl_next = gl;
    return (dl_start);
}
