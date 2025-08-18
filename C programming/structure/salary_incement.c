#include<stdio.h>

// this code is written by Anees Kokadan
// Salary increment by percentage calculator 
// used strycture passing function



// structure declared as global
struct employee{
    char name[32];
    int id;
    float salary;
};

// function definition for percentage calculation
// structure employee e and percent - both are from user input has been passed to function

void increment(struct employee e, float percent){

    percent = e.salary*percent/100;
    printf("Incremented salary is: %.2f", e.salary+percent);
    
    
}



int main(){


float percent;
struct employee e;

printf("Enter Employee name: ");
scanf("%31[^\n]", e.name);

printf("Enter employee ID: ");
scanf("%d", &e.id);

printf("Enter salary: ");
scanf("%f", &e.salary);

printf("Enter increment percentage: ");
scanf("%f", &percent);

// calling increment function
increment (e, percent);

}

