#include<stdio.h>
int main(){

    int a = 15;
    int *p = &a;

    printf("\nValue of a = %d", a);
    printf("\nAddress of a (using &)= %p", &a);
    printf("\nContent inside p (using p)= %p", p);
    printf("\nValue inside p (using *p) = %d", *p);
   // printf("value inside **p = %d", *(*p));








    return 0;
}