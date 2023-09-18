#include "linebreak.h"


void Print_Pointer(char** ptr_to_nline, Text data)
{
    FILE* output = fopen("oneginOut.txt", "w");
    if (output == NULL)
    {
        perror("ERROR:");
        exit(errno);
    }

    for (size_t counter = 0; counter < data.nline; counter++)
    {
        fprintf(output, "%s\n", *(ptr_to_nline + counter));
    }

    fclose(output);
}

size_t Buffer_Size()
{
    struct stat buff;

    stat("onegin.txt", &buff);

    return (buff.st_size + 1);       // размер файла в байтах
}

void Reading_From_File(Text* data)
{
    data->buffer = (char*)calloc(data->sizebuf, sizeof(char));

    FILE* input = fopen("onegin.txt", "rb");
    if (input == NULL)
    {
        perror("ERROR:");
        exit(errno);
    }

    fread(data->buffer, sizeof(char), data->sizebuf, input); // копирование текста из файла в buffer

    fclose(input);
}

void Splitting_Into_Lines(Text* data)
{
    size_t size_text = 0;
    for (size_t counter = 0; counter < data->sizebuf; counter++)
    {
        if (*(data->buffer + counter) == '\r')
        {
            *(data->buffer + counter) = '\0';
        }

        if (*(data->buffer + counter) == '\n')
        {
            size_text++;
        }
    }

    data->text = (char**)calloc(size_text + 1, sizeof(char*));

    *(data->text + 0) = data->buffer + 0;

    for (size_t counter = 0; counter < data->sizebuf; counter++)
    {
        if (*(data->buffer + counter) == '\n')
        {
            *(data->buffer + counter) = '\0';
            *(data->text + data->nline) = data->buffer + counter + 1;
            (data->nline)++;
        }
    }
}

bool IsAlpha(int arg)
{
    if (('A' <= arg) && ('Z' <= 90))
        return 1;
    else
        return 0;
}


void DestroyStruct(Text* data)
{
    data -> nline = 0;
    data -> sizebuf = 0;
    free(data -> text);
    free(data -> buffer);
}
