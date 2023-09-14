#include <stdio.h>


void Sort(int array[], int left, int right);
int Part(int array[], int left, int right);
void Swap(int array[], int left, int right);

int main()
{
    int array[10] = {5, 15, 3, 18, 10, 12, 10, 6, 9};
    int left = 0;
    int right = 8;
    Sort(array, left, right);
    int i = 0;
    while(i < 9)
    {
        printf("%d ", array[i]);
        i++;
    }
}
void Sort(int array[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = Part(array, left, right);

    Sort(array, left, mid - 1);
    Sort(array, mid + 1, right);
}

int Part(int array[], int left, int right)
{
    int mid = array[(left + right) / 2];
    while (left < right)
    {
        if (array[left] == array[right])
        {
            left++;
        }
        while(array[left] < mid)
        {
            left++;
        }
        while(array[right] > mid)
        {
            right--;
        }
        Swap(array, left, right);
    }
    return left;
}

void Swap(int array[], int left, int right)
{
    int temp = 0;
    temp = array[left];
    array[left] = array[right];
    array[right] = temp;
}
