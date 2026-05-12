#include <stdio.h>

int main() {
    int arr[100], size, target;
    int i, j, found = 0;

    // Input array size
    printf("Enter size of array: ");
    scanf("%d", &size);

    // Input array elements
    printf("Enter array elements:\n");
    for(i=0; i<size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Input target sum
    printf("Enter target sum: ");
    scanf("%d", &target);

    // Find pairs
    printf("Pairs with sum %d are:\n", target);

    for(i=0; i<size-1; i++) 
    {
        for(j=i+1; j<size; j++) 
        {

            // Check if pair sum equals target
            if(arr[i] + arr[j] == target) {
                printf("(%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    // If no pair found
    if(found == 0) {
        printf("No pairs found.\n");
    }

    return 0;
}