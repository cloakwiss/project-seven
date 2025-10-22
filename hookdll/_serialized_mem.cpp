#ifndef SERIALIZED_MEM_H
#define SERIALIZED_MEM_H


#include "toBytes.cpp"


#if 0
int main(){

    int a = 10;
    int * intptr = &a;

    const char* str = "Hello! from buffer";
    size_t size = strlen(str) ;

    allocate_buffer();
    con_to_byte((void*)str, &bufferhead, bytebuffer, &size);
    con_to_byteP((void*)&str, &bufferhead, bytebuffer);


    printf("bufferhead: %d\n", bufferhead);
    for(size_t i = 0; i < bufferhead; i++){
        printf("%x ", bytebuffer[i]);
    }

    free_buffer();

    return 0;
}
#endif

#endif
