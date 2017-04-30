CC=g++ 
CFLAGS=-g -Wall -std=c++11
CPPFLAGS=-I include
LIBS = -lGL -lglut -lSOIL

all: build floppybird

floppybird: build/main.o build/draw.o build/frameupdate.o	
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LIBS)

build/main.o: main.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

build/frameupdate.o: frameupdate.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

build/draw.o: draw.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

build:
	mkdir build

clean:
	rm -rf build/ *~