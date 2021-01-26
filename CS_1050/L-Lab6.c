#include <stdio.h>
#include <stdlib.h>

#define s scanf
#define p printf
#define R rand()
#define ASize 100

void bonus(int[]);
void LoadArray(int[],int);
void PrintArray(int[],int);
int UserInput(void);
int ErrorChecker(int a);
void RinseWashRepeat(void);
float Mean(int a[], int f);
int MinNum(int a[], int f);
int MaxNum(int a[], int f);
int CommonNumbers (int a[], int b[], int f);
int NumberCount(int a[], int f, int g);

int main()
{
RinseWashRepeat();
return 0;
}

void RinseWashRepeat(void)
{
int ArrayOne [ASize] = {0};
int ArrayTwo [ASize] = {0};
int UserIn = 0;
int UserInCheck = 0;
p("\nPlease Choose length, between 1-100: ");
while (ErrorChecker(UserIn = UserInput()) == 0)
{p("\nI'm sorry user, I'm afraid I can't do that... Between 1 and 100: ");}
UserIn = UserIn - 1;
LoadArray(ArrayOne, UserIn);
LoadArray(ArrayTwo, UserIn);
p("\nThe first array...\n");
PrintArray(ArrayOne, UserIn);
p("\nThe max number in the array is at index: %d", MaxNum(ArrayOne, UserIn));
p("\nThe min number in the array is at index: %d",MinNum(ArrayOne, UserIn));
p("\nAverage of all numbers int the first array is: %.2f\n", Mean(ArrayOne,UserIn));
PrintArray(ArrayTwo, UserIn);
p("\nThe max number in the array is at index: %d", MaxNum(ArrayTwo, UserIn));
p("\nThe min number in the array is at index: %d",MinNum(ArrayTwo, UserIn));
p("\nAverage of all numbers int the first array is: %.2f", Mean(ArrayTwo,UserIn));
p("\nPlease enter desired index: ");
while (ErrorChecker(UserInCheck = UserInput()) == 0)
{p("\nI'm sorry user, I'm afraid I can't do that...");} 
p("\nThe count of number %d in the first array is: %d", UserInCheck, NumberCount(ArrayOne, UserIn, UserInCheck));
p("\nThe count of number %d in the second array is: %d", UserInCheck, NumberCount(ArrayTwo, UserIn, UserInCheck));
p("\nThe number of number that have the same value at the same index is: %d\n", CommonNumbers(ArrayOne, ArrayTwo, UserIn));
}


int ErrorChecker(int a)
{
int ErrorCode = 0;
if (a >= 1 && a <=100)
{ErrorCode = 1;}
else
{ErrorCode = 0;}
return ErrorCode;
}
int UserInput(void)
{
int input = 0;
s("%d", &input);
return input;
}
void LoadArray(int a[],int b)
{
int counter = 0;
for (counter = 0; counter <= b; counter++)
{a[counter] = (R%10);} 
}
int MinNum(int a[], int f)
{
int Temp = 0, Rem = 0, Little = 0, LittleIndex = 0;
for (Temp = 0; Temp <= f; Temp++ )
	{
	Rem =  a[Temp];
	if(Rem < Little)
	{
	Little = Rem;
	LittleIndex = Temp;
	}
	}
return LittleIndex;
}
int MaxNum(int a[], int f)
{
int Temp = 0, Rem = 0, Big = 0, BigIndex = 0;
for (Temp = 0; Temp <= f; Temp++ )
	{
	Rem =  a[Temp];
	if(Rem > Big)
	{
	Big = Rem;
	BigIndex = Temp;
	}
	}
return BigIndex;
}

int NumberCount(int a[], int f, int g)
{
int matches = 0;
int counter = 0;
for (counter = 0; counter <= f; counter++)
{
if (a[counter] == g)
{
matches++;
}
}
return matches;
}

float Mean(int a[], int f)
{
float subtotal = 0;
float temp = 0;
int VarAssit = 0;
VarAssit = f + 1;
float total = 0;
int counter = 0;
for (counter = 0; counter <= f; counter++)
{
temp = (float) a[counter];
subtotal = subtotal + temp;
total = ((float)subtotal/VarAssit);
}
return total;
}

int CommonNumbers(int a[], int b[], int f)
{
int NumNums = 0;
int counter = 0;
for (counter = 0; counter <= f; counter++)
{
int madness = a[counter];
int thisis = b[counter];
if (thisis == madness)
{NumNums++;}
else
{}
}
return NumNums;
}

void PrintArray(int a[], int f)
{
int counter = 0;
for (counter = 0; counter <= f; counter++)
{
p(" %d", a[counter]);
}
p("\n");
}

