#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char name[129];
    
    if (argc == 2)
    {
        printf("Hello, %s\n", argv[1]);
    }
    else
    {
        printf("What is your name? ");
        scanf("%[^\n]s", name);
        printf("Hello, %s\n", name);
    }
    return 0;
}