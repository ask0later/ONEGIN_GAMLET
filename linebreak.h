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


size_t Buffer_Size();

void Splitting_Into_Lines(TEXT* data);

void Reading_From_File(TEXT* data);

void Print_Pointer(char** ptr_to_nline, TEXT data);
void DestroyStruct(TEXT* data);

bool IsAlpha(int arg);
