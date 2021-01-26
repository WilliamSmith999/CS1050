#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define x X
#define ROW 6										//Number of Rows of seats
#define COL 4										//Number of Columns of seats
#define MAX 20										//Maximum characters in strings

int costMatrix[ROW][COL]={{300,200,200,300},		//This is the cost of each seat in all the 3 flights. There are 24(How??) seats in each flight. 
			  			  {300,200,200,300},	
			  			  {300,200,200,300},
			  			  {300,200,200,300},
			 			  {300,200,200,300},
			 			  {300,200,200,300}};



// Displays the Menu options
void displayMenu();

/*This does the log-in authentication, return 1 only if both the strings match , else it returns 0. Essentially, you will be doing string compare. 
Comparing two strings is checking if all the characters are same in both.Compares the pawprint with adminPawprint and password with adminPassword */
bool loginMatch(char string1[],char string2[]);

/*This does the initialization for each flight, called as soon as your program starts. Allocates 1-5 (specified by count)seats in the flight.
fill those seats randomly in all 3 flights before hand. Print 'O' for unreserved seats and 'X' for reserved seats*/
void initialSeats(char flight[][COL],int count);

//Prints the current flight Map every time it is called. Send the flight as the parameter.
void printFlightMap(char flight[][COL]);

//Prints the flight options. 3 flights from COU to BNA,LAS,MIA
void flightMenu(char flight1[][COL], char flight2[][COL], char flight3[][COL]);

/*This calculates the Total Revenue, sum of the cost of all reserved seats from each flight. Called in admin mode only.
If an index in a flight is 'X', take the cost for that particular index from costMatrix[][] and add it to a running total
and return that total. Do that for all three flights*/
int getTotalRevenue(char flight[][COL]);

/*Reserves seat in a flight, have to ask for which row (0-5) and which column(0-3) from the user. Perform error check inside this for row and column entered. 
mark that seat as 'X', if the seat is already taken then you need to loop back and ask again. If reservation is possible, print a success message,assign the seat
and print the flight map here*/
void seatReservation(char flight[][COL]);

/*Just before calling this function in main() : flight numbers are "MIA1050","BNA1050",LSA1050". Store this in num1[],num2[],num3[] respectively 
Ask for the first name when a flight option is chosen. Store this in name[]. This function takes those two strings, name and flight number, as parameters. 
Merges them and stores them in 3rd string as shown in the output and prints the message of confirmation.
*/
void printMessage(char name[], char num[7]);
void rinsewashrepeat(char flight1[][COL],char flight2[][COL],char flight3[][COL]);
bool AdminLogin ();


int main(void)
{
char flight1[ROW][COL]={{'O','O','O','O'},
			  			{'O','O','O','O'},	
			  			{'O','O','O','O'},
			  			{'O','O','O','O'},
			 			{'O','O','O','O'},
			 			{'O','O','O','O'}};
char flight2[ROW][COL]={{'O','O','O','O'},
			  			{'O','O','O','O'},	
			  			{'O','O','O','O'},
			  			{'O','O','O','O'},
			 			{'O','O','O','O'},
			 			{'O','O','O','O'}};
char flight3[ROW][COL]={{'O','O','O','O'},
			  			{'O','O','O','O'},	
			  			{'O','O','O','O'},
			  			{'O','O','O','O'},
			 			{'O','O','O','O'},
			 			{'O','O','O','O'}};

initialSeats(flight1, 2);
initialSeats(flight2, 2);
initialSeats(flight3, 2);
rinsewashrepeat(flight1, flight2, flight3);
printf("Goodbye\n");

return (0);
}


void displayMenu()
{
	printf("1: Admin Login\n2: Flight Menu\n3: Exit\n");
	printf("\nPlease Choose: ");
}

bool loginMatch(char string1[],char string2[])
{
int ColCount = 0;
int counter = 0;
bool FailState = false;


for (counter  = 0; counter  < ROW; counter++)
{	
	for(ColCount = 0; ColCount < COL; ColCount++)
	{ if(string1 != string2){FailState = true;}}
}

return FailState;	
}

void initialSeats(char flight[][COL],int count)
{
	{
int temp = 0;
int LocCount = 0;		
int ColCount = 0;
int counter = 0;
for (counter = 0; LocCount  <  count && counter < count; counter++)
{	for(ColCount =0; ColCount < COL && LocCount < count; ColCount++)
	{
	temp = (rand()%2);
	if (temp == 0)
	{
	flight[counter][ColCount] = 'X';
	LocCount++;
	}
	if (temp == 1)
	{flight[counter][ColCount] = 'O';}
	}
}
}
}

void printFlightMap(char flight[][COL])
{
int ColCount = 0;
int counter = 0;
for (counter  = 0; counter  < ROW; counter++)
{	
	for(ColCount = 0; ColCount < COL; ColCount++)
	{printf("%c", flight[counter][ColCount]);}
printf("\n");
}
printf("\n");
}

