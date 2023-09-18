#include "directives.h"

void quick_sort(char** ptr_to_nline, int low, int top, int (*forward_or_back_strcmp) (char* s1, char* s2));

int Strcmp(char* arg1, char* argv2);
int backStrcmp(char* arg1, char* arg2);

void Swap_Pointer(char** ptr, int left, int right);

bool IsAlpha(int arg);
