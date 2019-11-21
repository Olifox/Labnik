ROOT_DIR=$(shell pwd)/build;

all:clean build

clean :
	rm -rf build/
	rm -rf bin/

build : source/
	echo $(ROOT_DIR)
	mkdir build
	make -C source ROOT_DIR=$(ROOT_DIR)
	mkdir bin
	find source -name "*.o" -exec mv {} build/ \;
	find source -name "main" -exec mv {} bin/ \;