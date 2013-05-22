/*
 * Copyright (C) 2012 Russell King.
 *
 * Based in part on code from the Intel Xorg driver.
 *
 * Unaccelerated drawing functions for Vivante GPU.  These prepare
 * access to the drawable prior to passing on the call to the Xorg
 * Server's fb layer (or pixman layer.)
 */
#ifndef VIVANTE_UNACCEL_H
#define VIVANTE_UNACCEL_H

void vivante_unaccel_FillSpans(DrawablePtr pDrawable, GCPtr pGC, int nspans,
	DDXPointPtr ppt, int *pwidth, int fSorted);
void vivante_unaccel_SetSpans(DrawablePtr pDrawable, GCPtr pGC, char *psrc,
	DDXPointPtr ppt, int *pwidth, int nspans, int fSorted);
void vivante_unaccel_PutImage(DrawablePtr pDrawable, GCPtr pGC, int depth,
	int x, int y, int w, int h, int leftPad, int format, char *bits);
RegionPtr vivante_unaccel_CopyArea(DrawablePtr pSrc, DrawablePtr pDst,
	GCPtr pGC, int srcx, int srcy, int w, int h, int dstx, int dsty);
RegionPtr vivante_unaccel_CopyPlane(DrawablePtr pSrc, DrawablePtr pDst,
	GCPtr pGC, int srcx, int srcy, int w, int h, int dstx, int dsty,
	unsigned long bitPlane);
void vivante_unaccel_PolyPoint(DrawablePtr pDrawable, GCPtr pGC, int mode,
	int npt, DDXPointPtr pptInit);
void vivante_unaccel_PolyLines(DrawablePtr pDrawable, GCPtr pGC, int mode,
	int npt, DDXPointPtr ppt);
void vivante_unaccel_PolySegment(DrawablePtr pDrawable, GCPtr pGC,
	int nsegInit, xSegment * pSegInit);
void vivante_unaccel_PolyFillRect(DrawablePtr pDrawable, GCPtr pGC, int nrect,
	xRectangle * prect);
void vivante_unaccel_ImageGlyphBlt(DrawablePtr pDrawable, GCPtr pGC,
	int x, int y, unsigned int nglyph, CharInfoPtr * ppci, pointer pglyphBase);
void vivante_unaccel_PolyGlyphBlt(DrawablePtr pDrawable, GCPtr pGC,
	int x, int y, unsigned int nglyph, CharInfoPtr * ppci, pointer pglyphBase);
void vivante_unaccel_PushPixels(GCPtr pGC, PixmapPtr pBitmap,
	DrawablePtr pDrawable, int w, int h, int x, int y);

void vivante_unaccel_GetSpans(DrawablePtr pDrawable, int wMax, DDXPointPtr ppt,
	int *pwidth, int nspans, char *pdstStart);
void vivante_unaccel_GetImage(DrawablePtr pDrawable, int x, int y, int w, int h,
	unsigned int format, unsigned long planeMask, char *d);
Bool vivante_unaccel_ChangeWindowAttributes(WindowPtr pWin, unsigned long mask);
RegionPtr vivante_unaccel_BitmapToRegion(PixmapPtr pixmap);
void vivante_unaccel_CopyNtoN(DrawablePtr pSrc, DrawablePtr pDst, GCPtr pGC,
	BoxPtr pBox, int nBox, int dx, int dy, Bool reverse, Bool upsidedown,
	Pixel bitPlane, void *closure);

void vivante_unaccel_Composite(CARD8 op, PicturePtr pSrc, PicturePtr pMask,
	PicturePtr pDst, INT16 xSrc, INT16 ySrc, INT16 xMask, INT16 yMask,
	INT16 xDst, INT16 yDst, CARD16 w, CARD16 h);
void vivante_unaccel_Glyphs(CARD8 op, PicturePtr pSrc, PicturePtr pDst,
	PictFormatPtr maskFormat, INT16 xSrc, INT16 ySrc, int nlist,
	GlyphListPtr list, GlyphPtr * glyphs);
void vivante_unaccel_Triangles(CARD8 op, PicturePtr pSrc, PicturePtr pDst,
	PictFormatPtr maskFormat, INT16 xSrc, INT16 ySrc, int ntri,
	xTriangle * tris);
void vivante_unaccel_Trapezoids(CARD8 op, PicturePtr src, PicturePtr dst,
	PictFormatPtr maskFormat, INT16 xSrc, INT16 ySrc, int ntrap,
	xTrapezoid * traps);
void vivante_unaccel_AddTriangles(PicturePtr pPicture, INT16 x_off, INT16 y_off,
	int ntri, xTriangle *tris);
void vivante_unaccel_AddTraps(PicturePtr pPicture, INT16 x_off, INT16 y_off,
	int ntrap, xTrap *traps);

#endif
