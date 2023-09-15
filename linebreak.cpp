#include "linebreak.h"


void Print_Pointer(char** ptr_to_nline, TEXT data)
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

TEXT Reading_From_File(TEXT data)
{
    data.buffer = (char*)calloc(data.sizebuf, sizeof(char));

    FILE* input = fopen("onegin.txt", "r");
    if (input == NULL)
    {
        perror("ERROR:");
        exit(errno);
    }

    fread((data.buffer), sizeof(char), (data.sizebuf), input); // копирование текста из файла в buffer

    fclose(input);
    return data;
}

TEXT Splitting_Into_Lines(TEXT data)
{
    size_t size_text = 0;
    for (size_t counter = 0; counter < data.sizebuf; counter++)
    {
        if (*(data.buffer + counter) == '\r')
        {
            *(data.buffer + counter) = '\0';
        }

        if (*(data.buffer + counter) == '\n')
        {
            size_text ++;
        }
        else
        {
            *(data.buffer + counter) = toupper(*(data.buffer + counter));
        }
    }

    data.text = (char**)calloc(size_text + 1, sizeof(char*));

    *(data.text + 0) = data.buffer + 0;

    for(size_t counter = 0; counter < data.sizebuf; counter++)
    {
        if(*(data.buffer + counter) == '\n')
        {
            *(data.buffer + counter) = '\0';
            *(data.text + data.nline) = data.buffer + counter + 1;
            data.nline++;
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


void DestroyStruct(TEXT* data)
{
    data -> nline = 0;
    data -> sizebuf = 0;
    free(data -> text);
    free(data -> buffer);
}
