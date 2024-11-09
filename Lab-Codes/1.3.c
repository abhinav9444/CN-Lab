/*
Ques-3 : write a program to accept array of employee info in structure and try to sort them according to salary of the employee.
structure contains the data members(emp_no, salary, name)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int emp_no;
    float salary;
    char name[50];
};

int compare(const void *a, const void *b) {
    struct Employee *emp1 = (struct Employee *)a;
    struct Employee *emp2 = (struct Employee *)b;
    
    if (emp1->salary < emp2->salary) {
        return -1;
    } else if (emp1->salary > emp2->salary) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct Employee employees[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i+1);
        printf("Employee Number: ");
        scanf("%d", &employees[i].emp_no);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        printf("Name: ");
        scanf("%s", employees[i].name);
    }
    
    qsort(employees, n, sizeof(struct Employee), compare);
    
    printf("\nSorted Employee Details:\n");
    printf("| %-12s | %-10s | %-20s |\n", "Emp Number", "Salary", "Name");
    printf("|--------------|------------|----------------------|\n");
    for (int i = 0; i < n; i++) {
        printf("| %-12d | %-10.2f | %-20s |\n", employees[i].emp_no, employees[i].salary, employees[i].name);
    }   
    return 0;
}