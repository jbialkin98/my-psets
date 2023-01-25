#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char name[128];
    
    if (argc == 2)
    {
        printf("Hello, %s\n", argv[1]);
    }
    else
    {
        printf("What is your name? ");
        while (scanf("%s", name) > 0)
        {
            printf("Hello, %s\n", name);
            return 0;
        }
    }
    return 0;
}