#include<stdio.h>

// This code is written by Anees Kokadan
// prits a given array, pritns sum of the elements, take out odd elements 

// function definition to print the given array
void print_array(int array[]){
    int p=0;
    printf("\n\nThe given array is: [ ");
    for (p=0; p<20; p++){
        printf("%d ", array[p]);
    }
    printf("]");
}

// function definition to print the sum of elements in the array
void array_sum(int array[]){
    int i = 0;
    int sum = 0;
    for (i=0; i<=19; i++){
        sum = sum + array[i];
    }
    printf("\nThe sum of elements in the array is: %d", sum);
} 


// function definition to take out and print odd elements from the given array
int array_odd(int array[]){
    int i = 0;
    int j=0;
    int n=0;
    int odd[10];
    printf("\n\nOdd elements in array: \n");
    for (i=0; i<=19; i++){
        if (array[i] %2 ==1){
            printf("array[%d] = %d\n", i, array[i]);
            odd[n]=array[i];
            n++;
        }
        
    }

    // code to make another array with the selected odd numbers  
    printf("\n\nNumer of odd elements: %d", n);
    printf("\n\nOdd array is printed as follows:\n");
    printf("[ ");
     for (j=0; j<n; j++){
            printf("%d ", odd[j]);
        }
    printf("]\n\n");
}


int main(){

    int array[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    print_array(array); // calling print array function
    array_sum(array); // calling sum array function
    array_odd(array); // calling odd array function


    return 0;
}

