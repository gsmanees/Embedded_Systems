#include<stdio.h>
#include<stdlib.h>
int main()
{
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

    // scanning array elements from user
    printf("\nplease give values for array;\n");
    for (i=0; i<n; i++){
        printf("Enter element %d:", i+1);
        scanf("%d", &arr[i]);
    }

free (arr);
    // printf("%d", arr); // it will give garbage value, since we freed the used memory
}