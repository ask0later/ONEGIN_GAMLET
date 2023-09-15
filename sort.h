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

int Strcmp(char* arg1, char* argv2);
int backStrcmp(char* arg1, char* arg2);

void Swap_Pointer(char** ptr, int left, int right);

bool IsAlpha(int arg);
