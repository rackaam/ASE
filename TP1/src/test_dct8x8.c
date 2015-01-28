#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"dct.h"


short insample[8][8] = {
	{139, 144, 149, 153, 155, 155, 155, 155 },
	{144, 151, 153, 156, 159, 156, 156, 156 },
	{150, 155, 160, 163, 158, 156, 156, 156 },
	{159, 161, 162, 160, 160, 159, 159, 159 },
	{159, 160, 161, 162, 162, 155, 155, 155 },
	{161, 161, 161, 161, 160, 157, 157, 157 },
	{162, 162, 161, 163, 162, 157, 157, 157 },
	{162, 162, 161, 161, 163, 158, 158, 158 }
};

short refsample[8][8] = {
	{1260, -1, -12, -5, 2, -2, -3, 1 },
	{-23, -17, -6, -3, -3, 0, 0, -1 },
	{-11, -9, -2, 2, 0, -1, -1, 0 },
	{-7, -2, 0, 1, 1, 0, 0, 0 },
	{-1, -1, 1, 2, 0, -1, 1, 1 },
	{2, 0, 2, 0, -1, 1, 1, -1 },
	{-1, 0, 0, -1, 0, 2, 1, -1 },
	{-3, 2, -4, -2, 2, 1, -1, 0 }
};

void print_block(short in[8][8]) {
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf("%d    ", in[i][j]);
		}
		printf("\n");
	}
}

void print_labeledblock(char *text, short in[8][8]) {
	int i, j;
	printf("= %s =\n", text);
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf("%04d    ", in[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void slow_float_dct8x8(short pixel[8][8], short data[8][8]);
void fast_float_dct8x8(short pixel[8][8], short data[8][8]);

int main() {
	short fast_float_output[8][8];
	short slow_float_output[8][8];

	slow_float_dct8x8(insample,slow_float_output);
	print_labeledblock("Slow (Direct) dct8x8",slow_float_output);

	fast_float_dct8x8(insample,fast_float_output);
	print_labeledblock("Fast dct8x8",fast_float_output);

	printf("Done ...\n");
	return 0;

}
