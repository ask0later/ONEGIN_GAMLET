#include "sort.h"

/*
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
}*/


void quick_sort(char** ptr_to_nline, int low, int top, int (*forward_or_back_strcmp) (char* s1, char* s2))
{
    if (low >= top)
    {
        return;
    }

    int left = low, right = top;
    int middle = (left + right) / 2;
    char* pivot = ptr_to_nline[middle];

    do
    {
        // while (func_ptr(ptr_to_nline[left], pivot))
        while (forward_or_back_strcmp(ptr_to_nline[left], pivot) < 0)
            {
                left++;
            }
        while (forward_or_back_strcmp(ptr_to_nline[right], pivot) > 0)
            {
                right--;
            }
        if (left <= right)
        {
            Swap_Pointer(ptr_to_nline, left, right);
            left++;
            right--;
        }

    } while (left < right);

    quick_sort(ptr_to_nline, low, right, forward_or_back_strcmp);
    quick_sort(ptr_to_nline, left, top, forward_or_back_strcmp);

}


int Strcmp(char* arg1, char* arg2)
{
    assert(arg1);
    assert(arg2);

    while (*arg1)
    {
        if (!IsAlpha(*arg1))
        {
            arg1++;
        }
        if (!IsAlpha(*arg2))
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

int backStrcmp(char* arg1, char* arg2)
{
    assert(arg1);
    assert(arg2);
    while (*arg1 != '\n')
        arg1++;
    while (*arg2 != '\n')
        arg2++;

    arg1--;
    arg2--;
    while (*arg1)
    {
        if (!IsAlpha(*arg1))
        {
            arg1--;
        }
        if (!IsAlpha(*arg2))
        {
            arg2--;
        }

        if (*arg1 != *arg2)
        {
            break;
        }
        arg1--;
        arg2--;
    }

    return *(const unsigned char*)arg1 - *(const unsigned char*)arg2;
}

void Swap_Pointer(char** ptr, int left, int right)
{
    assert(ptr);

    char *tmp = {};
    tmp = ptr[left];
    ptr[left] = ptr[right];
    ptr[right] = tmp;
}
