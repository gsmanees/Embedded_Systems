#include<stdio.h>
void swap_callbyValue(int a,int b){ // CV function
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("\na inside CV function = %d\n", a);
    printf("b inside CV function = %d", b);
}
void swap_callbyReference(int *a, int *b){ // CR function
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    printf("\n a inside CR function = %d\n", *a);
    printf("b inside CR function = %d", *b);
}

int main(){ // main function
    int a = 10;
    int b = 15;

    swap_callbyValue(a,b);
    printf("\nValue of a after callbyValue swapping inside main function = %d", a);
    printf("\nValue of b after callbyValue swapping inside main function = %d", b);

    swap_callbyReference(&a,&b);
    printf("\nValue of a after callbyReference swapping inside main function = %d", a);
    printf("\nValue of b after callbyReference swapping inside main function = %d", b);

    return 0;
}