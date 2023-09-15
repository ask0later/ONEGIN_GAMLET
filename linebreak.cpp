#include "linebreak.h"

TEXT recalloc(TEXT data, size_t numRealloc)
{
    assert(&data);
                                           // dataSize
    data.text = (char**)realloc(data.text, numRealloc * SIZE_TEXT);
    for (size_t j = numRealloc * SIZE_TEXT; j < (numRealloc + 1) * SIZE_TEXT; j++)
    {//инициализирую память от text + k*SIZE до text + (k + 1)*SIZE
        *(data.text + j) = NULL;
    }
    return data;
}

void DestroyStruct(TEXT* data)
{
    data -> nline = 0;
    data -> sizebuf = 0;
    free(data -> text);
    free(data -> buffer);
}

void Print_Pointer(char** ptr, TEXT data)
{
    FILE* output = fopen("oneginOut.txt", "w");
    if (output == NULL)
    {
        perror("ERROR:");
        exit(errno);
    }

    for (size_t counter = 0; counter < data.nline; counter++)
    {
        fprintf(output, "line %2d : %s\n", counter + 1, *(ptr + counter));
    }
    fclose(output);
}

size_t Buffer_Size()
{
    struct stat buff;

    stat("onegin.txt", &buff);

    return (buff.st_size + 1);       // размер файла в байтах
}

TEXT Reading_From_File(TEXT data)
{
    assert(&data != NULL);

    FILE* input = fopen("onegin.txt", "r");
    if (input == NULL)
    {
        perror("ERROR:");
        exit(errno);
    }
    data.text = (char**)calloc(SIZE_TEXT, sizeof(char*));

    data.buffer = (char*)calloc(data.sizebuf, sizeof(char));

    fread((data.buffer), sizeof(char), (data.sizebuf), input); // копирование текста из файла в buffer

    printf("size of file = %d\n", data.sizebuf);
    //printf("%s",data.buffer);

    fclose(input);
    return data;
}

TEXT Splitting_Into_Lines(TEXT data)
{
    *(data.text + 0) = data.buffer + 0;

    for (size_t counter = 0; counter < data.sizebuf; counter++)
    {
        if (*(data.buffer + counter) == '\r')
        {
            *(data.buffer + counter) = '\0';
        }

        if (*(data.buffer + counter) == '\n')
        {
            *(data.buffer + counter) = '\0';
            *(data.text + data.nline) = data.buffer + counter + 1;
            (data.nline) ++;
        }
        else
        {
            *(data.buffer + counter) = toupper(*(data.buffer + counter));
        }
    }

    return data;
}

bool IsAlpha(int arg)
{
    if ((65 <= arg) && (arg <= 90))
        return 1;
    else
        return 0;
}
