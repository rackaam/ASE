#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <common.h>
#include <vex_simd.h> // only with vex


/* Main computational kernel. The whole function will be timed,
 including the call and return. */
/* Original code provided by Gael Deest */

extern unsigned char in[MAX_WIDTH][MAX_HEIGHT];
extern unsigned char out[MAX_WIDTH][MAX_HEIGHT];

float y1[MAX_WIDTH][MAX_HEIGHT];
float y2[MAX_WIDTH][MAX_HEIGHT];
float t[MAX_WIDTH][MAX_HEIGHT];

int qy1[MAX_WIDTH][MAX_HEIGHT];
int qy2[MAX_WIDTH][MAX_HEIGHT];
int qt[MAX_WIDTH][MAX_HEIGHT];

int ay1[MAX_HEIGHT];
int ay2[MAX_HEIGHT];
int at[MAX_WIDTH][MAX_HEIGHT];

short s_ay1[MAX_HEIGHT];
short s_ay2[MAX_HEIGHT];
short s_by1[MAX_WIDTH];
short s_by2[MAX_WIDTH];
short s_at[MAX_WIDTH][MAX_HEIGHT];


void deriche_float(int width, int height) {
	int i, j;

	float xm1, tm1, ym1, ym2;
	float xp1, xp2;
	float tp1, tp2;
	float yp1, yp2;
	float k;
	float a1, a2, a3, a4, a5, a6, a7, a8;
	float b1, b2, c1, c2;

	k = a1 = a5 = ( (-0.188682));
	a2 = a6 = ( (0.110209));
	a3 = a7 = ( (-0.183682));
	a4 = a8 = ( (0.114441));
	b1 = ( (0.840896));
	b2 = ( (-0.606531));
	c1 = c2 = (int) (1);

L1:
	for (i = 0; i < width; i++) {
		ym1 = 0, ym2 = 0, xm1 = 0;
		for (j = 0; j < height; j++) {
			y1[i][j] = (a1 * in[i][j] + a2 * xm1 + b1 * ym1 + b2 * ym2) ;
			xm1 = in[i][j];
			ym2 = ym1;
			ym1 = y1[i][j];
		}
	}

L2:
	for (i = 0; i < width; i++) {
		yp1 = 0, yp2 = 0, xp1 = 0, xp2 = 0;
		for (j = height - 1; j >= 0; j--) {
			y2[i][j] = (a3 * xp1 + a1 * xp2 + b1 * yp1 + b2 * yp2) ;
			xp2 = xp1;
			xp1 = in[i][j];
			yp2 = yp1;
			yp1 = y2[i][j];
		}
	}
	
L3:
	for (i = 0; i < width; i++)
		for (j = 0; j < height; j++)
			t[i][j] = (c1 * (y1[i][j] + y2[i][j])) ;
		
L4:
	for (j = 0; j < height; j++) {
		tm1 = 0, ym1 = 0, ym2 = 0;
		for (i = 0; i < width; i++) {
			y1[i][j] = (a5 * t[i][j] + a6 * tm1 + b1 * ym1 + b2 * ym2) ;
			tm1 = t[i][j];
			ym2 = ym1;
			ym1 = y1[i][j];
		}
	}
	
L5:
	for (j = 0; j < height; j++) {
		tp1 = 0, tp2 = 0, yp1 = 0, yp2 = 0;
		for (i = width - 1; i >= 0; i--) {
			y2[i][j] = (a7 * tp1 + a8 * tp2 + b1 * yp1 + b2 * yp2) ;
			tp2 = tp1;
			tp1 = t[i][j];
			yp2 = yp1;
			yp1 = y2[i][j];
		}
	}
	
L6:
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			out[i][j] = (c2 * (y1[i][j] + y2[i][j])) ;
			if (out[i][j] > 25) {
				out[i][j] = 0;
			} else {
				out[i][j] = 255;
			}
		}
	}
}


