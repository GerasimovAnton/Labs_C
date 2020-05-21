#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int findChar(char c, char* arr, int size);

int main()
{
    setlocale(LC_ALL,"RUS");
 

    char rus[] = { 'А','Б','В','Г','Д','Е','Ж','З','И',
                  'К','Л','М','Н','О','П','Р','С',
                  'Т','У','Ф','Х','Ю' };

    char en[] = { 'A','B','V','G','D','E','J','Z','I',
                  'K','L','M','N','O','P','R','C',
                  'T','Y','F','X','U' };

    int strSize = 0;
    char str[80], ch;

    while ((ch = getchar()) != '\n') {
        str[strSize++] = ch;
    }


    for (size_t i = 0; i < strSize; i++)
    {
        int indx = findChar(toupper(str[i]), en, 22);
        if (indx != -1) str[i] = rus[indx];
    }

    str[strSize] = '\0';
    printf("%s",str);
    getchar();
    return 0;
}

int findChar(char c, char* arr, int size)
{
    for (size_t i = 0; i < size; i++) if (arr[i] == c) return i;
    return -1;
}






