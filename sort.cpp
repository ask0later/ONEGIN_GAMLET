#include "sort.h"

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
        if (!IsAlpha(toupper(*arg1)))
        {
            arg1++;
        }
        if (!IsAlpha(toupper(*arg2)))
        {
            arg2++;
        }

        if ((toupper(*arg1)) != (toupper(*arg2)))
        {
            break;
        }
        arg1++;
        arg2++;
    }

    return (toupper(*arg1)) - (toupper(*arg2));
}

int backStrcmp(char* arg1, char* arg2)
{
    assert(arg1);
    assert(arg2);
    while (*arg1 != '\0')
        arg1++;
    while (*arg2 != '\0')
        arg2++;

    arg1--;
    arg2--;

    while (*arg1)
    {
        if (!IsAlpha(toupper(*arg1)))
        {
            arg1++;
        }
        if (!IsAlpha(toupper(*arg2)))
        {
            arg2++;
        }

        if ((toupper(*arg1)) != (toupper(*arg2)))
        {
            break;
        }
        arg1--;
        arg2--;
    }

    return (toupper(*arg1)) - (toupper(*arg2));
}

void Swap_Pointer(char** ptr, int left, int right)
{
    assert(ptr);

    char *tmp = {};
    tmp = ptr[left];
    ptr[left] = ptr[right];
    ptr[right] = tmp;
}
