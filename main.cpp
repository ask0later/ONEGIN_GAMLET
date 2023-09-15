#include "header.h"


int main()
{
    struct TEXT data = {.nline = 1, .text = 0, .sizebuf = Buffer_Size(), .buffer = 0};
    data = Reading_From_File(data);
    data = Splitting_Into_Lines(data);

    char** ptr_to_nline = data.text;

    //Print_Pointer(ptr_to_nline, data);

    //data = BubbleSort(data);
    q_sort(ptr_to_nline, 0, data.nline - 1);

    Print_Pointer(ptr_to_nline, data);

    DestroyStruct(&data);
}







