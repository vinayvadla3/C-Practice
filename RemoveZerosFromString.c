/*
  Program to remove all zeros form given input string
  
  Author:- VinayVadla
  Email:- vadlavinay3gmail.com
*/

#include <stdio.h>
#include <string.h>

/*
	This function removes zeros from input given string
*/
void RmLdngZeros(char *ptr)
{
    int i=0;
    for(i=0;i<strlen(ptr);i++)
    {
        if(ptr[i] == '0')
        {
            memmove(ptr+i, ptr+i+1, strlen(ptr)+1);
            i--;
        }
    }
}

int main()
{
    char str[] = "0000000001234";
    puts(str);
    
    RmLdngZeros(str);
    puts(str);
    
    return 0;
}
