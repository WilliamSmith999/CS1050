#include <stdio.h>
#include <stdlib.h>

#define s scanf
#define p printf
#define fs fscanf
#define fp fprintf
#define name WilliamSmith
#define PawPrint WS42C

int load_data(char*, int *, float *,int );
void print_data(int *, float *, int);
int highest_amount( float *, int );
int lowest_amount( float *, int);

float average_amount( float *, int );

int update_data(char *, int *,float *,int );

void write_data(char* , int *, float *, int , int, int, float);

void print_stats(int *, float *, int , int, int, float);

void sort_data(int *,float *,int);

void datafill(char*, char*, char*, int);
void RollBackC(char*, int);
void RollBackD(int*, int);
void RollBackF(float*, int);

int main(int argc, char *argv[]){
	int count = 0;
	char *Assitptr;
	int *Highest;
	int *Lowest;
	float AVG = 0;
	int UnitDiff = 0;
	int HighestAccount = 0;
	float HighestBalance = 0;
	int LowestAccount = 0;
	float LowestBalance = 0;
	
	if (argc != 5){
		p("\nPlease use the correct command line arguments...");
		return (0);
	}
	
	int size = atoi(argv[2]);
	
	float *Floatptr = (float *) malloc(sizeof(float) * size);
	int *Intptr = (int*)malloc(sizeof(int) * size);
	char *Inptr = (char*)malloc(sizeof(char) * 9);
	char *Upptr = (char*)malloc(sizeof(char) * 9);
	char *Outpter = (char*)malloc(sizeof(char) * 9);
	datafill(Assitptr, Inptr, argv[1], count);
	datafill(Assitptr, Upptr, argv[3], count);
	datafill(Assitptr, Outpter, argv[4], count);
	if(load_data(Inptr, Intptr, Floatptr, size) != 1)
	{p("\nUnable to open file %s\n", Inptr);}
	if(load_data(Inptr, Intptr, Floatptr, size) == 1)
	{p("\nPraise the sun, File opened successfully\n");}
	print_data(Intptr, Floatptr, size);
	
	
	return (0);
}

void print_data(int* Intptr, float* Floatptr, int size){
	
	int count = 0;
	int i = 0;
	p("ACC NUM   AMOUNT\n");
	for(i = 0, count = 0; i < size; i++)
	{
		p("%d    %*.2f\n", *Intptr, 8, *Floatptr);
		Intptr++;
		Floatptr++;
		count++;
	}
	RollBackD(Intptr, count);
	RollBackF(Floatptr, count);
	
}
int load_data(char* a, int* b, float* c, int d){
	int i = 0;
	int count = 0;
	FILE *pFile;
	pFile = fopen(a, "r");
	
	
	
	if(pFile == NULL)
	{
		return (0);
	}
	
	for(i = 0; i < d; i++)
	{
		fs(pFile, "%d %f", b, c);
		b++;
		c++;
		count++;
	}
	RollBackD(b, count);
	RollBackF(c, count);
	return (1);
}
void RollBack(char* a, int b){
	
	while(b > 0)
	{
		a--;
		b--;
	}
	
}
void RollBackD(int* a, int b){
	
	while(b > 0)
	{
		a--;
		b--;
	}
	
}
void RollBackF(float* a, int b){
	
	while(b > 0)
	{
		a--;
		b--;
	}
	
}
void datafill(char* a, char* b, char* x, int c){
	a = x;
	while(*a != '\0')
	{
		*b = *a;
		b++;
		a++;
		c++;
	}
	while(c > 0)
	{
		b--;
		c--;
	}
		
}
int highest_amount( float* a, int b){
	float *Localptr; 
	float Assit1 = 0;
	int count = 0; 
	while(count < b)
	{
		if(*a > Assit1){Assit1 = *a; Localptr = a;}
		a++;
		count++;
	}
	
	RollBackF(a, count);
	return (int) Localptr;
}
int lowest_amount( float* a, int b){
	
	float *Localptr; 
	float Assit1 = 2000000000;
	int count = 0; 
	while(count < b)
	{
		if(*a < Assit1){Assit1 = *a; Localptr = a;}
		a++;
		count++;
	}
	
	RollBackF(a, count);
	return (int) Localptr;
}
float average_amount( float* a, int b){
	
	float AVG = 0;
	int i = 0;
	float AssitVar = 0;
	
	while(i < b)
	{
		AssitVar = AssitVar + *a;
		a++;
		i++;
	}
	AVG = (AssitVar/b);
	RollBackF(a, i);
	return AVG;
}
void print_stats(int *, float *, int , int, int, float){
	int count = 0;
	char *Assitptr;
	int *Highest;
	int *Lowest;
	float AVG = 0;
	int UnitDiff = 0;
	int HighestAccount = 0;
	float HighestBalance = 0;
	int LowestAccount = 0;
	float LowestBalance = 0;
	Highest = (int *)highest_amount(Floatptr, size);
	Lowest = (int *)lowest_amount(Floatptr, size);
	AVG = average_amount(Floatptr, size);
	
	count = 0;
	while(Floatptr != (float *)Highest)
	{
		count++;
		Floatptr++;
	}
	UnitDiff = count;
	HighestBalance = *Floatptr;
	RollBackF(Floatptr, count);
	count = 0;
	while (count < UnitDiff)
	{
		count++;
		Intptr++;
	}
	HighestAccount = *Intptr;
	RollBackD(Intptr, count);
	count = 0;
	while(Floatptr != (float *)Lowest)
	{
		count++;
		Floatptr++;
	}
	UnitDiff = count;
	LowestBalance = *Floatptr;
	RollBackF(Floatptr, count);
	count = 0;
	while (count < UnitDiff)
	{
		count++;
		Intptr++;
	}
	LowestAccount = *Intptr;
	RollBackD(Intptr, count);
	p("\nLowest account and it's balance: \n");
	p("%d    %*.2f\n", LowestAccount, 8, LowestBalance);
	p("\nHighest account and it's balance: \n");
	p("%d    %*.2f\n", HighestAccount, 8, HighestBalance);
	
}




