CFLAGs=-Wall -Wextra -ggdb

all: array array.i array.s

array.o: main.cpp
		g++ $(CFLAGS) -Wa,-a=array.lst -c main.cpp

array: main.o
		g++ $(CFLAGS) -Bstatic -Wl,-Map=array.map -o array main.o

array.i: main.cpp
		g++ -E main.cpp >array.i

array.s: main.cpp
		g++ -S main.cpp

# adding verbose for seeing all command line
verbose:
		g++ -v $(CFLAGS) -Wextra -c main.cpp

# cleaning after compilation
clean:
		rm -f array array.i main.s main.o array.map array.lst