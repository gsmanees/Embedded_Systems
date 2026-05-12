#include <stdio.h>

int main() 
{
    int n, i, index = 0;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n], result[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i=0; i<n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Store negative numbers first
    for(i=0; i<n; i++) 
    {
        if(arr[i] < 0) {
            result[index] = arr[i];
            index++;
        }
    }

    // Store positive numbers and zero next
    for(i=0; i<n; i++) 
    {
        if(arr[i] >= 0) {
            result[index] = arr[i];
            index++;
        }
    }

    // Display rearranged array
    printf("Rearranged array:\n");
    for(i=0; i<n; i++) 
    {
        printf("%d ", result[i]);
    }

    return 0;
}