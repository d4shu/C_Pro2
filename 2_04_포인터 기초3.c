#include <stdio.h>

int main()
{
    int i = 10;
    int* p;
    p = &i;
    
    printf("i = %d\n", i);
    printf("address of i = %p\n", p);
    printf("*p = %d\n", *p);
    
}