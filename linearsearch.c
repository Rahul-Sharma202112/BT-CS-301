#include <stdio.h>
#define SIZE 5

int main()
{
    int arr[SIZE][SIZE], key, flag = 0;
    int i, j;
    printf("Enter data\n");

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    
    printf("\noutput data\n\n");

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the value which you want to search\n");
    scanf("%d", &key);

    for (i = 0; i < SIZE && flag == 0; i++)
    {
        for (j = 0; j < SIZE && flag == 0; j++)
        {
            if (key == arr[i][j])
            {
                flag = 1;
            }
        }
    }
    if (flag == 1)
    {

        printf("\nYes data is found at (%d,%d)\n", i, j);
    }
    else
    {
        printf("Data is not found\n");
    }
    return 0;
}