#ifndef COMMON_H
#define COMMON_H

#define MAX_WIDTH 1500
#define MAX_HEIGHT 1050
//#define MAX_WIDTH 800
//#define MAX_HEIGHT 600

int load_pgm(char* name, int* width, int* height, unsigned char img[MAX_WIDTH][MAX_HEIGHT]);
int save_pgm(char* name, int width, int height, unsigned char img[MAX_WIDTH][MAX_HEIGHT]);
void** mat_malloc(int width, int height, int size);

#endif
