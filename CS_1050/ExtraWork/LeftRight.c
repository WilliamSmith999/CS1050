#include <stdio.h>

int main()
{
	int Choice = 1;
	int Off  = 0;
	int On  = 1;
	
	printf("\n this game only uses keys 1 and 0, on and off...");
	printf("\n If you want to go left, imput 0... \n");
	scanf("%d", &Choice);
	if (Choice == Off )
	{
		printf("\n So you want to go left?");
	}
	else
	{
		printf("\n So you want to go right?");
	}
	printf("\n Is that correct?... (1 for yes 0 for no)");
	scanf("%d", &Choice);
	if (Choice == 1)
	{
		printf("\n Good everything is working...");
	}
	else
	{
		printf("\n -_- \n");
		printf("\n Did you only hit 1 OR 0? \n");
	}

return(0);
}
