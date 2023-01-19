#include <stdio.h>
#include <string.h>
#include <ctype.h> 

/*
    Remove comment if you want debug prints
*/
//#define _DEBUG

static char In_Str[100];// = "5-8+2*6-5*6+7/6-4+8+5";
static float Result=0;
static float Arr_Val_Sym[30] = {0};
static float Dup_Arr_Val[30] = {0};
static char Sym_Arr[30] = {0};

void PrintArray(float *tmp)
{
    for(int i=0;i<strlen(In_Str);i++)
    {
        printf("%d\t%f\n",i,tmp[i]);
    }
}

void Division(float x, float y)
{
#ifdef _DEBUG
    printf("x = %f\ty = %f\n",x,y);
#endif
    if(x >= y)
        Result = (x) / (y);
    else if(x < y)
        Result = (y) / (x);
}

void Multiplication(float x, float y)
{
#ifdef _DEBUG
    printf("x = %f\ty = %f\n",x,y);
#endif
    Result = (x) * (y);
}

/*
    In this function removed all zeros from the array

*/
void RmZeros(float *tmp)
{
    int i=0,j=0;
    float temp[30]={0};
    for(i=0;i<strlen(In_Str);i++)
    {
        if(tmp[i] != 0)
        {
            temp[j] = tmp[i];
            j++;
        }
    }
    for(i=0;i<strlen(In_Str);i++)
    {
        tmp[i] = temp[i];
    }
}

/*
    In CalculationFun function all calculations are done.
    By comparing with operator called respective function (Multiplication, Division) 
Because these are high priority operators.
    For Addition and Subtraction Added those symbols into new array (Sym_Arr)
    At the end Addition and Subtraction are done by using Sym_Arr array.
*/
void CalculationFun()
{
    int i=0, j=0, k=0;
    for(i=1;i<strlen(In_Str);i+=2)
    {
        if(Arr_Val_Sym[i] == 43 || Arr_Val_Sym[i] == 45)
        {
            Sym_Arr[k] = Arr_Val_Sym[i]; 
            printf("%c\n",Sym_Arr[k]);   
            k++;
        }
        else if(Arr_Val_Sym[i] == 42)
        {
            Multiplication(Dup_Arr_Val[i-1],Dup_Arr_Val[i+1]);
            Dup_Arr_Val[i-1] = 0;
            Dup_Arr_Val[i+1] = Result;
        }
        else if(Arr_Val_Sym[i] == 47)
        {
            Division(Dup_Arr_Val[i-1],Dup_Arr_Val[i+1]);
            Dup_Arr_Val[i-1] = 0;
            Dup_Arr_Val[i+1] = Result;
        }
    }
#ifdef _DEBUG
    printf("Result = %f\ti = %d\n",Result,i);
    puts(Sym_Arr);
    PrintArray(Dup_Arr_Val);
#endif
    RmZeros(Dup_Arr_Val);
    Result =0;

    Result = Dup_Arr_Val[0];
    for(int i=0,j=0;i<strlen(Sym_Arr);i++)
    {
        if(Sym_Arr[i] == 43)
        {
            Result += Dup_Arr_Val[j+1];
            j++;
        }
        else if(Sym_Arr[i] == 45)
        {
            Result -= Dup_Arr_Val[j+1];
            j++;
        }
    }
}

/*
    In this FillArray function two arrays are used (Arr_Val_Sym, Dup_Arr_Val)
    By converting from string (ASCII) to Decimal values 
    In Arr_Val_Sym array, integer values and operators are stored at respective indexes,
    In Dup_Arr_Val array, only integer values are stored at respective indexes.

*/
void FillArray()
{
    int OutLoop=0, InLoop=0, Index=0, DeciCount=1;
    float CalNum=0;

    for(OutLoop=0;OutLoop<strlen(In_Str);OutLoop++)
    {
        DeciCount=1;
        if(isdigit(In_Str[OutLoop]))
        {
            InLoop=OutLoop;
            while(isdigit(In_Str[InLoop]) || (In_Str[InLoop] == '.') )
            {
                if(In_Str[InLoop] == '.')
                {
                    InLoop++;
                    while(isdigit(In_Str[InLoop]))
                    {
                        CalNum *= 10;
                        DeciCount *= 10;
                        CalNum += In_Str[InLoop] - 48;
                        InLoop++;
                    }
                    break;
                }
                else
                {
                    CalNum *= 10;
                    CalNum += (In_Str[InLoop] - 48);
                    InLoop++;
                }
            }
            CalNum /= ((DeciCount));
#ifdef _DEBUG
            printf("CalNum = %f\t%d\n",CalNum,InLoop);
#endif
            OutLoop = InLoop-1;
            Arr_Val_Sym[Index] = CalNum;
            Dup_Arr_Val[Index] = CalNum;
            Index++;
            CalNum=0;
        }
        else
        {
            Arr_Val_Sym[Index] = In_Str[OutLoop];
            Index++;
        }
    }
}

int main()
{
    puts("Enter Data");
    scanf("%s",In_Str);
    FillArray();

#ifdef _DEBUG
    PrintArray(Dup_Arr_Val);
#endif
    CalculationFun();
#ifdef _DEBUG
    PrintArray(Dup_Arr_Val);
#endif

    printf("Result = %f\n",Result);
    return 0;
}
