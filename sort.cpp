#include "sort.h"


TEXT BubbleSort(TEXT data)
{
    for (size_t outpass = 0; outpass < data.nline - 1; outpass++)
    {
        for (size_t inpass = 0; inpass < data.nline - 1 - outpass; inpass++)
        {
            if (Strcmp(data.text[inpass], data.text[1 + inpass]) > 0)
            {
                Swap_Pointer(data.text + inpass, data.text + 1 + inpass);
            }
        }
    }
    return data;
}




/*
size_t** q_sort(TEXT data, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = (data.text + (left + right) / 2);
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
        printf("l = %d, r = %d\n", left, right);
        qsort(array, first, right);
        qsort(array, left, last);
    }
}
*/


int Strcmp(char* arg1, char* arg2)
{
    assert(arg1);
    assert(arg2);

    while (*arg1)
    {
        if (!isupper(*arg1))
        {
            arg1++;
        }
        if (!isupper(*arg2))
        {
            arg2++;
        }

        if (*arg1 != *arg2)
        {
            break;
        }
        arg1++;
        arg2++;
    }

    return *(const unsigned char*)arg1 - *(const unsigned char*)arg2;
}

void Swap_Pointer(char** arg1, char** arg2)
{
    assert(arg1);
    assert(arg2);

    char* tmp = {};
    tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
    /*tmp = data.text[inpass];
    data.text[inpass] = data.text[inpass + 1];
    data.text[inpass + 1] = tmp;*/
}
