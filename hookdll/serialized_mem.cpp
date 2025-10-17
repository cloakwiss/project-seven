#ifndef SERIALIZED_MEM_H
#define SERIALIZED_MEM_H


#include "toBytes.cpp"

size_t bufferhead = 0;
uint8_t *bytebuffer = NULL;


void
delimiter(size_t *buffer_head) {
    bytebuffer[*buffer_head] = 0x01E;
    (*buffer_head)++;
}

void
allocate_buffer() {

    bytebuffer =
        (uint8_t *)VirtualAlloc(NULL, BUFFER_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    if (bytebuffer == NULL) {
        printf("VirtualAlloc failed with error %lu\n", GetLastError());
        return;
    }

    printf("allocated \n");
}

void
free_buffer() {
    if (!VirtualFree(bytebuffer, 0, MEM_RELEASE)) {
        printf("VirtualFree failed with error %lu\n", GetLastError());
        return;
    }
    printf("\nfreed \n");
}

// int main(){

//     int a = 10;
//     int * intptr = &a;

//     const char* str = "Hello! from buffer";
//     size_t size = strlen(str) ;

//     allocate_buffer();
//     con_to_byte((void*)str, &bufferhead, bytebuffer, &size);
//     con_to_byteP((void*)&str, &bufferhead, bytebuffer);


//     printf("bufferhead: %d\n", bufferhead);
//     for(size_t i = 0; i < bufferhead; i++){
//         printf("%x ", bytebuffer[i]);
//     }

//     free_buffer();

//     return 0;
// }

#endif
