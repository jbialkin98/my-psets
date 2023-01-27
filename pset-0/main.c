#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{   
    if (argc == 2)
    {
        printf("Hello, %s\n", argv[1]);
    }
    else
    {
        char name[129];
        printf("What is your name? ");
        if (scanf("%[^\n]s", name) > 0)
        {
            printf("Hello, %s\n", name);
        }
        else
        {
            return 1;
        }
        
    }
    return 0;
}