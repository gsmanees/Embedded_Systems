#include<stdio.h>
int main(){

    // structure definition
    struct employee {
        char name[32];
        int id;
        float salary;
    };

    // positional value assignmant 
    struct employee a = {"Anees Kokadan", 001, 55000.0};
    printf("Name: %s\nID: %d\nSalary: %f", a.name, a.id, a.salary);


    // assigning value by scanf - reading values from user 
    struct employee b;
    printf("\n\nEnter name 2: ");
    scanf("%31[^\n]", b.name);
    printf("Enter ID 2: " );
    scanf("%d", &b.id);
    printf("Enter salary 2: ");
    scanf("%.2f", &b.salary);

    printf("%s\n%d\n%.2f", b.name, b.id, b.salary);



return  0;
}