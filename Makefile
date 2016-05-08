CC=g++
#CC=llvm-g++


PC_OPTIMIZE = -O0
#-pedantic
PC_LANG = -std=c++0x
PC_WARNINGS = -Wall
PC_CFLAGS = $(PC_LANG) $(PC_WARNINGS) $(PC_OPTIMIZE)

CFLAGS = -g -pthread $(PC_LANG) $(PC_WARNINGS) $(PC_OPTIMIZE)


all : RandPool.o seed_test

seed_test :
	$(CC) $(CFLAGS) -l cryptopp RandPool.o -o seed_test seed_test.cpp

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -fv *.o *.gch seed_test
