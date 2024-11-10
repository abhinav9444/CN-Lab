/*
Ques-1.5 : write a program to enter a statement from console and write to file and then read from the file.
*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a statement: ");
    gets(str);
    FILE *fp = fopen("file.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp, "%s", str);
    fclose(fp);
    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char ch;
    printf("Contents of file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}