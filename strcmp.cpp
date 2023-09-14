#include <stdio.h>

int strcmp(const char *X, const char *Y);

int main()
{
    char *X = "Techie";
    char *Y = "Tech";

    int ret = strcmp(X, Y);

    if (ret > 0) {
        printf("%s", "X is greater than Y");
    }
    else if (ret < 0) {
        printf("%s", "X is less than Y");
    }
    else {
        printf("%s", "X is equal to Y");
    }

    return ;
}

int strcmp(char* arg1, char* argv2)
{
    while (*X)
    {
        // if characters differ, or end of the second string is reached
        if (*X != *Y)
        {
            break;
        }

        // move to the next pair of characters
        X++;
        Y++;
    }

    // return the ASCII difference after converting `char*` to `unsigned char*`
    return *(const unsigned char*)X - *(const unsigned char*)Y;
}