void flightMenu(char flight1[][COL], char flight2[][COL], char flight3[][COL])
{
	
	int ActionChoice = 0;
	printf("\n1.) COU ----> MIA\n2.) COU ----> BNA\n3.) COU ----> LAS");
	printf("\nChoose a flight: ");
	scanf("%d", &ActionChoice);
	char Name[MAX] = "";
	printf("\nPlease enter your name: ");
	scanf("%s", Name);
	printf("\n");
	if(ActionChoice == 1)
	{
	printFlightMap(flight1);
	printf("\n");
	seatReservation(flight1);
	printMessage(Name, "MIA1050");
	}
	if (ActionChoice == 2)
	{
	printFlightMap(flight2);
	printf("\n");
	seatReservation(flight2);
	printMessage(Name, "BNA1050");
	}
	if (ActionChoice == 3)
	{
	printFlightMap(flight3);
	printf("\n");
	seatReservation(flight3);
	printMessage(Name, "LAS1050");
	}
	

}

int getTotalRevenue(char flight[][COL])
{
int TwoRevenue = 0;
int ThreeRevenue = 0;
int Revenue = 0;
int TwoXCount = 0;
int ThreeXCount = 0;
int counter = 0;
for (counter  = 0; counter  < ROW; counter++)
{	
	if(flight[counter][0] == 'X')
	{
		ThreeXCount++;
	}
	if(flight[counter][3] == 'X')
	{
		ThreeXCount++;
	}
	
	if(flight[counter][1] == 'X')
	{
		TwoXCount++;
	}
	if(flight[counter][2] == 'X')
	{
		TwoXCount++;
	}
}

TwoRevenue = TwoXCount * 200;
ThreeRevenue = ThreeXCount * 300;
Revenue = TwoRevenue + ThreeRevenue;

return Revenue;	
}

void seatReservation(char flight[][COL])
{
	int row = 0;
	int column = 0;
	bool SeatTaken = false;
	printf("\nPlease enter desired row: ");
	scanf("%d", &row);
	while(row < 0 && row > 5)
	{
		printf("I'm afraid I can't do that; must be between 0 and 5");
		scanf("%d", &row);
	}
	printf("\nPlease enter desired column: ");
	scanf("%d", &column);
	while(column < 0 && column > 3)
	{
		printf("I'm afraid I can't do that; must be between 0 and 3");
		scanf("%d", &column);
	}
	do
	{
		if(flight[row][column] == 'X')
		{
			SeatTaken = true;
		}
		else
		{
			SeatTaken = false;
		}
		if(SeatTaken)
		{
			printf("\nI'm sorry that seat is taken, please select another: ");
			printf("\nPlease enter desired row: ");
	scanf("%d", &row);
	while(row < 0 && row > 5)
	{
		printf("I'm afraid I can't do that; must be between 0 and 5");
		scanf("%d", &row);
	}
	printf("\nPlease enter desired column: ");
	scanf("%d", &column);
	while(column < 0 && column > 3)
	{
		printf("I'm afraid I can't do that; must be between 0 and 3");
		scanf("%d", &column);
	}
		}
		
	} while(SeatTaken);
	if(!SeatTaken)
	{
		flight[row][column] = 'X';
		printf("\nYour seat has been reserved\n");
		printFlightMap(flight);
	}
}

void printMessage(char name[], char num[])
{
	int counter = 0;
	char Eticket[2][MAX] = {{'b'},{'b'}};
	for(counter = 0; num[counter] != '\0' || name[counter] != '\0'; counter++)
	{
		Eticket[0][counter] = num[counter];
		Eticket[1][counter] = name[counter];
	}
	printf("Thank you, %s, your flight, %s, is booked.\nYour e-ticket number is: ", name, num );
for (counter  = 0; Eticket[1][counter]  != '\0' || Eticket[0][counter] != '\0'; counter++)
{	
printf("%c", Eticket[1][counter]);
printf("%c", Eticket[0][counter]);
}
	printf("\n");
}

bool AdminLogin()
{
	char AdminPaw[MAX] = "jdwdm3";
	char AdminPass[MAX] = "cmp_sc1050";
	char PawIn[MAX];
	char PassIn[MAX];
	printf("\nAdmin Login\nAdmin pawprint: ");
	scanf("%s", PawIn);
	printf("\nPassword: ");
	scanf("%s",PassIn);
	while (!loginMatch(PawIn, AdminPaw) && !loginMatch(PassIn, AdminPass))
	{
	printf("\nAdmin Login\nAdmin pawprint & password (In that order): ");
	scanf("%s", PawIn);
	scanf("%s",PassIn);
	}
	printf("Log in compete\n");
	bool AdminMode = true;
	
	return AdminMode;
}

void rinsewashrepeat(char flight1[][COL], char flight2[][COL], char flight3[][COL])
{
	int Money = 0;
	int ActionChoice = 0;
	bool Exit = false;
	bool AdminMode = false;
	while(Exit == false)
	{
	displayMenu();
	scanf("%d", &ActionChoice);
	switch (ActionChoice)
	{
	case 1 : {AdminMode = AdminLogin();}
	break;
	
	case 2 : {flightMenu(flight1,flight2,flight3);}
	break;
	
	case 3: {Exit = true;}
	break;
	
	default: {printf("\nPlease try again...");}
	break;
	}

	if(AdminMode)
	{
	printFlightMap(flight1);
	printf("\n");
	printFlightMap(flight2);
	printf("\n");
	printFlightMap(flight3);
	printf("\n");
	Money = getTotalRevenue(flight1) + getTotalRevenue(flight2) + getTotalRevenue(flight3);
	printf("\nTotal earnings from flights: %d\n", Money);
	printf("\nExiting admin mode\n");
	AdminMode = false;
	}
	}
}
