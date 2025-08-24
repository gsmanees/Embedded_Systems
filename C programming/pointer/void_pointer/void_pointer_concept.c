#include<stdio.h>
int main(){


    // int with void pointer 
    int a=10;
    int *p = &a;
    printf("\np = %p", p);
    printf("\n*p = %d", *p);

    void *ptr = &a; // void pointer declaration, data type doesnt matter during dclaration
    printf("\nptr = %p", ptr); // void pointer address printing, no need casting 
    printf("\n*ptr = %d", *(int *)ptr); // void pointer data printing format


    *p = 30; // pointer value assigning 
    printf("\n*p = %d", *p);


    *(int *)ptr = 40; // void pointer value assigning
    printf("\n*ptr = %d", *(int *)ptr);  



    // float variable with void pointer 
    float b=3.14;
    void *ftr = &b; 

    printf("\nftr = %p", ftr);
    printf("\n*ftr = %.2f", *(float*)ftr); // void pointer dereferencing to float 

    *(float *)ftr = 9.13; // float value assignig to void pointer
    printf("\n*ftr = %.2f", *(float *)ftr); // void pointer dereferencing to float
    return 0; 
}