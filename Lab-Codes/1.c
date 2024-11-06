/*
Ques 1 : Wrp to swap 2 numbers by call by value and call by address.
*/

#include <stdio.h>
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Swapped value inside the swapping function : \nnum1=%d\nnum2=%d\n",a,b);
}
void swapByAddress(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int num1 = 10, num2 = 20;
    printf("Before swapping:\nnum1 = %d\nnum2 = %d\n",num1,num2);
    swapByValue(num1, num2);
    printf("After swapping by value outside the swapping function :\nnum1 = %d\nnum2 = %d\n",num1,num2);
    swapByAddress(&num1, &num2);
    printf("After swapping by address (changes original value of variable):\nnum1 = %d\nnum2 = %d\n",num1,num2);
    return 0;
}