void deriche_slow(int width, int height) {
	int i, j;

	int xm1, tm1, ym1, ym2;
	int xp1, xp2;
	int tp1, tp2;
	int yp1, yp2;
	int k;
	int a1, a2, a3, a4, a5, a6, a7, a8;
	int b1, b2, c1, c2;

	k = a1 = a5 = (int) (256 * (-0.188682));
	a2 = a6 = (int) (256 * (0.110209));
	a3 = a7 = (int) (256 * (-0.183682));
	a4 = a8 = (int) (256 * (0.114441));
	b1 = (int) (256 * (0.840896));
	b2 = (int) (256 * (-0.606531));
	c1 = c2 = (int) (256);

	for (i = 0; i < width; i++) {
		ym1 = 0, ym2 = 0, xm1 = 0;
		for (j = 0; j < height; j++) {
			// les 4 en Q23,8
			int a1Xin = a1 * in[i][j];
			int a2Xxm1 = a2 * xm1;
			int b1Xym1 = (b1 * ym1) >> 8;
			int b2Xym2 = (b2 * ym2) >> 8;
			qy1[i][j] = a1Xin + a2Xxm1 + b1Xym1 + b2Xym2;	
			xm1 = in[i][j];
			ym2 = ym1;
			ym1 = qy1[i][j];
		}
	}
	for (i = 0; i < width; i++) {
		yp1 = 0, yp2 = 0, xp1 = 0, xp2 = 0;
		for (j = height - 1; j >= 0; j--) {
			int a3Xxp1 = a3 * xp1;
			int a1Xxp2 = a1 * xp2;
			int b1Xyp1 = (b1 * yp1) >> 8;
			int b2Xyp2 = (b2 * yp2) >> 8;
			qy2[i][j] = a3Xxp1 + a1Xxp2 + b1Xyp1 + b2Xyp2;
			xp2 = xp1;
			xp1 = in[i][j];
			yp2 = yp1;
			yp1 = qy2[i][j];
		}
	}
	for (i = 0; i < width; i++)
		for (j = 0; j < height; j++)
			qt[i][j] = (c1 * (qy1[i][j] + qy2[i][j])) >> 8;
			
	for (j = 0; j < height; j++) {
		tm1 = 0, ym1 = 0, ym2 = 0;
		for (i = 0; i < width; i++) {
			qy1[i][j] = (a5 * qt[i][j] + a6 * tm1 + b1 * ym1 + b2 * ym2) >> 8;
			tm1 = qt[i][j];
			ym2 = ym1;
			ym1 = qy1[i][j];
		}
	}
	for (j = 0; j < height; j++) {
		tp1 = 0, tp2 = 0, yp1 = 0, yp2 = 0;
		for (i = width - 1; i >= 0; i--) {
			qy2[i][j] = (a7 * tp1 + a8 * tp2 + b1 * yp1 + b2 * yp2) >> 8 ;
			tp2 = tp1;
			tp1 = qt[i][j];
			yp2 = yp1;
			yp1 = qy2[i][j];
		}
	}
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			out[i][j] = (c2 * (qy1[i][j] + qy2[i][j])) >> 16;
			if (out[i][j] > 25) {
				out[i][j] = 0;
			} else {
				out[i][j] = 255;
			}
		}
	}
}


