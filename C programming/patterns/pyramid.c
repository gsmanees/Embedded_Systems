#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        // print spaces
        for(j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // print stars
        for(j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        // move to next line
        printf("\n");
    }
    return 0;
}