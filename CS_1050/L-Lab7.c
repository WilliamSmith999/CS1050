#include <stdio.h>
#include <stdlib.h>

#define s scanf
#define p printf
#define R rand()
#define MAX  100

void bonus(int[]);
void LoadArray(int [][MAX],int);
void PrintArray(int[][MAX],int);
int UserInput(void);
int ErrorChecker(int a, int b);
void RinseWashRepeat(void);
float Mean(int a[][MAX], int c,  int f);
int MaxNum(int a[][MAX], int c,  int f);
int NumberCount(int a[][MAX], int f);
void AddN(int a[][MAX], int f);
//int length(char s[]);
//void copy(char s[], char s1[]);
//char UserInputS();

int main()
{
RinseWashRepeat();
return 0;
}

void RinseWashRepeat(void)
{
//char s[MAX] = {};
//char s1[MAX] = {};
int Array[MAX][MAX] = {{0},{0}};
int ArrayCode = 1;
int ColCode = 2;
int UserIn = 0;
int UserInCheck = 0;
p("\nPlease Choose length, between 1-100: ");
while (ErrorChecker(UserIn = UserInput(), ArrayCode) == 0)
{p("\nI'm sorry user, I'm afraid I can't do that... Between 1 and 100: ");}
UserIn = UserIn - 1;
LoadArray(Array, UserIn);
PrintArray(Array, UserIn);
p("\nPlease enter desired index: ");
while (ErrorChecker(UserInCheck = UserInput(), ColCode) == 0)
{p("\nI'm sorry user, I'm afraid I can't do that...");}
UserInCheck = UserInCheck - 1;
p("\nAverage Of The Number in this Column is: %.2f", Mean(Array, UserInCheck, UserIn));
p("\nBiggest Number In the column is: %d", MaxNum(Array, UserInCheck, UserIn));
p("\nNumber Of Zeros In The Array: %d", NumberCount(Array,UserIn ));
p("\nNew Matrix: \n\n");
AddN(Array, UserIn);
/*p("\n\nEnter A String: ");
s = UserInputS();
p("\nThe length of the string is: ", length(s));
copy(s);*/
}
/*
char UserInputS()
{
char s[MAX];
s("%s", s);
return s[MAX];
}
*/

int ErrorChecker(int a, int b)
{
int ErrorCode = 0;
if (b == 1)
{
if (a >= 1 && a <=100)
{ErrorCode = 1;}
else
{ErrorCode = 0;}
}
if(b==2)
{
if (a >= 1 && a <= 5)
{ErrorCode = 1;}
else
{ErrorCode = 0;}
}
return ErrorCode;
}
int UserInput(void)
{
int input = 0;
s("%d", &input);
return input;
}
void LoadArray(int a[][MAX],int b)
{
int ColCount = 0;
int counter = 0;
for (counter = 0; counter <= b; counter++)
{	for(ColCount =0; ColCount < MAX; ColCount++)
	{
	a[counter][ColCount] = (R%10);
	}
} 
}
int MaxNum(int a[][MAX], int c,  int f)
{
int Temp = 0, Rem = 0, Big = 0;
for (Temp = 0; Temp <=  f; Temp++ )
	{
	Rem =  a[Temp][c];
	if(Rem > Big)
	{
	Big = Rem;;
	}
	}
return Big;
}

int NumberCount(int a[][MAX], int f)
{
int colcount = 0;
int matches = 0;
int counter = 0;
for (counter = 0; counter <= f; counter++)
{
for(colcount = 0; colcount < 5; colcount++)
{if (a[counter][colcount] == 0)
{
matches++;
}
}
}
return matches;
}

float Mean(int a[][MAX], int c,  int f)
{
float subtotal = 0;
float temp = 0;
float  VarAssit = 0;
VarAssit = (float)f + 1;
float total = 0;
int counter = 0;
for (counter = 0; counter  <= f; counter++)
{
temp = a[counter][c];
subtotal = temp + subtotal;
}
total = subtotal / VarAssit;
return total;
}

void AddN(int a[][MAX], int f)
{
int temp = 0;
int ColCount = 0;
int counter = 0;
for (counter  = 0; counter  <= f; counter++)
{	
	for(ColCount = 0; ColCount < 5; ColCount++)
	{
	temp = a[counter][ColCount] + temp;
	}
	a[counter][4] = temp;
	temp = 0;
}
PrintArray(a, f);
}

void PrintArray(int a[][MAX], int f)
{
int ColCount = 0;
int counter = 0;
for (counter  = 0; counter  <= f; counter++)
{	
	for(ColCount = 0; ColCount < 5; ColCount++)
	{p("%3d", a[counter][ColCount]);}
p("\n");
}
p("\n");
}
/*
int length(char* s[])
{
int counter = 0;
int len = 0;
while (s[counter] != '\0')
{len++;
counter++;
}
return len;
}

void copy(char s[], char s1[])
{
int counter = 0;
while (s[counter] != '\0')
{
s1[counter] = s[counter];
counter++;
}
p("\nThe copy of %s is equal to %s", s, s1);
}
*/