void deriche_fused(int width, int height) {
	int i, j;

	int xm1, tm1, ym1, ym2;
	int xp1, xp2;
	int tp1, tp2;
	int yp1, yp2;
	int k;
	int a1, a2, a3, a4, a5, a6, a7, a8;
	int b1, b2, c1, c2;
	int a3Xxp1, a1Xxp2, b1Xyp1, b2Xyp2;

	k = a1 = a5 = (int) (256 * (-0.188682));
	a2 = a6 = (int) (256 * (0.110209));
	a3 = a7 = (int) (256 * (-0.183682));
	a4 = a8 = (int) (256 * (0.114441));
	b1 = (int) (256 * (0.840896));
	b2 = (int) (256 * (-0.606531));
	c1 = c2 = (int) (256);

	for (i = 0; i < width; i++) {
		ym1 = 0, ym2 = 0, xm1 = 0, yp1 = 0, yp2 = 0, xp1 = 0, xp2 = 0;
		for (j = height - 1; j >= 0; j--) {
			a3Xxp1 = a3 * xp1;
			a1Xxp2 = a1 * xp2;
			b1Xyp1 = (b1 * yp1) >> 8;
			b2Xyp2 = (b2 * yp2) >> 8;
			qy2[i][j] = a3Xxp1 + a1Xxp2 + b1Xyp1 + b2Xyp2;
			xp2 = xp1;
			xp1 = in[i][j];
			yp2 = yp1;
			yp1 = qy2[i][j];
		}
		for (j = 0; j < height; j++) {
			// les 4 en Q23,8
			int a1Xin = a1 * in[i][j];
			int a2Xxm1 = a2 * xm1;
			int b1Xym1 = (b1 * ym1) >> 8;
			int b2Xym2 = (b2 * ym2) >> 8;
			qy1[i][j] = a1Xin + a2Xxm1 + b1Xym1 + b2Xym2;
			xm1 = in[i][j];
			ym2 = ym1;
			ym1 = qy1[i][j];
			qt[i][j] = (c1 * (qy1[i][j] + qy2[i][j])) >> 8;
		}
	}
	
	for (j = 0; j < height; j++) {
		tm1 = 0, ym1 = 0, ym2 = 0, tp1 = 0, tp2 = 0, yp1 = 0, yp2 = 0;
		for (i = width - 1; i >= 0; i--) {
			qy2[i][j] = (a7 * tp1 + a8 * tp2 + b1 * yp1 + b2 * yp2) >> 8 ;
			tp2 = tp1;
			tp1 = qt[i][j];
			yp2 = yp1;
			yp1 = qy2[i][j];
		}
		for (i = 0; i < width; i++) {
			qy1[i][j] = (a5 * qt[i][j] + a6 * tm1 + b1 * ym1 + b2 * ym2) >> 8;
			tm1 = qt[i][j];
			ym2 = ym1;
			ym1 = qy1[i][j];
			out[i][j] = (c2 * (qy1[i][j] + qy2[i][j])) >> 16;
			if (out[i][j] > 25) {
				out[i][j] = 0;
			} else {
				out[i][j] = 255;
			}
		}
	}
}


void deriche_array(int width, int height) {
	int i, j;

	int xm1, tm1, ym1, ym2;
	int xp1, xp2;
	int tp1, tp2;
	int yp1, yp2;
	int k;
	int a1, a2, a3, a4, a5, a6, a7, a8;
	int b1, b2, c1, c2;
	int a3Xxp1, a1Xxp2, b1Xyp1, b2Xyp2;

	k = a1 = a5 = (int) (256 * (-0.188682));
	a2 = a6 = (int) (256 * (0.110209));
	a3 = a7 = (int) (256 * (-0.183682));
	a4 = a8 = (int) (256 * (0.114441));
	b1 = (int) (256 * (0.840896));
	b2 = (int) (256 * (-0.606531));
	c1 = c2 = (int) (256);

	for (i = 0; i < width; i++) {
		ym1 = 0, ym2 = 0, xm1 = 0, yp1 = 0, yp2 = 0, xp1 = 0, xp2 = 0;
		for (j = height - 1; j >= 0; j--) {
			a3Xxp1 = a3 * xp1;
			a1Xxp2 = a1 * xp2;
			b1Xyp1 = (b1 * yp1) >> 8;
			b2Xyp2 = (b2 * yp2) >> 8;
			ay2[j] = a3Xxp1 + a1Xxp2 + b1Xyp1 + b2Xyp2;
			xp2 = xp1;
			xp1 = in[i][j];
			yp2 = yp1;
			yp1 = ay2[j];
		}
		for (j = 0; j < height; j++) {
			// les 4 en Q23,8
			int a1Xin = a1 * in[i][j];
			int a2Xxm1 = a2 * xm1;
			int b1Xym1 = (b1 * ym1) >> 8;
			int b2Xym2 = (b2 * ym2) >> 8;
			ay1[j] = a1Xin + a2Xxm1 + b1Xym1 + b2Xym2;
			xm1 = in[i][j];
			ym2 = ym1;
			ym1 = ay1[j];
			at[i][j] = (c1 * (ay1[j] + ay2[j])) >> 8;
		}
	}
	
	for (j = 0; j < height; j++) {
		tm1 = 0, ym1 = 0, ym2 = 0, tp1 = 0, tp2 = 0, yp1 = 0, yp2 = 0;
		for (i = width - 1; i >= 0; i--) {
			ay2[i] = (a7 * tp1 + a8 * tp2 + b1 * yp1 + b2 * yp2) >> 8 ;
			tp2 = tp1;
			tp1 = at[i][j];
			yp2 = yp1;
			yp1 = ay2[i];
		}
		for (i = 0; i < width; i++) {
			ay1[i] = (a5 * at[i][j] + a6 * tm1 + b1 * ym1 + b2 * ym2) >> 8;
			tm1 = at[i][j];
			ym2 = ym1;
			ym1 = ay1[i];
			out[i][j] = (c2 * (ay1[i] + ay2[i])) >> 16;
			if (out[i][j] > 25) {
				out[i][j] = 0;
			} else {
				out[i][j] = 255;
			}
		}
	}
}


