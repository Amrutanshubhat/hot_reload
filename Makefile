raylib = $(HOME)/external/raylib/src

cflags = clang -std=c99 -Wall -g
target = -o out
includes = -I$(raylib)
# linker to search for dynamic linking
rpath = -Wl,-rpath=$(raylib) -Wl,-rpath=./
linkers	= -L$(raylib) $(rpath) -lraylib -lGL -ldl


.PHONY:	clean

all: main.c hot
	$(cflags) $(target) $< $(includes) $(linkers)
	./out

hot: program_logic.c
	$(cflags) -fPIC -shared -o ./libhot.so $< $(includes) $(linkers)

clean:
	rm out ./*.so
