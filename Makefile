test:
	cc ./src/test.c -lteafs -o ./bin/a.out
	@echo Test saved to "./bin/" as "out"

clean:
	rm ./build/*

lib:
	cp -u ./src/teafs.h ./build/
	cc -Wall -c ./src/teafs.c -o ./build/teafs.o
	ar -cvq ./build/libteafs.a ./build/teafs.o
	@echo "libteafs.a" saved to "./build/"

install:
	@echo You need to be root for this.
	mv -u ./build/libteafs.a /usr/local/lib/
	cp -u ./build/teafs.h /usr/local/include/

all:
	make clean; make lib; sudo make install; make test
