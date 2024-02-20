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

void blue()
{

    printf("\033[0;34m");
}

void green() 
{
    printf("\033[0;32m");
}

void reset()
{

     printf("\033[0m");
}

char **splitArgument(char *str)
{
    // str = cp file file file
    //[cp,file,file,file,NULL]
    char *subStr;
    int size = 2;
    int index = 0;
    subStr = strtok(str, " ");
    char **argumnts = (char **)malloc(size * sizeof(char *));
    *(argumnts + index) = subStr;
    while ((subStr = strtok(NULL, " ")) != NULL)
    {
        size++;
        index++;
        *(argumnts + index) = subStr;
        argumnts = (char **)realloc(argumnts,size * sizeof(char *));
    }
    *(argumnts + (index+1)) = NULL;

    return argumnts;
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

void echo(char **arg)
{
    while (*(++arg)) // this while starts with index 1, after echo string and runs till NULL printing the echo string.
    {
        printf("%s ",*arg);
    }
    puts("");

    // int i = 1;  // anothe example of while, it takes more resources because of int i.
    // while(arg[i]!=NULL)
    //     printf("%s ",arg[i++]);
    
}

void getPcUsername()
{
    char* username = getenv("USER");
    if(!username)
    {
        username = getenv("LOGNAME");
    }

    if (username) 
    {
        green();
        printf("%s@%s", username,username);
    } 
    else 
    {
        printf("Username could not be determined.\n");
    }
}
