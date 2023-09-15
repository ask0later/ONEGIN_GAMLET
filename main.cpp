#include "header.h"


int main()
{
    struct TEXT data = {.nline = 0, .text = 0, .sizebuf = Buffer_Size(), .buffer = 0};

    data = Reading_From_File(data);

    data = Splitting_Into_Lines(data);
    printf("ABOBA\n");
    printf("!!!!!!!!!!!!!!!!%s\n", *(data.text + 200));

    char** ptr_to_nline = data.text;

    Print_Pointer(ptr_to_nline, data);
    /*
    printf("%s\n", *(ptr_to_nline + 120));
    printf("%s\n", *(data.text + 343));
    printf("number of line: %d\n", data.nline);*/
    //data = BubbleSort(data);


    //forward_quick_sort(ptr_to_nline, 0, data.nline - 1);
    //backward_quick_sort(ptr_to_nline, 0, data.nline - 1);

    //Print_Pointer(ptr_to_nline, data);

    DestroyStruct(&data);
}







