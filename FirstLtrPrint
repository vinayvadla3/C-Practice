/*
  Program to Print first letter of every word in given string
  
  Author:- VinayVadla
  Email:- vadlavinay3@gmail.com
*/

#include <stdio.h>
#include <string.h>

/*
	This function print First letter of every word in given string
*/
void FstLtr(char *ptr)
{
    int i=0;
    for(i=0;i<strlen(ptr);i++)
    {
        if( (i==0) && (isalpha(ptr[i])) )
        {
            printf("%c\n",ptr[i]);
        }
        else if( (ptr[i] == ' ') || (ptr[i] == '\n'))
        {
            printf("%c\n",ptr[i+1]);
        }
    }
}

int main()
{
    char str[] = "Geeks for Geeks Vinay";
    puts(str);
    
    FstLtr(str);
    puts(str);
    
    return 0;
}
