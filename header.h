#include <stdio.h>
#include <sys\stat.h>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <assert.h>

struct Text
{
    size_t nline;
    char** text;
    size_t sizebuf;
    char* buffer;
};


Text BubbleSort(Text data);
void quick_sort(char** ptr_to_nline, int low, int top, int (*forward_or_back_strcmp) (char* s1, char* s2));

int Strcmp(char* arg1, char* argv2);
int backStrcmp(char* arg1, char* arg2);


void Splitting_Into_Lines(Text* data);
void Reading_From_File(Text* data);

void Print_Pointer(char** ptr_to_nline, Text data);

size_t Buffer_Size();
void DestroyStruct(Text* data);



