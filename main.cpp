#include "header.h"


int main()
{
    struct TEXT data = {.nline = 1, .text = 0, .sizebuf = Buffer_Size(), .buffer = 0};

    Reading_From_File(&data);// void
    printf("size of file: %d\n", data.sizebuf);


    Splitting_Into_Lines(&data);
    printf("number of line: %d\n", data.nline);

    char** ptr_to_nline = data.text;
    //Print_Pointer(ptr_to_nline, data);

    //Print_Pointer(ptr_to_nline, data);

    //quick_sort(ptr_to_nline, 0, data.nline - 1, &Strcmp);
    //quick_sort(ptr_to_nline, 0, data.nline - 1, backStrcmp(char* arg1, char* argv2););


    Print_Pointer(ptr_to_nline, data);

    DestroyStruct(&data);
}







