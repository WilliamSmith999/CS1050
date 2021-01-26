#include <stdio.h>
#include <stdlib.h>

#define s scanf
#define p printf
#define R rand()

void bonus(int[]);
void LoadArray(int[],int);
void PrintArray(int[],int);
int UserInput(void);
int ErrorChecker(int a);
void DisplayMenu(void);
int GenerateNumber(void);
int CheckGuess(int b, int c);
void PrintResult(int b, int c);
int RinseWashRepeat(void);
void WinsLoses(int d, int e, int f);

int main()
{
int BonusArray[100] = {0};
int SentVal = 0;
int WinLose = 0;
float Record = 0;
int wins = 0;
int lose = 0;

while (SentVal == 0)
{
WinLose = RinseWashRepeat();
if (WinLose == 0)
{lose++;}
if (WinLose == 1)
{wins++;}
p("\nDo you want to play again?\n0 for YES\n1 for NO: ");
s("%d", &SentVal);
Record++;
}
//p("\n\n%d\n\n",wins);
//p("\n\n%d\n\n",lose);
WinsLoses(wins,lose,Record);

bonus(BonusArray);

return 0;
}

void WinsLoses(int d, int e, int f)
{
if (d != 0 && e != 0)
{
float WLRatio = 0;
WLRatio = (float) d/e;
p("\nyou have played %d games, with a win lose recorde of %.2f", f, WLRatio);
}
else
{
if(d == 0)
{p("\nYou have Won %d games, and lost %d games", d, e);}
else
{p("\nYOU WON ALL YOUR GAMES!");}
}
p("\n\n");
}

int RinseWashRepeat(void)
{
int UserIn = 0;
int Random = 0;
int result = 0;
int WinLose =  0;
DisplayMenu();
while (ErrorChecker(UserIn = UserInput()) == 0)
{p("\nI'm sorry user, I can't let you do that... 1 or 0: ");}
Random = GenerateNumber();
result = CheckGuess(UserIn, Random);
PrintResult(result, Random);
if (result == 1)
{WinLose = 1;}
else
{WinLose = 0;}
return WinLose;
}

int GenerateNumber()
{
int number = 0;
number = (R%2);
return number;
}

int ErrorChecker(int a)
{
int ErrorCode = 0;
if (a != 1 && a != 0)
{ErrorCode = 0;}
else
{ErrorCode = 1;}
return ErrorCode;
}

void DisplayMenu (void)
{p("\nPlease Make a guess (It's a 50/50 shot and nothing to loose right?)\n0-----> HEADS\n1-----> TAILS\nEnter 1 or 0\nYour guess: ");}

int UserInput(void)
{
int input = 0;
s("%d", &input);
return input;
}

void PrintResult(int b, int c)
{
if (b == 1)
{p("\nYOU WIN!");}
if (b == 0)
{p("\nSorry try again...");}
if (c == 1)
{p("\nThe awnser was Tails.");}
if (c == 0)
{p("\nThe awnser was Heads.");}
}

int CheckGuess(int b, int c)
{
int result = 0;
if (b == c)
{result = 1;}
else
{result = 0;}
return result;
}

void bonus(int a[])
{
int Temp = 0;
p("\n\n*****BONUS*****\nPlease enter a number for the size of the array <100: ");
s("%d", &Temp);
while (Temp > 100 || Temp == 100)
{
p("\nI'm One does not simply put a number >= 100 into this program\nPlease Try Again: ");
s("%d", &Temp);
}
LoadArray(a, Temp);
PrintArray(a, Temp);
}

void LoadArray(int a[],int b)
{
int counter = 0;
for (counter = 0; counter <= b; counter++)
{a[counter] = (R%10);} 
}

void PrintArray(int a[], int b)
{
int counter = 0;
for (counter = 0; counter <= b; counter++)
{
p("Here are the first %d numbers of the array fully randomized\n",b);
p(" %d", a[counter]);
p("\n");
}
}
