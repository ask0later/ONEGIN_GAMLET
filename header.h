#include <stdio.h>
#include <sys\stat.h>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <assert.h>

struct TEXT
{
    size_t nline;
    char** text;
    size_t sizebuf;
    char* buffer;
};


const size_t SIZE_TEXT = 512;


TEXT BubbleSort(TEXT data);
void forward_quick_sort(char** ptr_to_nline, int low, int top);
void backward_quick_sort(char** ptr_to_nline, int low, int top);


TEXT Splitting_Into_Lines(TEXT data);
TEXT Reading_From_File(TEXT data);

void Print_Pointer(char** ptr_to_nline, TEXT data);

size_t Buffer_Size();
void DestroyStruct(TEXT* data);



