#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 20
#define PASS 1
#define FAIL 0
#define s scanf
#define p printf



int CheckStudentNum(char A[]);
// Error Check: Only allows didgits and between 6-8 characters

int Length(char A[]);
// Returns length of A[]

int CheckStudLength(char A[]);
// check length 6-8

int CheckUpperCase(char A[]);
// Error Check: MUST find one uppercase 

int CheckDigit(char A[]);
// Error Check: MUST finde one digit

int CheckPassLength(char A[]);
// Error Check: Enforce password length

int CheckSpecialChar(char A[]);
// Error Check: Enforce special characters

int String_Compare(char A[], char B[]);
// Error Check: Compair two strings, same Pass different Fail

int Replace(char S[], int I);
// Replace char at I with #

int IDValidation(char A[]);
// validator

int PassValidation(char A[]);

int main()
{
char ID[MAX];
char Pass[MAX];
char stringone[MAX];
char stringtwo[MAX];
int Aid = 0;
p("\nPlease enter student ID: ");
s("%s", ID);
while(IDValidation(ID) == FAIL)
{
p("\nPlease enter student ID: ");
s("%s", ID);
}	

p("\nPlease enter student Password: ");
s("%s", Pass);
while(PassValidation(Pass) == FAIL)
{
p("\nPlease enter student Password: ");
s("%s", Pass);
}

p("\nCongrates account created: \nID: %s\nPassword: %s\n", ID, Pass);
p("\nEnter string one: ");
s("%s", stringone);
p("\nEnter string two: ");
s("%s", stringtwo);

Aid = String_Compare(stringone, stringtwo);
if(Aid == 1){p("%s is bigger then %s", stringone, stringtwo);}
	else
		if(Aid == 2){p("%s is bigger then %s", stringtwo, stringone);}
			else
				if(Aid == 0){p("%s is the same size as %s", stringone, stringtwo);}


p("\nGoodbye\n");
	
	
return (0);
}

int String_Compare(char A[], char B[])
{
	int temp1, temp2, i, j, State = 0;
	while(A[i] != '\0')
	{
		temp1 = A[i] + temp1;
		i++;
	}
	while(B[j] != '\0')
	{
		temp2 = B[j] + temp2;
		j++;
	}
	
	if(temp1 > temp2){State = 1;}
	if(temp1 < temp2){State = 2;}
	if(temp1 == temp2){State = 0;}
	
	return State;
}


int PassValidation(char A[])
{
	int State = 1;
	
	if(CheckPassLength(A) == FAIL){p("\nError: Between 6- 10 Characters\n");}
	if(CheckSpecialChar(A) == FAIL){p("\nError: Needs special character\n");}
	if(CheckDigit(A) == FAIL){p("\nError: Needs a digit\n");}
	if(CheckUpperCase(A) == FAIL){p("\nError: Needs an uppercase letter\n");}
	if(CheckPassLength(A) == FAIL && CheckSpecialChar(A) == FAIL){State = FAIL;}
	if(CheckDigit(A) == FAIL && CheckUpperCase(A) == FAIL){State = FAIL;}
	return State;
}

int IDValidation(char A[])
{
	int State = 1;
	if (CheckStudLength(A) == FAIL && CheckStudentNum(A) == FAIL){State = FAIL;}
	if (CheckStudLength(A) == FAIL){p("\nError: must be between 6 and 8 characters\n");}
	if (CheckStudentNum(A) == FAIL){p("\nError: must be only numbers\n");}
	return State;
}

int CheckStudLength(char A[])
{
	int State, counter, i = 0;
	while (A[i] != '\0')
	{
	i++;	
	counter++;
	}
	if (counter > 8 || counter < 6){State = FAIL;}
	if (counter < 9 || counter > 5){State = PASS;}
	return State;
}

int CheckStudentNum (char A[])
{
	int State = 3;
	int i = 0;
	
	while (A[i] != '\0')
	{
	if (!isdigit(A[i])){State = FAIL;}
	i++;
	}
	
	return State;
}

int CheckDigit(char A[])
{
	int State = 3;
	int i = 0;
	
	while (A[i] != '\0')
	{
	if (isdigit(A[i])){State = PASS;}
	i++;
	}
	
	return State;
}

int CheckUpperCase(char A[])
{
	int State = 3;
	int i = 0;
	
	while (A[i] != '\0')
	{
	if (isupper(A[i])){State = PASS;}
	i++;
	}
	
	return State;
	
}

int CheckSpecialChar(char A[])
{
	int State = 3;
	int i = 0;
	
	while (A[i] != '\0')
	{
	if (ispunct(A[i])){State = PASS;}
	i++;
	}
	
	return State;
}

int CheckPassLength(char A[])
{
	int State, counter, i = 0;
	while (A[i] != '\0')
	{
	i++;	
	counter++;
	}
	if (counter > 10 || counter < 6){State = FAIL;}
	if (counter < 11 || counter > 5){State = PASS;}
	return State;
}
