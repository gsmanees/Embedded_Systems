#include<stdio.h>

int main(){

    float arr[5] = {1.1,2.1,3.1,4.1,5.1};
    void *arr_ptr = arr; // array address to void pointer 
    int i=0;

    // printing elements of the array with void pointer 
    for (i=0; i<5; i++){
        printf("%.2f ", *(float *)arr_ptr+i ); // arr_ptr+i --> to point next element of arrray
        // like current address+0, then  increment address by the value of i (here by 1)
    }
}