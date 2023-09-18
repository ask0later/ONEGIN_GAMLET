#include <stdio.h>
#include <sys\stat.h>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <assert.h>

struct TEXT// smaller letters
{
    size_t nline;
    char** text;
    size_t sizebuf;
    char* buffer;
};


const size_t SIZE_TEXT = 512;


TEXT BubbleSort(TEXT data);
void quick_sort(char** ptr_to_nline, int low, int top, int (*forward_or_back_strcmp) (char* s1, char* s2));

int forward_or_back_strcmp(char* s1, char* s2);
int Strcmp(char* arg1, char* argv2);
int backStrcmp(char* arg1, char* arg2);


void Splitting_Into_Lines(TEXT* data);
void Reading_From_File(TEXT* data);

void Print_Pointer(char** ptr_to_nline, TEXT data);

size_t Buffer_Size();
void DestroyStruct(TEXT* data);



