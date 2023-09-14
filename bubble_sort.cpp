#include <stdio.h>

const size_t SIZE = 15;

void bubbleSort(int array[]);
void Swap_Pointer(int* arg1, int* arg2);
void PrintArray(int* arr);

int main()
{
    int array[] = {3, 18, 20, 4, 19, 6, 10, 10, 10, 20, 4, 19, 16, 8, 8};
    PrintArray(array);
    printf("\n");
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = 0;
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
    //spsi
    PrintArray(array);
}

void PrintArray(int arr[])
{
    int i = 0;
    while (i < SIZE)
    {
        printf("%d ", *(arr + i));
        i++;
    }
}

void Swap_Pointer(int* arg1, int* arg2)
{
    int temp = 0;
    temp = *arg1;
    *arg1 = *arg2;
    *arg2 = temp;
}
