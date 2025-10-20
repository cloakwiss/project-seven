
default:
	gcc -shared -o buffer.dll "-Wl,--out-implib,libbuffer.a" -fPIC -O0 -g -fno-inline buffer_lib.c 
	go run .
