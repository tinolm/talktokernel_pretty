compiling:
	rm -rf bin binary
	mkdir bin
	gcc -O3 -static src/*.c -o bin/binary
clean:
	rm -rf bin binary
fancy:
	rm -rf bin binary
	mkdir bin
	gcc -O3 -static src/*.c -o bin/binary
	ln -s bin/binary binary
