#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv[]) 
{
    // File opening stuff

    char data[MB_LEN_MAX];
    FILE *fptr;

    if ((fptr = fopen((const char * restrict)argv[1], "r")) == NULL)
    {
        printf("Error! File cannot be opened.");
        exit(1);
    }

    fscanf(fptr, "%[^\n]", data);

    // Main code

    int num;
    int doPrint = 0;

    for(int i = 0; i <= strlen(data); i++)
    {
        if(data[i] == '+')
        {
            num++;
        }
        if(data[i] == '-')
        {
            num--;
        }
        if(data[i] == '|')
        {
            doPrint++;
        }
    }
    if(doPrint <= 1)
    {
        printf("%d", num);
    }

    // Ending

    fclose(fptr);

    return 0;
}