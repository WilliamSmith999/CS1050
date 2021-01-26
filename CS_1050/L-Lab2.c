 #include <stdio.h>
int main()
{
	int Num1 = (-1);
	int Num2 = (-1);
	int Remainder = 0;
	int AddTot = 0;
	int SubTot = 0;
	int MultiTot = 0;
	double DivTot = 0;
	
	while (Num1 < 0)
	{
	printf("\nPlease enter a positive integer: ");
	scanf("%d", &Num1);
		if (Num1 < 0)
		{printf("\nError positive integers only. Please try again.\n");}
	}
	while (Num2 < 0)
	{
	printf("\nPlease enter a second positive integer: ");
	scanf("%d", &Num2);
		if (Num2 < 0)
		{printf("\nError positive integers only. Please try again.\n");}
	}
	
	printf("\nADDITION\n");
	AddTot = Num1 + Num2;
	printf("%d + %d = %d \n", Num1, Num2, AddTot);

	printf("\nSUBTRACTION\n");
	SubTot= Num1 - Num2;
	printf("%d - %d = %d \n",Num1, Num2, SubTot);

	printf("\nMULTIPLICATION\n");
	MultiTot = Num1 * Num2;
	printf("%d * %d = %d\n", Num1, Num2, MultiTot);

	printf("\nDIVISION\n");
	if(Num2 == 0)
	{
		while  (Num2 == 0 || Num2 < 0)
		{
			printf("Cannot divide by zero, or use negatives new number required: ");
			scanf("%d", &Num2);
		}
	}
	DivTot = (float)  Num1 / (float) Num2;
	printf("%d / %d = %.2f\n\n", Num1, Num2, DivTot);
	Remainder = Num1 % 2;
	if (Remainder  == 0)
	{
		printf("%d",Num1);
		printf(" is even\n");
	}
	else
	{
		printf("%d",Num1);
		printf(" is odd\n");
	}
	
	Remainder = Num2 % 2;
	if (Remainder == 0)
	{	
		printf("%d",Num2);
		printf(" is even\n\n");
	}
	else
	{
		printf("%d", Num2);
		printf(" is odd\n\n");
	}


	if (Num1 > Num2)
	printf("%d is the bigger number\n\n",Num1);
	if (Num2 > Num1)
	printf("%d is the bigger number\n\n",Num2);
	if (Num1 == Num2)
	printf("The number are the same...\n\n");


	printf("Thank you... \n");
	
	





}

