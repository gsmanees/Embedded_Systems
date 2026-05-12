#include <stdio.h>

int main() {
    int a[100], b[100], c[200];
    int n1, n2;
    int i, j, k;

    // Input first array
    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter elements of first sorted array:\n");
    for(i=0; i<n1; i++) {
        scanf("%d", &a[i]);
    }

    // Input second array
    printf("Enter size of second array: ");
    scanf("%d", &n2);

    printf("Enter elements of second sorted array:\n");
    for(i=0; i<n2; i++) {
        scanf("%d", &b[i]);
    }

    // Merge arrays
    i = 0;
    j = 0;
    k = 0;

    while(i<n1 && j<n2) {
        if(a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of first array
    while(i < n1) {
        c[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements of second array
    while(j < n2) {
        c[k] = b[j];
        j++;
        k++;
    }

    // Display merged array
    printf("Merged sorted array:\n");

    for(i = 0; i < n1 + n2; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}