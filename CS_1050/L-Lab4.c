#include <stdio.h>
#include <stdbool.h>
#define p printf
#define s scanf

int ErrorCheck (int a);
int CheckEven (int b);
int CheckPrime (int c);
int ExtremeDigits (int d);
void Validator (int e);
int GetInPut (void);
int SmallLargeTotal(int f);
void Bonus();

int main()
{
int ExTot = 0, SLTot = 0, Base = 0;
Base = GetInPut();
Validator(ErrorCheck(Base));
	while(ErrorCheck(Base) == 0)
	{
	Base =  GetInPut();
	}
if (CheckEven(Base) == 1)
{
p("\n%d is a even number\n", Base);
}
else
{
p("\n%d is an odd number\n", Base);
}

if (CheckPrime(Base) == 1)
{
p("\n%d is a prime number\n", Base);
}
else
{
p("\n%d is NOT a prime number\n", Base);
}

ExTot = ExtremeDigits(Base);
SLTot = SmallLargeTotal(Base);

p("\nSum of the product and sum of the extreme digits of %d is %d\n", Base, ExTot);
p("\nThe sume of the largest and smallest digits in %d is %d\n", Base, SLTot);

Bonus();

return(0);
}

int SmallLargeTotal(int f)
{
int Temp = 0, Rem = 0, SLTot = 0, Big = 0, Little = 0;
Temp = f;
Little = f;

while (f > 0)
	{
	Rem = f % 10;
	if(Rem > Big){Big = Rem;}
	if(Rem < Little){Little = Rem;}
	f = f / 10;
	}

SLTot = Little + Big;

return SLTot;
}

int GetInPut()
{
int Number;
p("\nPlease enter a positive  number: ");
s("%d", &Number);
return Number;
}

int ErrorCheck(int a)
{
	int ErrCheckVal = 0;
	if (a < 0 || a == 0)
	{ErrCheckVal = 0;}
	else
	{ErrCheckVal = 1;}

//	p("\n\n ErrorCheckValue %d\n\n",ErrCheckVal);	

	return ErrCheckVal;
}


int CheckEven(int b)
{
	int EvenCheckVal = 0;
	if ((b % 2) == 0)
	{EvenCheckVal = 1;}
	else
	{EvenCheckVal = 0;}
	return EvenCheckVal;
}


int CheckPrime(int c)
{
int i, flag = 0, PrimCheckVal = 0;
for(i=2;i<=c/2;++i)
{
	if(c%i == 0)
	{
		flag = 1;
		break;
	}
}
if (flag==0)
{
PrimCheckVal = 1;
}
else
{
PrimCheckVal = 0;
}
return PrimCheckVal;
}


int ExtremeDigits (int d)
{
int temp = d, total = 0, Firstnum = 0, Lastnum = 0;
Lastnum = temp%10;
temp = d;
while (temp >= 10)
{
	temp /= 10;
}
Firstnum = temp;
total = ((Firstnum * Lastnum) + (Firstnum + Lastnum));
return total;
}

void Validator(int a)
{
	if(a != 1)
	{
	p("\nError: You must contruct additional pylons\nPlease repeat previous function\n");
	}
	else
	{}
}

void Bonus()
{
int n, reverse = 0, rem, temp;
p("\n***BONUS***\n");
p("\nPlease enter an integer: ");
s("%d", &n);
while(n < 0 || n == 0)
{
n = GetInPut();
}

temp = n;
while(temp!=0)
{
rem = temp%10;
reverse = reverse*10+rem;
temp /= 10;
}
if (reverse == n)
{p("\n%d is a palindrome.\n",n);}
else
{p("\n%d is NOT a palindrome.\n", n);}
}