void deriche_short(int width, int height) {
	int i, j;
	
	short xm1, tm1, ym1, ym2;
	short xp1, xp2;
	short tp1, tp2;
	short yp1, yp2;
	short k;
	short a1, a2, a3, a4, a5, a6, a7, a8;
	short b1, b2, c1, c2;
	short a3Xxp1, a1Xxp2, b1Xyp1, b2Xyp2;

	k = a1 = a5 = (short) (128 * (-0.188682));
	a2 = a6 = (short) (128 * (0.110209));
	a3 = a7 = (short) (128 * (-0.183682));
	a4 = a8 = (short) (128 * (0.114441));
	b1 = (short) (128 * (0.840896));
	b2 = (short) (128 * (-0.606531));
	c1 = c2 = (short) (128);

	for (i = 0; i < width; i++) {
		ym1 = 0, ym2 = 0, xm1 = 0, yp1 = 0, yp2 = 0, xp1 = 0, xp2 = 0;
		for (j = height - 1; j >= 0; j--) {
			a3Xxp1 = a3 * xp1;
			a1Xxp2 = a1 * xp2;
			b1Xyp1 = (b1 * yp1) >> 7;
			b2Xyp2 = (b2 * yp2) >> 7;
			s_ay2[j] = a3Xxp1 + a1Xxp2 + b1Xyp1 + b2Xyp2;
			xp2 = xp1;
			xp1 = in[i][j];
			yp2 = yp1;
			yp1 = s_ay2[j];
		}
		for (j = 0; j < height; j++) {
			short a1Xin = a1 * in[i][j];
			short a2Xxm1 = a2 * xm1;
			short b1Xym1 = (b1 * ym1) >> 7;
			short b2Xym2 = (b2 * ym2) >> 7;
			s_ay1[j] = a1Xin + a2Xxm1 + b1Xym1 + b2Xym2;
			xm1 = in[i][j];
			ym2 = ym1;
			ym1 = s_ay1[j];
			s_at[i][j] = (c1 * (s_ay1[j] + s_ay2[j])) >> 7;
		}
	}
	
	for (j = 0; j < height; j++) {
		tm1 = 0, ym1 = 0, ym2 = 0, tp1 = 0, tp2 = 0, yp1 = 0, yp2 = 0;
		for (i = width - 1; i >= 0; i--) {
			s_by2[i] = (a7 * tp1 + a8 * tp2 + b1 * yp1 + b2 * yp2) >> 7 ;
			tp2 = tp1;
			tp1 = s_at[i][j];
			yp2 = yp1;
			yp1 = s_by2[i];
		}
		for (i = 0; i < width; i++) {
			s_by1[i] = (a5 * s_at[i][j] + a6 * tm1 + b1 * ym1 + b2 * ym2) >> 7;
			tm1 = s_at[i][j];
			ym2 = ym1;
			ym1 = s_by1[i];
			out[i][j] = (c2 * (s_by1[i] + s_by2[i])) >> 14;
			if (out[i][j] > 25) {
				out[i][j] = 0;
			} else {
				out[i][j] = 255;
			}
		}
	}
}


