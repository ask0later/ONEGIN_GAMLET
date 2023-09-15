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



void forward_quick_sort(char** ptr_to_nline, int low, int top)
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
        while (Strcmp(ptr_to_nline[left], pivot) < 0)
            {
                left++;
            }
        while (Strcmp(ptr_to_nline[right], pivot) > 0)
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

    forward_quick_sort(ptr_to_nline, low, right);
    forward_quick_sort(ptr_to_nline, left, top);
}

//change
void backward_quick_sort(char** ptr_to_nline, int low, int top)
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
        while (backStrcmp(ptr_to_nline[left], pivot) < 0)
            {
                left++;
            }
        while (backStrcmp(ptr_to_nline[right], pivot) > 0)
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

    backward_quick_sort(ptr_to_nline, low, right);
    backward_quick_sort(ptr_to_nline, left, top);
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

//change
int backStrcmp(char* arg1, char* arg2)
{
    assert(arg1);
    assert(arg2);
    if (*arg1 != '\n')
        arg1++;
    if (*arg2 != '\n')
        arg2++;

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
