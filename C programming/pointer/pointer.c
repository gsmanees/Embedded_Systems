#include<stdio.h>

int main (){

    int a=45;
    int b=50;
    int c=55;
    int *p1=&a;
    int *p2=&b;
    int *p3=&c;

    int *q1 = &(*p1);
    int *q2 = &(*p2);
    int *q3 = &(*p3);



    printf("\nvalue of a = %d", a);
    printf("\nvalue of b = %d", b);
    printf("\nvalue of c = %d", c);

    
    printf("\nvalue inside &a = %d", *p1);
    printf("\nvalue inside &b = %d", *p2);
    printf("\nvalue inside &c = %d", *p3);

    printf("\nvalue of *p1 = %p", p1);
    printf("\nvalue of *p2 = %p", p2);
    printf("\nvalue of *p3 = %p", p3);

    printf("\nAddress of a = %p", &a);
    printf("\nAddress of b = %p", &b);
    printf("\nAddress of c = %p", &c);

    printf("\nAddress of pointer p1 (*p1): %p", q1);
    printf("\nAddress of pointer p2 (*p2): %p", q2);
    printf("\nAddress of pointer p1 (*p3): %p", q3);









    return 0;
}