void deriche_simd(int width, int height) {
	int i, j;
	
	short xm1, tm1, ym1, ym2;
	short xp1, xp2;
	short tp1, tp2;
	short yp1, yp2;
	short k;
	short a1, a2, a3, a4, a5, a6, a7, a8;
	short b1, b2, c1, c2;
	short a3Xxp1, a1Xxp2, b1Xyp1, b2Xyp2;
	v2x16 s1,s2, r, a78, b12, a31, a12;
	
	k = a1 = a5 = (short) (128 * (-0.188682));
	a2 = a6 = (short) (128 * (0.110209));
	a3 = a7 = (short) (128 * (-0.183682));
	a4 = a8 = (short) (128 * (0.114441));
	b1 = (short) (128 * (0.840896));
	b2 = (short) (128 * (-0.606531));
	c1 = c2 = (short) (128);
	a31 = PACK_2x16(a3, a1);
	a12 = PACK_2x16(a1, a2);
	a78 = PACK_2x16(a7, a8);
	b12 = PACK_2x16(b1, b2);
	
	for (i = 0; i < width; i++) {
		ym1 = 0, ym2 = 0, xm1 = 0, yp1 = 0, yp2 = 0, xp1 = 0, xp2 = 0;
		for (j = height - 1; j >= 0; j--) {
			s1 = PACK_2x16(xp1, xp2);
			s2 = PACK_2x16(yp1 >> 7, yp2 >> 7);
			r = ADD_2x16(MUL_2x16(a31, s1), MUL_2x16(b12, s2));
			s_ay2[j] = EXT_16(r,1) + EXT_16(r,0);
			xp2 = xp1;
			xp1 = in[i][j];
			yp2 = yp1;
			yp1 = s_ay2[j];
		}
		for (j = 0; j < height; j++) {
			s1 = PACK_2x16(in[i][j], xm1);
			s2 = PACK_2x16(ym1 >> 7, ym2 >> 7);
			r = ADD_2x16(MUL_2x16(a12, s1), MUL_2x16(b12, s2));
			s_ay1[j] = EXT_16(r,1) + EXT_16(r,0);
			xm1 = in[i][j];
			ym2 = ym1;
			ym1 = s_ay1[j];
			s_at[i][j] = (c1 * (s_ay1[j] + s_ay2[j])) >> 7;
		}
	}
	
	for (j = 0; j < height; j++) {
		tm1 = 0, ym1 = 0, ym2 = 0, tp1 = 0, tp2 = 0, yp1 = 0, yp2 = 0;
		for (i = width - 1; i >= 0; i--) {
			s_by2[i] = (a7 * tp1 + a8 * tp2 + b1 * yp1 + b2 * yp2) >> 7 ;
			tp2 = tp1;
			tp1 = s_at[i][j];
			yp2 = yp1;
			yp1 = s_by2[i];
		}
		for (i = 0; i < width; i++) {
			s_by1[i] = (a5 * s_at[i][j] + a6 * tm1 + b1 * ym1 + b2 * ym2) >> 7;
			tm1 = s_at[i][j];
			ym2 = ym1;
			ym1 = s_by1[i];
			out[i][j] = (c2 * (s_by1[i] + s_by2[i])) >> 14;
			if (out[i][j] > 25) {
				out[i][j] = 0;
			} else {
				out[i][j] = 255;
			}
		}
	}
}






