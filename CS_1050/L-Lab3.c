#include <stdio.h>
#include <math.h>

float ExtractIntrest (float a, float b);
void bonus ();
float IntrestEstimate(float z, int x, int y);
void RinseWashRepeat();
float PrincipalAmountValidation(float z);
int AccountTypeValidation(int x);
int YearValidation(int y);
int  main()
{
	int repeatsentval = 1;
	while ( repeatsentval == 1)
	{
	RinseWashRepeat();
	printf("Any further entries?\n1 for yes 0 for no\n");
	scanf("%d", &repeatsentval);
	}
	bonus();
	return 0;
}

int AccountTypeValidation(int x)
{
		while (x != 1 && x != 2 && x != 3)
	{
		printf("\nError: Invalid Imput.\nPlease try again.\n1.) Checking\n2.) Savings\n3.) Fixed Deposit\n\n");
		printf("\nChoose account type: ");
		scanf("%d", &x);
	}
	return x;
}

int YearValidation(int y)
{
		while (y <= 0 || y > 10 )
	{
		printf("\nError: Invalid Imput.\nPlease try again.\nYear must be 1 - 10");
		printf("\nInput valid year: ");
		scanf("%d", &y);
	}
	return y;
}

float PrincipalAmountValidation(float z)
{
		while (z < 0)
	{
		printf("\nError: Invalid Imput.\nPlease try again.\nAmount must be positive");
		printf("\nEnter valid amount: $");
		scanf("%f", &z);
	}
	return z;
}

float IntrestEstimate(float z, int x, int y)
{
	int rate = 0;
	float total = 0;
	
	switch(x)
	{
		case 1:
		rate = 1;
		break;
		case 2:
		rate = 3;
		break;
		case 3:
		rate = 7;
		break;
	}

	total = z * (float) pow((float)(1+((float)rate/100)),y);
	return total;
}

float ExtractIntrest(float a, float b)
{
	float interest = 0;
	interest = a - b;
	return interest;
}

void RinseWashRepeat()
{
	float EstInt = 0; //Extracted intrest
	float IntEst = 0; //interest estimated
	float PrincipalAmount = (-1);
	int YearToDate = 0;
	int AccTypeCode = 0;
	printf("\n1.) Checking\n2.) Savings\n3.) Fixed Deposit\n");
	printf("\nPlease enter account type by associated number: ");	
	scanf("%d", &AccTypeCode);
	AccTypeCode = AccountTypeValidation(AccTypeCode);
	printf("\nPlease enter years since investment: ");
	scanf("%d", &YearToDate);
	YearToDate = YearValidation(YearToDate);
	printf("\nPlease enter the principal amount: $");
	scanf("%f", &PrincipalAmount);
	PrincipalAmount = PrincipalAmountValidation(PrincipalAmount);
	IntEst = IntrestEstimate(PrincipalAmount, AccTypeCode, YearToDate);
	printf("after %d year(s) predicted amount is $%.2f\n", YearToDate, IntEst);
	EstInt = ExtractIntrest(IntEst,PrincipalAmount);
	printf("after %d year(s) predicted amount of interest on $%.2f is $%.2f\n", YearToDate, IntEst,EstInt );
}

void  bonus()
{
	double x = 0;
	double y = 0;
	double total = 0;
	printf("\nBonus Part\n");

	printf("\nEnter a number: ");
	scanf("%lf", &x);
	printf("\nEnter an exponent: ");
	scanf("%lf", &y);
	total = pow(x,y);

	printf("pow( %lf , %lf ) = %lf\n", x, y, total);

}
