#include <stdio.h>

int main() 
{
    int arr[100], n;
    int largest, secondLargest;
    int smallest, secondSmallest;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(int i=0; i<n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Initialize values
    largest = secondLargest = arr[0];
    smallest = secondSmallest = arr[0];

    for(int i=1; i<n; i++) 
    {

        // Find largest and second largest
        if(arr[i] > largest) 
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest) 
        {
            secondLargest = arr[i];
        }

        // Find smallest and second smallest
        if(arr[i] < smallest) 
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < secondSmallest && arr[i] != smallest) 
        {
            secondSmallest = arr[i];
        }
    }

    // Check if all elements are same
    if(largest == smallest) {
        printf("All elements are same.\n");
    }
    else {
        printf("Second Largest = %d\n", secondLargest);
        printf("Second Smallest = %d\n", secondSmallest);
    }

    return 0;
}