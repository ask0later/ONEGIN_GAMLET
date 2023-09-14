#include <stdio.h>

const size_t SIZE = 7;

void q_sort(int array[], int first, int last);
void PrintArray(int array[]);
void Swap(int array[], size_t left, size_t right);

int main()
{
    int array[] = {1, 9, 20, 9, 2, 9, 12};
    size_t right = SIZE - 1;
    size_t left = 0;

    q_sort(array, left, right);


    PrintArray(array);
}


void q_sort(int array[], int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = array[(left + right) / 2];
        do
        {
            while (array[left] < middle)
                left++;
            while (array[right] > middle)
                right--;
            if (left <= right)
            {
                Swap(array, left, right);
                left++;
                right--;
            }
        } while (left <= right);
        //printf("l = %d, r = %d\n", left, right);
        q_sort(array, first, right);
        q_sort(array, left, last);
    }
}
/*
void q_sort(int array[], int first, int last)
{
    printf("f = %d, l = %d\n", first, last);
    printf("a\n");
    if (first >= last)
        return;
    printf("a\n");
    int left = first, right = last, middle = array[(left + right) / 2];
    do
    {
        while (array[left] < middle)
            left++;
        while (array[right] > middle)
            right--;
        //if (array[left] == array[right])
        //{
        //    left++;
        //}
        Swap(array, left, right);
    } while (left <= right);
    printf("l = %d, r = %d\n", left, right);
    if (left > first)
    {
        q_sort(array, first, left - 1);
    }
    if (left < last)
    {
        q_sort(array, left + 1, last);
    }
}*/

void PrintArray(int array[])
{
    int i = 0;
    while (i < SIZE)
    {
        printf("%d ", *(array + i));
        i++;
    }
}

void Swap(int array[], size_t left, size_t right)
{
    int temp = 0;
    temp = array[left];
    array[left] = array[right];
    array[right] = temp;
}

