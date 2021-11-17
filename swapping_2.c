
//C program to swap two numbers using call by reference


#include <stdio.h>


void swap(int * num1, int * num2)
{
    int temp;

    printf("In Function values before swapping: %d %d\n", *num1, *num2);

    temp  = *num1;
    *num1 = *num2;
    *num2 = temp;

    printf("In Function values after swapping: %d %d\n\n", *num1, *num2);
}

int main()
{
    int n1, n2;

    printf("Enter two numbers: ");
    scanf("%d%d", &n1, &n2);

    printf("In Main values before swapping: %d %d\n\n", n1, n2);


    swap(&n1, &n2);

    printf("In Main values after swapping: %d %d", n1, n2);

    return 0;
}