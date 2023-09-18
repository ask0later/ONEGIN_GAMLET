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




size_t Buffer_Size();

void Splitting_Into_Lines(Text* data);

void Reading_From_File(Text* data);

void Print_Pointer(char** ptr_to_nline, Text data);
void DestroyStruct(Text* data);

bool IsAlpha(int arg);
