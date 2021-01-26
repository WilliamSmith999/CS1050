#include <stdio.h>

int main()
{
	int x,y;
	printf("\n Enter the first number: ");
	scanf("%d", &x);

	printf("\n Enter the second number: ");
	scanf("%d", &y);
	if(x > y)
	{
		printf("\n %d  is the largest number", x);
	}
	else
	{
		printf("\n %d is the largest number", y);
	}

	printf("\n");
	return 0;
}
