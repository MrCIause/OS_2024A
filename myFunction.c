#include "myFunction.h"

char *getInputFromUser()
{
    char ch;
    int size = 1;
    int index = 0;

    char *str = (char *)malloc(size* sizeof(char));
    puts("Enter strings:");
    while((ch = getchar()) != '\n')
    {
        *(str+index) = ch;
        size++;
        index++;
        str = (char *)realloc(str, size * sizeof(char));
    }
    *(str+index) = '\0';
    return str;
}
void blue(){

    printf("\033[0;34m");
}
void reset(){

     printf("\033[0m");
}

void getLocation()
{
    char location[BUFF_SIZE];

    if (getcwd(location, BUFF_SIZE) == NULL)
    {
        puts("Error");
    }
    else
    {
        blue();
        puts(location);
        reset();
    }
}

void logout(char *input)
{
    free(input); // gets input frees it.
    puts("log out"); // prints log out.
    exit(EXIT_SUCCESS); // EXIT_SUCCESS = 0, exit without interruptions.
}