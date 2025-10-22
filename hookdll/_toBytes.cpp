#include <windows.h>


#if 0
int main() {
    uint8_t buffer[8000];
    size_t buffer_head = 0;
    // int 
    int a = 42;
    // char ptr
    const char* ptr = "hello!, World";
    // int ptr 
    int *ptr2 = &a;
    //unsigned char
    const uint8_t *uchar= (uint8_t*)"hello!";
    //long
    long b = 4200;
    //long ptr
    const long* longptr = &b; 
    //float
    float f = 4200.0;
    //float ptr
    float *floatptr = &f;
    //short
    short s = 10;
    //short ptr
    short* sptr = &s;
    //__int64
    __int64 hi = 9;
    //__int64 ptr
    __int64 * hiptr = &hi;

    size_t size = sizeof(__int64);
    con_to_byte((void*)&hi, &buffer_head, buffer, &size);
    buffer[(buffer_head)] = 0x1E;
    buffer_head++;

    printf("%p \n", floatptr );
    con_to_byteP((void*)&hiptr, &buffer_head, buffer);
    buffer[(buffer_head)] = 0x1E;
    buffer_head++;


    printf("Buffer: ");
    for(size_t i = 0; i < buffer_head; i++){
        printf("%x ", buffer[i]);
    }
    printf("\nbuffer_head: %u", buffer_head);

    return 0;
}
#endif
