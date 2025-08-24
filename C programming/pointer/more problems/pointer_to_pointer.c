#include<stdio.h>

int main(){

    int a=5;
    int *p=&a;
    int **q=&p;


    printf("\nValue of a = %d", a); // address of a
    printf("\nValue of p = %p", p); // address of pointer p
    printf("\nValue of q = %p", q); // address of pointer q
    printf("\nValue of *p = %d", *p); // value inside pointer p
    printf("\nValue of **q = %d", **q); // value inside pointer q

    return 0;
}