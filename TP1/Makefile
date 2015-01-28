
CFLAGS =-Iinclude -pg -O3

MODE = student


all : jpegenc test_dct8x8 test_dct8  src-$(MODE)/dct8x8.s

jpegenc: src-$(MODE)/dct8x8.c src/jpegenc.c src/main.c
	g++ $(CFLAGS) -Isrc-$(MODE) src-$(MODE)/dct8x8.c src/jpegenc.c src/main.c -o jpegenc
	
test_dct8x8: src/test_dct8x8.c src-$(MODE)/dct8x8.c
	g++ $(CFLAGS) -Isrc-$(MODE) src/test_dct8x8.c src-$(MODE)/dct8x8.c -o test_dct8x8

test_dct8: src/test_dct8.c src-$(MODE)/dct8x8.c
	g++ $(CFLAGS) -Isrc-$(MODE) src/test_dct8.c src-$(MODE)/dct8x8.c -o test_dct8

src-$(MODE)/dct8x8.s: src-$(MODE)/dct8x8.c
	g++ $(CFLAGS) -c -S src-$(MODE)/dct8x8.c -o src-$(MODE)/dct8x8.s 
 
clean:
	rm -f jpegenc test_dct src-$(MODE)/dct8x8.s

launch:
	time ./jpegenc ./data/brueghel.bmp ./data/brueghel.jpg

run : clean all launch

rebuild : clean all
	

	
	
