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

//char** Line_Sorting(char** text, size_t nline);

TEXT Splitting_Into_Lines(TEXT data);
TEXT recalloc(TEXT data, size_t numRealloc);
size_t Buffer_Size();
TEXT Reading_From_File(TEXT data);
TEXT BubbleSort(TEXT data);
int Strcmp(char* arg1, char* argv2);
void Swap_Pointer(char** arg1, char** arg2);
void Print_Pointer(TEXT data);

void DestroyStruct(TEXT* data);


int main()
{
    struct TEXT data = {.nline = 1, .text = 0, .sizebuf = Buffer_Size(), .buffer = 0};
    data = Reading_From_File(data);
    data = Splitting_Into_Lines(data);




    Print_Pointer(data);
    printf("\n\n\n");
    data = BubbleSort(data);

    Print_Pointer(data);

    DestroyStruct(&data);
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
/*
TEXT Splitting_Into_Lines(TEXT data)
{
    printf("ab\n");
    data = Structure_Creation(data);
    printf("adress text : %p \n", data.text);
    size_t symbols = 0;    // количество символов в файле
    size_t numRealloc = 1; // количество строк в файле
    *(data.text) = data.buffer;

    while (symbols < data.sizebuf)
    {
        if (*(data.buffer + symbols) == '\r')
        {
            *(data.buffer + symbols) = '\0';
        }
        if ((*(data.buffer + symbols) == '\n'))
        {
            //printf("aboba %d\n", symbols);//
            //printf("blyat %d\n", data.nline); //
            *(data.buffer + symbols) = '\0';
            *(data.text + data.nline) = data.buffer + symbols + 1; //указателю присваивается адрес символа новой строчки
            if (data.nline == numRealloc * SIZE_TEXT)
            {
                numRealloc = numRealloc + 1;
                //dataSize *= 2;
                data = recalloc(data, numRealloc);
            }

            (data.nline)++;
        }
        else
        {
            *(data.buffer + symbols) = toupper(*(data.buffer + symbols));
        }
        symbols++;
    }
    //data.text = (char**)realloc(data.text, data.nline);

    printf("all characters = %d\nall lines = %d\n", symbols, data.nline);
    //printf("%d\n",data.nline);
    Print_Pointer(data);
    //printf("text of file:\n%s", buffer + 10); проверка на заглавные буквы
    //printf("text of file:\n%s", *(data.text + 21));// еще одна проверка)
    return data;
}

*/

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


TEXT qSort(TEXT data)
{
    for (size_t outpass = 0; outpass < data.nline - 1; outpass++)
    {
        for (size_t inpass = 0; inpass < data.nline - 1 - outpass; inpass++)
        {
            char* left = *(data.text + inpass)
        }

}
TEXT BubbleSort(TEXT data)
{
    for (size_t outpass = 0; outpass < data.nline - 1; outpass++)
    {
        for (size_t inpass = 0; inpass < data.nline - 1 - outpass; inpass++)
        {
            if (Strcmp(data.text[inpass], data.text[1 + inpass]) > 0)
            {
                Swap_Pointer(data.text + inpass, data.text + 1 + inpass);
            }
        }
    }
    return data;
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

int Strcmp(char* arg1, char* arg2)
{
    assert(arg1);
    assert(arg2);

    while (*arg1)
    {
        if (!isupper(*arg1))
        {
            arg1++;
        }
        if (!isupper(*arg2))
        {
            arg2++;
        }

        if (*arg1 != *arg2)
        {
            break;
        }
        arg1++;
        arg2++;
    }

    return *(const unsigned char*)arg1 - *(const unsigned char*)arg2;
}

void Swap_Pointer(char** arg1, char** arg2)
{
    assert(arg1);
    assert(arg2);

    char* tmp = {};
    tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
    /*tmp = data.text[inpass];
    data.text[inpass] = data.text[inpass + 1];
    data.text[inpass + 1] = tmp;*/
}

void Print_Pointer(TEXT data)
{
    FILE* output = fopen("oneginOut.txt", "w");
    if (output == NULL)
    {
        perror("ERROR:");
        exit(errno);
    }
    fprintf(output, "!!!!!\n");
    for (size_t counter = 0; counter < data.nline; counter++)
    {
        fprintf(output, "line %2d : %s\n", counter + 1, data.text[counter]);
    }
    fclose(output);
}

void DestroyStruct(TEXT* data)
{
    data -> nline = 0;
    data -> sizebuf = 0;
    free(data -> text);
    free(data -> buffer);
}

void qsort(int array[], int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = array[(left + right) / 2];
        do
        {
            while (array[left] < middle)
                left++;
            while (array[right] > middle)
                right--;
            if (left <= right)
            {
                Swap(array, left, right);
                left++;
                right--;
            }
        } while (left <= right);
        printf("l = %d, r = %d\n", left, right);
        qsort(array, first, right);
        qsort(array, left, last);
    }
}
