#include<stdio.h>
#include<stdlib.h>

int main(){

    int n, i;
    int *arr;

    printf("Enter size of array: ");
    scanf("%d", &n);

    // allocates memory acc to user input 
    arr = (int *) calloc (n, sizeof(int)); // used for array and all values are initially set to 0
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    // just printing the initial value to check whether it assigned to 0 or not
    printf("\nThe initial values at allocated addresses are: \n");
    for (i=0; i<n; i++){
        printf("%d ", arr[i]);

    }
    // scanning array elements from user
    printf("\nplease give values for array;\n");
    for (i=0; i<n; i++){
        printf("Enter element %d:", i+1);
        scanf("%d", &arr[i]);

    }
    // printing elements 
    printf("the entered values are \n");
    for (i=0; i<n; i++){

        printf("%d ", arr[i]);
    }

    free (arr);
    // printf("%d", arr); // it will give garbage value, since we freed the used memory


    return 0;
}