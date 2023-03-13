#include<stdio.h>
#include<stdint.h>

typedef struct
{
    uint64_t a;
    uint64_t b;
}size8byte;


typedef struct
{
    uint32_t PPCCR;     //Cache control register
    uint32_t PCCLCR;    //Cache line control register
    uint32_t PCCSAR;    //Cache search address register
    uint32_t PCCCVR;    //Cache read/write value register
    size8byte PCCRMR;    //Cache regions mode register
}LMEM;

int main(int argc, char const *argv[])
{
    LMEM name;
    LMEM *ptr = &name;

    // printf("Address: %p\n", &name);
    printf("Address: %p\n", &(name.PPCCR));
    printf("Address: %p\n", &(name.PCCLCR));
    printf("Address: %p\n", &(name.PCCSAR));
    printf("Address: %p\n", &(name.PCCCVR));
    printf("Address: %p\n", &(name.PCCRMR));

    // printf("Size: %d\n", *ptr);
    // printf("Size: %d\n", name);
    // printf("Size: %d\n", sizeof(name.PPCCR));
    // printf("Size: %d\n", sizeof(name.PCCLCR));
    // printf("Size: %d\n", sizeof(name.PCCSAR));
    // printf("Size: %d\n", sizeof(name.PCCCVR));
    // printf("Size: %d\n", sizeof(name.PCCRMR));
    return 0;
}

