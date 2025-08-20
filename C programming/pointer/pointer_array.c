#include<stdio.h>

// this program is written by Anees Kokadan
// to print the addresses of array elements using pointer 

int main(){

    int array[5];
    int i=0;
    int *p = array;
    

    // reading 5 array elements from user
    printf("Enter 5 array elements: \n");
    for (i=0; i<5; i++){
        scanf("%d", &array[i]);
    }
    
    // printing the user array of 5 elements 
    printf("Your array is as follows: \n");
    for (i=0; i<5; i++){
        printf("%d ", array[i]);
    }

    // implementing pointer concept on arrays
    printf("\n\nThe storage addresses of the elements in the array are:\n");
    for (i=0; i<5; i++){
        printf("array[%d] = %d = %p\n", i, array[i], p+i);
    }

     printf("\n\nThe value inside addresses of the the array (printed by using pointer concept) are:\n");
    for (i=0; i<5; i++){
        printf("array[%d] = %d = %d\n", i, array[i], *(p+i));
    }





    return 0;
}