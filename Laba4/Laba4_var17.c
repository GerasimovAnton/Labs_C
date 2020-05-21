#include <stdio.h>
#include <stdlib.h>


void deleteEl(int *arr,int size,int indx);
int deleteChars(char *str,int size,int start,int finish);

int main()
{
    int strSize = 0;
    char str[80], ch;

    printf("\nThis program removes all characters between brackets\n");
    puts("\nenter string of chars: ");
    while ((ch = getchar()) != '\n') {
        str[strSize++] = ch;
    }

    int start = -1;
    int sCount = 0;
    int finish = -1;

    int oBCount = 0,cBCount = 0;

    for (size_t j = 0; j < strSize; j++)
    {
        if(str[j] == ')') oBCount ++;
        if(str[j] == '(' && sCount == 0){
            start = j;
            sCount++;
        } else if(str[j] == '(' && sCount > 0){
            sCount++;
        }

        if(str[j] == ')') cBCount ++;
        if(str[j] == ')' && sCount == 1){
            finish = j;
            sCount--;
        }  else if(str[j] == ')' && sCount >  1){
            sCount--;
        }
        

        if(start != -1 && finish != -1)
        {
            int s = deleteChars(str,strSize,start,finish);
            j -= (strSize - s);
            strSize = s;

            start = -1;
            finish = -1;
            sCount = 0;
        }
    }

    if(oBCount != cBCount)
    {
        printf("ERROR: The number of opening brackets does not match the number of closing brackets!\n");
    }

    str[strSize] = '\0';
    printf("%s",str);

    printf("\nPress any key to exit the program...");
    getchar();
}


int deleteChars(char *str,int size,int start,int finish)
{
    int newSize = 0;
    for (size_t i = 0,p = 0; i < size; i++)
    {
        if(i > start && i < finish && !(str[i] == '(' || str[i] == ')')) continue;
        str[newSize++] = str[i];
    }

    return newSize;
}