#include <stdio.h>
#include <math.h>

float Calculations(int c, float d, int g);
void bonus();
float RinseWashRepeat();
float DetRate(int a, int b);
float KHWUsedValidation(int e);
int AccountTypeValidation(int f);
int main()
{
int repeatval = 1;
int counter = 0;
float RunningTotal = 0;

while (repeatval == 1)
{
RunningTotal = RunningTotal + RinseWashRepeat();
printf("\nAny further entries?\n1 for yes and 0 for no\n");
scanf("%d", &repeatval);
counter++;
}



printf("\nYou calculated bills %d\nFor a total value of: $%.2f", counter, RunningTotal);

bonus();
return 0;
}

int AccountTypeValidation(int f)
{
while (f != 1 && f != 2 && f != 3)
{
printf("\nError: Must construct additional pylons....\nOR enter a 1.) Residential 2.) Commercial 3.) Industrial\n");
printf("Choose account type: ");
scanf("%d", &f);
}
return f;
}

int KWHUsedValidation(int e)
{
while (e < 0)
{
printf("\n Error: Glitch in the matrix Kilo-watt hours used must be greater then 0\n");
printf("\nPlease enter valid amount: ");
scanf("%d", &e);
}
return e;
}

float DetRate(int a, int b)
{
float Rate = 0;
switch(a)
{
case 1: if (b >= 0 && b <= 300)	{Rate = 7.50;}
	if (b > 300 && b <= 750){Rate = 10;}
	if (b > 750 && b <= 1500){Rate = 13.50;}
	if (b > 1500){Rate = 15;}
break;

case 2: if (b >= 0 && b <= 300){Rate = 10.50;}
	if (b > 300 && b <= 750){Rate = 14;}
	if (b > 750 && b <= 1500){Rate =17.50;}
	if (b > 1500){Rate = 20;}
break;

case 3: if (b >= 0 && b <= 300){Rate =36.50;}
	if (b > 300 && b <= 750){Rate = 40;}
	if (b > 750 && b <= 1500){Rate = 45.50;}
	if (b > 1500){Rate = 50;}
break;

}
return Rate;
}

float Calculations(int c, float d, int g)
{
float Total =0;
float NRGCharge = 0;
int CustCharge = 0;
switch(g)
{
case 1:
CustCharge = 15;
break;
case 2:
CustCharge = 70;
break;
case 3:
CustCharge = 650;
break;
}
NRGCharge = (float)  c * (d/100);
printf("\nThe energy charge for the customer is: $%.2f\n", NRGCharge);
Total = NRGCharge + CustCharge;
return Total;

}

float RinseWashRepeat()
{
int type = 0;
int KWH = 0;
float Rate = 0;
float total = 0;

printf("\n1.) Residential\n2.)Commercial\n3.)Industrial\n");
printf("\nPlease Enter account type: ");
scanf("%d", &type);
type = AccountTypeValidation(type);
printf("\nPlease Enter kilo-watt hours used: ");
scanf("%d", &KWH);
KWH = KWHUsedValidation(KWH);
Rate = DetRate(type,KWH);
total = Calculations(KWH,Rate,type);
printf("\nThe total charge is : $%.2f",total);

return total;
}

void bonus()
{
int counter = 0;
int oddtot = 0;
int eventot = 0;
int tot = 0;
int bonusnumber = 0;
printf("\n\n\nPlease enter a number: ");
scanf("%d", &bonusnumber);

printf("The numbers are: ");

for (counter = 0; counter <= bonusnumber; counter++)
{
if ((counter % 2) == 0)
{
eventot = counter + eventot;
}
else
{
oddtot = counter + oddtot;
}
printf("%d ", counter);
tot = counter + tot;
}

printf("\n\nThe sum of all numbers is: %d", tot);
printf("\n\nThe sum of all ODD numbers is: %d", oddtot);
printf("\n\nthe sum of all EVEN numbers is: %d\n\n", eventot);

}
