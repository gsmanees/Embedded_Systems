
/*
Enter number of terms of the array: 5

Enter ayyay elements :

Enter element 1: 1

Enter element 2: 2

Enter element 3: 3

Enter element 4: 4

Enter element 5: 5

The socond largest element is : 4
*/

#include<stdio.h>
#include<stdlib.h>
int main ()
{
    int n;
    int i;
    int *arr;
    printf("Enter number of terms of the array: ");
    scanf("%d", &n);

    // calloc - dynamic memory allocation for array

    arr = (int *) calloc (n, sizeof (int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("\nEnter ayyay elements :\n");
    for (i=0; i<n; i++)
    {
        printf("\nEnter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }


// sorting array for finding second largest element
for (i=0; i<n-1; i++)
{
    for (int j=i+1; j<n; j++)
    {
        if (arr[i]<arr[j])
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

printf("\nThe socond largest element is : %d", arr[1]);
}