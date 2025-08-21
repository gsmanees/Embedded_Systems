#include<stdio.h>
int main(){


    int a=46;
    int arr[5] = {1, 42, 32, 43, 51};
    int *p=&a;
    int *arr_ptr = arr;

    printf("\np = %p", p);
    printf("\n&a = %p", &a);
    printf("\n*p = %d", *p);
    printf("\narr = %p", arr); // array first element address printing
    printf("\narr_ptr = %p", arr_ptr); // first element address
    printf("\n*arr_ptr = %d", *arr_ptr); // first element printing 
    printf("\n*(arr_ptr+1) = %d", *(arr_ptr+1)); //second element
    printf("\n*arr_ptr++ = %d", *arr_ptr++); // prints first elements and increment its value to next element
    printf("\n*++arr_ptr = %d", *++arr_ptr); // since arr_ptr is already pointing to second element, 
    // now pre incremented and printed, so third element will print
    return 0;
}