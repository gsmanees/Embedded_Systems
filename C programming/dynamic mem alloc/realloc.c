#include<stdio.h>
#include<stdlib.h>

int main(){

    int n,i, new; // n is first number and new is new size 
    int *ptr;

    // scanning number of elements from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // allocating dynamic memory by malloc
    ptr = (int *) malloc (n*sizeof(int));
    if(ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }


    // scanning elements 
    for (i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", (ptr+i));
    }

    // printing elements 
    printf("You enered: \n");
    for (i=0; i<n; i++){
        printf("%d ", *(ptr+i));

    }


    // scanning new size from user 
    printf("\nEnter new size: ");
    scanf("%d", &new);

    // reallocating the new dynamic memory to the already allocated memory by using realloc
    ptr = (int *) realloc(ptr, new*sizeof(int));
      if(ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }


    // scnning new values from user 
    printf("\nEnter new values below: \n");

    for (i=n; i<new; i++){ // this for loop starting from nth memory position
        printf("\nEnter value %d: ", i+1);
        scanf("%d", (ptr+i));
    }

    // printing all the values together after realloc
    printf("the values after realloc: \n");
    for (i=0; i<new; i++){
        
        printf("%d ", *(ptr+i));
    }

free(ptr); // freeing up used memory

    return 0;
}