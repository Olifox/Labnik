ROOT_DIR=$(shell pwd)/build;

all:clean build

clean :
	rm -rf build/
	rm -rf bin/

build : src/
	echo $(ROOT_DIR)
	mkdir build
	make -C src ROOT_DIR=$(ROOT_DIR)
	mkdir bin
	find src -name "*.o" -exec mv {} build/ \;
	find src -name "main" -exec mv {} bin/ \;