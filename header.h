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


const size_t SIZE_TEXT = 50;


TEXT BubbleSort(TEXT data);
//size_t** q_sort(TEXT data, int first, int last);



TEXT Splitting_Into_Lines(TEXT data);
TEXT Reading_From_File(TEXT data);

void Print_Pointer(TEXT data);

size_t Buffer_Size();
void DestroyStruct(TEXT* data);



