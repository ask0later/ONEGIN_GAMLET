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
int Strcmp(char* arg1, char* argv2);
void Swap_Pointer(char** arg1, char** arg2);
