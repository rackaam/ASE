CFLAGS = -g -I../include/ -std=c99 -Wall 
CC=gcc
OBJS =  obj/edge_detect.o \
	    obj/pgm.o \
	    obj/deriche.o \
	    obj/alloc.o 

INCS = ../include/common.h
PROG = deriche
SRCDIR = ../src/

float: run 

fixed: run_fixed

fused: run_fused

array: run_array

short: run_short
	
deriche : $(OBJS) $(INCS) 
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) -lm

obj/edge_detect.o : $(SRCDIR)edge_detect.c $(INCS) 
	$(CC) $(CFLAGS) -c -o obj/edge_detect.o $(SRCDIR)edge_detect.c
	
obj/pgm.o : $(SRCDIR)pgm.c $(INCS)
	$(CC) $(CFLAGS) -c -o obj/pgm.o $(SRCDIR)pgm.c

obj/deriche.o : $(SRCDIR)deriche.c $(INCS)
	$(CC) $(CFLAGS) -c -o obj/deriche.o $(SRCDIR)deriche.c
	
obj/alloc.o : $(SRCDIR)alloc.c $(INCS)
	$(CC) $(CFLAGS) -c -o obj/alloc.o $(SRCDIR)alloc.c

run: $(PROG)
	./$(PROG) ../data/satellite.pgm ./deriche-satellite-float.pgm float_slow

run_fixed: $(PROG)
	./$(PROG) ../data/satellite.pgm ./deriche-satellite-fixed.pgm fixed_slow

run_fused: $(PROG)
	./$(PROG) ../data/satellite.pgm ./deriche-satellite-fused.pgm fixed_fast
	
run_array: $(PROG)
	./$(PROG) ../data/satellite.pgm ./deriche-satellite-array.pgm fixed_array

run_short: $(PROG)
	./$(PROG) ../data/satellite.pgm ./deriche-satellite-short.pgm fixed_short

clean:
	rm obj/* $(PROG)
