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
