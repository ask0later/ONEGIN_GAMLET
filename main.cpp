#include "header.h"


int main()
{
    struct TEXT data = {.nline = 1, .text = 0, .sizebuf = Buffer_Size(), .buffer = 0};
    data = Reading_From_File(data);
    data = Splitting_Into_Lines(data);


    Print_Pointer(data);

    data = BubbleSort(data);
    //data.text = q_sort(data.text, 0, data.nline);

    Print_Pointer(data);

    DestroyStruct(&data);
}







