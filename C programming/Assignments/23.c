#include <stdio.h>

int main() {
    int arr[100], temp[100];
    int size, n, i;
    char dir;

    // Input array size
    printf("Enter size of array: ");
    scanf("%d", &size);

    // Input array elements
    printf("Enter array elements:\n");
    for(i=0; i<size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Input rotation count
    printf("Enter number of positions to rotate: ");
    scanf("%d", &n);

    // Input direction
    printf("Enter direction (L for Left, R for Right): ");
    scanf(" %c", &dir);

    // Handle n greater than array size
    n = n%size; // if Array size = 5, n = 7, n is grater than array size, so actually 7%5 = 2 rotation needed

    // Left rotation
    if(dir == 'L' || dir == 'l') 
    {
        for(i=0; i<size; i++) {
            temp[i] = arr[(i + n) % size]; // pushing elements to left - beginning posision 
        }
    }

    // Right rotation
    else if(dir == 'R' || dir == 'r') 
    {
        for(i=0; i<size; i++) {
            temp[(i + n) % size] = arr[i]; // pushing elements to right - ending posisiton 
        }
    }

    else {
        printf("Invalid direction!\n");
        return 0;
    }

    // Display rotated array
    printf("Rotated array:\n");
    for(i = 0; i < size; i++) 
    {
        printf("%d ", temp[i]);
    }

    return 0;
}