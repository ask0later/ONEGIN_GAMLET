#include "header.h"


int main()
{
    struct Text data = {.nline = 1, .text = 0, .sizebuf = Buffer_Size(), .buffer = 0};

    Reading_From_File(&data);

    Splitting_Into_Lines(&data);

    char** ptr_to_nline = data.text;

    quick_sort(ptr_to_nline, 0, (int) data.nline - 1, &Strcmp);


    Print_Pointer(ptr_to_nline, data);

    DestroyStruct(&data);
}







