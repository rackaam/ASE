#include<stdio.h>
#include<math.h>


float insample8[] = {1.0, 13.0, 5.0, 45.0, 24.0, 9.0, 12.0, 24.0};
float refsample8[] = {81.31, -9.85, -29.55, -44.71, 51.61, 6.4, -43.6, -13.0};


void print_vector(char* mess, float* in) {
	int i,j;
	printf("\nVector %s :\n",mess);
	for (i=0;i<8;i++) {
		printf("%f ",in[i]);
	}
	printf("\n");
	fflush(stdout);
}

extern void slow_float_dct8(float in[8],float out[8]);
extern void fast_float_dct8(float in[8],float out[8]);
extern void fast_fixed_dct8(short in[8],short out[8]);

int main() {
	float float_output[8];
	float float_input[8];

	int i=0;


	print_vector("Input",insample8);

	slow_float_dct8(insample8,float_output);
	print_vector("Slow output ",float_output);

	fast_float_dct8(insample8,float_output);
	print_vector("Fast output ",float_output);
	
	// à compléter/modifier
	// fast_fixed_dct8( ..., ...);
	//print_vector("Fast fixed point output ",float_output);

	return 0;
}
