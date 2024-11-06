/*
Ques-2 : Wrp to declare the student structure having data members roll, name, marks then input the student details and display 
the student details using pointer to structure. 
*/

#include <stdio.h>

struct student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct student s;
    struct student *ptr = &s;
    printf("Enter roll number: ");
    scanf("%d", &(ptr->roll));
    printf("Enter name: ");
    scanf("%s", ptr->name);
    printf("Enter marks: ");
    scanf("%f", &(ptr->marks));
    printf("\nStudent Details:\n");
    printf("Roll Number: %d\n", ptr->roll);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %.2f\n", ptr->marks);
    return 0;
}