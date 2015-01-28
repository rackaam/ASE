#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dct.h"

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
void float_dct8x8(short pixel[8][8], short data[8][8]);
void slow_float_dct8(float in[8], float out[8]);
void fast_float_dct8(float in[8], float out[8]);


void dct8x8(short pixel[8][8], short data[8][8]) {
	slow_float_dct8x8(pixel,data);
//	fast_float_dct8x8(pixel,data);
}



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

void fast_float_dct8x8(short pixel[8][8], short data[8][8])
{
	int i,j;
	
	float tab[8];
}


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

	// Etage 1 Ã  complÃ©ter

#ifdef TRACE
	printf("\n==== Stage 1 ====\n");
	for (i=0;i<8;i++) {
		printf("stage1[%d] = %f\n",i,tmp[i]);
	}
#endif

	// Etage 2 Ã  complÃ©ter

#ifdef TRACE
	printf("\n==== Stage 2 ====\n");
	for (i=0;i<8;i++) {
		printf("stage2[%d] = %f\n",i,out[i]);
	}
#endif

	// Etage 3 Ã  complÃ©ter

#ifdef TRACE
	printf("\n==== Stage 3 ====\n");
	for (i=0;i<8;i++) {
		printf("stage3[%d] = %f\n",i,tmp[i]);
	}
#endif

	// Etage 4 Ã  complÃ©ter

#ifdef TRACE
	printf("\n==== Output ====\n");
	for (i=0;i<8;i++) {
		printf("output[%d] = %f\n",i,out[i]);
	}
#endif
}

