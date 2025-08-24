#include<stdio.h>
#include<stdlib.h> // used for dynamic mem alloc--> malloc, calloc, realloc

int main(){
    int n=0;
    int *ptr;
    int i=0;

    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    // dynamic memory allocation by malloc
    ptr = (int *)malloc(n*sizeof(int));
    if (ptr == NULL){
        printf("\nMemory allocation is failed");
        return 1;
    }

    // scaning elements from user
    for (i=0; i<n; i++){
        printf("Enter %d th element: ", i+1);
        scanf("%d", (ptr+i));
    }

    // display the elements 
    printf("\nYou entered \n");
    for(i=0; i<n; i++){
        printf("%d\n", *(ptr+i));
    }
    free (ptr); // freeing used memory


    return 0;
}