#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dct.h"

//#define TRACE

#define VAL00 (0.5/4.0)
#define VAL0x (0.7071067/4.0)
#define VALx0 (0.7071067/4.0)
#define VALxx (1.0/4.0)

#define C0 (2*(0.7071068))
#define C1 (2*(0.49039))
#define C2 (2*(0.46194))
#define C3 (2*(0.41573))
#define C4 (2*(0.35355))
#define C5 (2*(0.27779))
#define C6 (2*(0.19134))
#define C7 (2*(0.09755))

// Fixed point values
#define C1_FP (int) ((2<<15) * (0.49039))
#define C2_FP (int) ((2<<15) * (0.46194))
#define C3_FP (int) ((2<<15) * (0.41573))
#define C4_FP (int) ((2<<15) * (0.35355))
#define C5_FP (int) ((2<<15) * (0.27779))
#define C6_FP (int) ((2<<15) * (0.19134))
#define C7_FP (int) ((2<<15) * (0.09755))

#define Cu0  0.7071068

float Av[8][8] = {
		{ VAL00, VAL0x, VAL0x, VAL0x, VAL0x, VAL0x, VAL0x, VAL0x},
		{VALx0, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx},
		{VALx0, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx},
		{VALx0, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx},
		{VALx0, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx},
		{VALx0, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx},
		{VALx0, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx},
		{VALx0, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx, VALxx}
};

#define PI 3.1416

void slow_float_dct8x8(short pixel[8][8], short data[8][8]);
void fast_float_dct8x8(short pixel[8][8], short data[8][8]);
void fast_fixed_dct8x8(short pixel[8][8], short data[8][8]);
void slow_float_dct8(float in[8], float out[8]);
void fast_float_dct8(float in[8], float out[8]);
void fast_fixed_dct8(short in[8], short out[8]);


void dct8x8(short pixel[8][8], short data[8][8]) {
 	//slow_float_dct8x8(pixel,data);
	//fast_float_dct8x8(pixel,data);
	fast_fixed_dct8x8(pixel, data);
}

/**
*Réalise une transformé DCT unidimensionnelle sur 8 points.
*Paramètres: pixel , data (pointeurs sur des tableaux de 8 flottants)
*/
void slow_float_dct8x8(short pixel[8][8], short data[8][8])
{
	int i,j,u, v;
	short tmp[8][8];

	for (v = 0; v < 8; v++) {
		for (u = 0; u < 8; u++) {
			double res_b = 0.0;
			for (i = 0; i < 8; i++) {
				for (j = 0; j < 8; j++) {
					res_b = res_b + Av[u][v] * cos(((2 * i + 1) * u * PI) / 16.0)
							* cos(((2 * j + 1) * v * PI) / 16.0)
							* pixel[i][j];
				}
			}
			tmp[u][v]=res_b;
		}
	}

	for (v=0; v<8; v++) {
		for (u=0; u<8; u++) {
			data[u][v] =  tmp[u][v];
		}
	}
}

/*
*Implemente la dct8x8 dans sa version décomposé en lignes colonnes.
*Utilise la fonction slow_fast_dct8
*Paramètres: short pixel[8][8], short data[8][8]
*/
void fast_float_dct8x8(short pixel[8][8], short data[8][8])
{
	int i,j;
	
	float tab[8];
	float out[8];

	// lignes
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			tab[j] = pixel[i][j];
		}
		fast_float_dct8(tab, out);
		for(j = 0; j < 8; j++)
		{
			data[i][j] = out[j];
		}
	}

	// colonnes
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			tab[j] = data[j][i];
		}
		fast_float_dct8(tab, out);
		for(j = 0; j < 8; j++)
		{
			data[i][j] = out[j];
		}
	}
}

/*
*Implemente la dct8x8 dans sa version décomposé en lignes colonnes.
*Utilise la fonction slow_fast_dct8
*Paramètres: short pixel[8][8], short data[8][8]
*/
void fast_fixed_dct8x8(short pixel[8][8], short data[8][8])
{
	int i,j;

	short tab[8];
	short out[8];

	// lignes
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			tab[j] = pixel[i][j];
		}
		fast_fixed_dct8(tab, out);
		for(j = 0; j < 8; j++)
		{
			data[i][j] = out[j];
		}
	}

	// colonnes
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			tab[j] = data[j][i];
		}
		fast_fixed_dct8(tab, out);
		for(j = 0; j < 8; j++)
		{
			data[i][j] = out[j];
		}
	}
}

/**
*Réalise une transformé DCT unidimensionnelle sur 8 points.
*Paramètres: in , out (pointeurs sur des tableaux de 8 flottants)
*/
void slow_float_dct8(float in[8], float out[8]) 
{
	int u, i;

	for(u = 0; u < 8; u++)
	{
		float f = 0;
		float C = u == 0 ? Cu0 : 1.0;
		for(i = 0; i < 8; i++)
		{
			f += C * in[i] * cos(((2*i + 1) * u * PI)/16.0);
		}
		out[u] = f/2;
	}
}

