/*
  C Program to Check if String is Pangram
  A pangram is a sentence containing every letter in the English Alphabet.
  
  Author:- VinayVadla
  Email:- vadlavinay3@gmail.com
*/

#include <stdio.h>
#include <string.h>

/*
	This function remove repeated characters in given string
*/
void RmRptCh(char *ptr)
{
    int i=0,j=0;
    for(i=0;i<strlen(ptr);i++)
    {
        for(j=i+1;j<strlen(ptr);j++)
        {
            if( !(isalpha(ptr[i])) )
            {
                memmove(ptr+i,ptr+i+1,strlen(ptr)+1);
            }
            else if(ptr[i] == ptr[j] )
            {
                memmove(ptr+j,ptr+j+1,strlen(ptr)+1);
                j--;
            }
        }
    }
}

/*
	This Function sort input given string in ascending order
*/
void SortStr(char *ptr)
{
    int i=0,j=0;
    char temp=0;
    for(i=0;i<strlen(ptr);i++)
    {
        for(j=i+1;j<strlen(ptr);j++)
        {
            if( (ptr[i] >= ptr[j]) )
            {
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] =temp;
            }
        }
    }
}

/*
	This function converts Capital letters to Small letters 
*/
void ConvToSmall(char *ptr)
{
    int i=0;
    for(i=0;i<strlen(ptr);i++)
    {
        if('A' <= ptr[i] && ptr[i] <= 'Z')
        {
            ptr[i] += 'a' - 'A';
        }
    }
}

int main()
{
    char str[] = "THE quick brown fox jumps over the LAZY dog";
    puts(str);
    ConvToSmall(str);
    puts(str);
    SortStr(str);
    puts(str);
    RmRptCh(str);
    puts(str);
    strlen(str) == 26 ? puts("yes") : puts("no");
    return 0;
}