/*
*Réalise une transformé DCT unidimensionelle sur 8 points
*selon l'alogorithme de Chen.
*Paramètres: float in[8], float out[8]
*/
void fast_float_dct8(float in[8], float out[8]) {
	int k,n,i;
	float tmp[8];
	float tmp2[8];

#ifdef TRACE
	printf("\n==== Input ====\n");
	for (i=0;i<8;i++) {
		printf("input[%d] = %f\n",i,in[i]);
	}
#endif

// Etage 1
tmp[0] = in[0] + in[7];
tmp[1] = in[1] + in[6];
tmp[2] = in[2] + in[5];
tmp[3] = in[3] + in[4];

tmp[4] = in[3] - in[4];
tmp[5] = in[2] - in[5];
tmp[6] = in[1] - in[6];
tmp[7] = in[0] - in[7];

#ifdef TRACE
	printf("\n==== Stage 1 ====\n");
	for (i=0;i<8;i++) {
		printf("stage1[%d] = %f\n",i,tmp[i]);
	}
#endif

// Etage 2
tmp2[0] = tmp[0] + tmp[3];
tmp2[1] = tmp[1] + tmp[2];
tmp2[2] = tmp[1] - tmp[2];
tmp2[3] = tmp[0] - tmp[3];
tmp2[4] = tmp[4];
tmp2[5] = -C4 * tmp[5] + C4 * tmp[6];
tmp2[6] = C4 * tmp[5] + C4 * tmp[6];
tmp2[7] = tmp[7];
#ifdef TRACE
	printf("\n==== Stage 2 ====\n");
	for (i=0;i<8;i++) {
		printf("stage2[%d] = %f\n",i,tmp2[i]);
	}
#endif

// Etage 3
tmp[0] = C4 * tmp2[0] + C4 * tmp2[1];
tmp[1] = C4 * tmp2[0] - C4 * tmp2[1];
tmp[2] = C6 * tmp2[2] + C2 * tmp2[3];
tmp[3] = (- C2 * tmp2[2]) + C6 * tmp2[3];

tmp[4] = tmp2[4] + tmp2[5];
tmp[5] = tmp2[4] - tmp2[5];
tmp[6] = -(tmp2[6] - tmp2[7]);
tmp[7] = tmp2[6] + tmp2[7];
#ifdef TRACE
	printf("\n==== Stage 3 ====\n");
	for (i=0;i<8;i++) {
		printf("stage3[%d] = %f\n",i,tmp[i]);
	}
#endif

// Etage 4
out[0] = tmp[0] / 2.0;
out[4] = tmp[1] / 2.0;    
out[2] = tmp[2] / 2.0;
out[6] = tmp[3] / 2.0;   

out[1] = (C7 * tmp[4] + C1 * tmp[7]) / 2.0;
out[5] = (C3 * tmp[5] + C5 * tmp[6]) / 2.0;
out[3] = ((-C5 * tmp[5]) + C3 * tmp[6]) / 2.0;
out[7] = ((-C1 * tmp[4]) + C7 * tmp[7]) / 2.0;
#ifdef TRACE
	printf("\n==== Output ====\n");
	for (i=0;i<8;i++) {
		printf("output[%d] = %f\n",i,out[i]);
	}
#endif
}

/*
*Réalise une transformé DCT unidimensionelle sur 8 points
*selon l'alogorithme de Chen. (Version en arithmétique virgule fixe)
*Format de codage pour entrée et sortie Q15,0
*Paramètres: float in[8], float out[8]
*/
void fast_fixed_dct8(short in[8], short out[8])
{
	int tmp[8];
	int tmp2[8];
    
	tmp[0] = in[0] << 15;
	tmp[1] = in[1] << 15;
	tmp[2] = in[2] << 15;
	tmp[3] = in[3] << 15;
	tmp[4] = in[4] << 15;
	tmp[5] = in[5] << 15;
	tmp[6] = in[6] << 15;
	tmp[7] = in[7] << 15;

	// Etage 1
	tmp2[0] = tmp[0] + tmp[7];
	tmp2[1] = tmp[1] + tmp[6];
	tmp2[2] = tmp[2] + tmp[5];
	tmp2[3] = tmp[3] + tmp[4];
	tmp2[4] = tmp[3] - tmp[4];
	tmp2[5] = tmp[2] - tmp[5];
	tmp2[6] = tmp[1] - tmp[6];
	tmp2[7] = tmp[0] - tmp[7];

	// Etage 2
	tmp[0] = tmp2[0] + tmp2[3];
	tmp[1] = tmp2[1] + tmp2[2];
	tmp[2] = tmp2[1] - tmp2[2];
	tmp[3] = tmp2[0] - tmp2[3];
	tmp[4] = tmp2[4];
	tmp[5] = -C4_FP * (tmp2[5] >> 15) + C4_FP * (tmp2[6] >> 15);
	tmp[6] = C4_FP * (tmp2[5] >> 15) + C4_FP * (tmp2[6] >> 15);
	tmp[7] = tmp2[7];

	// Etage 3
	tmp2[0] = C4_FP * (tmp[0] >> 15) + C4_FP * (tmp[1] >> 15);
	tmp2[1] = C4_FP * (tmp[0] >> 15) - C4_FP * (tmp[1] >> 15);
	tmp2[2] = C6_FP * (tmp[2] >> 15) + C2_FP * (tmp[3] >> 15);
	tmp2[3] = (- C2_FP * (tmp[2] >> 15)) + C6_FP * (tmp[3] >> 15);
	tmp2[4] = tmp[4] + tmp[5];
	tmp2[5] = tmp[4] - tmp[5];
	tmp2[6] = -(tmp[6] - tmp[7]);
	tmp2[7] = tmp[6] + tmp[7];

	// Etage 4 + division par 2
	out[0] = tmp2[0] >> 16;
	out[4] = tmp2[1] >> 16;    
	out[2] = tmp2[2] >> 16;
	out[6] = tmp2[3] >> 16;   
	out[1] = (C7_FP * (tmp2[4] >> 6) + C1_FP * (tmp2[7] >> 6)) >> 25;
	out[5] = (C3_FP * (tmp2[5] >> 6) + C5_FP * (tmp2[6] >> 6)) >> 25;
	out[3] = ((-C5_FP * (tmp2[5] >> 6)) + C3_FP * (tmp2[6] >> 6)) >> 25;
	out[7] = ((-C1_FP * (tmp2[4] >> 6)) + C7_FP * (tmp2[7] >> 6)) >> 25;
} 
