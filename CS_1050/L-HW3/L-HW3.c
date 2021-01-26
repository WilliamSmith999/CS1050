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
void print_stats(int *, float *, int, int, float);
void sort_data(int *,float *,int);
void datafill(char*, char*, char*, int);
void RollBackC(char*, int);
void RollBackD(int*, int);
void RollBackF(float*, int);

int main(int argc, char *argv[]){
	int count = 0;
	char *Assitptr;
	int index_of_highest = 0;
	int index_of_lowest = 0;
	int AVG = 0;
	
	
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
	index_of_highest = highest_amount(Floatptr, size);
	index_of_lowest = lowest_amount(Floatptr, size);
	AVG = average_amount(Floatptr, size);
	print_data(Intptr, Floatptr, size);
	print_stats(Intptr, Floatptr, index_of_highest, index_of_lowest, AVG);
	update_data(Upptr, Intptr, Floatptr, size);
	sort_data(Intptr, Floatptr, size);
	p("\nThe new balances for the accounts and in sorted postions: \n");
	index_of_highest = highest_amount(Floatptr, size);
	index_of_lowest = lowest_amount(Floatptr, size);
	AVG = average_amount(Floatptr, size);
	print_data(Intptr, Floatptr, size);
	print_stats(Intptr, Floatptr, index_of_highest, index_of_lowest, AVG);
	write_data(Outpter, Intptr, Floatptr, size, index_of_highest, index_of_lowest, AVG);
	
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
	int i = 0;
	int index = 0;
	int high = 0;
	
	while(i < b){
		
			if(*(a+i) > high){
				
				high = *(a+i);
				index = i;
				
			}
		i++;
	}
	
	return index;
}
int lowest_amount( float* a, int b){
	
	int i = 0;
	int index = 0;
	int low = 0;
	
	while(i < b){
		
			if(*(a+i) < low){
				
				low = *(a+i);
				index = i;
				
			}
		i++;
	}
	
	return index;
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
void print_stats(int* Intptr, float* Floatptr, int IndexHigh, int IndexLow, float AVG){
	
	p("\nLowest account and it's balance: ");
	p("%d    %*.2f\n", *(Intptr+IndexLow), 8, *(Floatptr+IndexLow));
	p("\nHighest account and it's balance: ");
	p("%d    %*.2f\n", *(Intptr+IndexHigh), 8, *(Floatptr+IndexHigh));
	p("\nThe average amount of all account balance's: %.2f\n", AVG);
	
}
int update_data(char* Upptr, int* Intptr, float* Floatptr, int size){
	
	FILE* fPtr = fopen(Upptr, "r");
	int i = 0;
	int j = 0;
	int* updateAcc = malloc(sizeof(int)*size);
	float* updateBal = malloc(sizeof(float) * size);
	
	if(fPtr == NULL){p("\nERROR failed to open file..."); return (0);}
	
	while(fs(fPtr,"%d %f", (updateAcc+i),(updateBal+i)) == 2){
		
		for(j=0; j < size; j++){
			
			if(*(updateAcc+i) == *(Intptr+j)){
				
				*(Floatptr+j) += *(updateBal+i);
				
			}
			
		}
		i++;
	}
	free(updateAcc);
	free(updateBal);
	return (1);
}
void sort_data(int* Intptr, float* Floatptr, int size){
	
	int AccAssit = 0;
	float BalAssit = 0;
	int j = 0;
	int i = 0;
	
	for(i = 0; i < size - 1; i++){
		
		for(j = 0; j < size - 1; j++){
			
			if(*(Intptr+j) > *(Intptr+j+1)){
				
				
			AccAssit = *(Intptr+j);
			*(Intptr+j) = *(Intptr+j+1);
			*(Intptr+j+1) = AccAssit;
			
			BalAssit = *(Floatptr+j);
			*(Floatptr+j) = *(Floatptr+j+1);
			*(Floatptr+j+1) = BalAssit;
			
			}
			
		}
		
	}
	
}
void write_data(char* Outpter, int* Intptr, float* Floatptr, int size, int IndexHigh, int IndexLow, float AVG){
	
	int i = 0;
	
	FILE* fPtr = fopen(Outpter, "w");
	
	if(fPtr == NULL){p("\nYour file has met a terrible fate hasn't it?\nUnable to open file\n");}
	
	while (i < size){
		
		fp(fPtr, "%d       %.2f\n", *(Intptr+i), *(Floatptr+i));
		i++;
		
	}	
	
	fp(fPtr, "\nLowest account and it's balance: ");
	fp(fPtr, "%d    %*.2f\n", *(Intptr+IndexLow), 8, *(Floatptr+IndexLow));
	fp(fPtr, "\nHighest account and it's balance: ");
	fp(fPtr, "%d    %*.2f\n", *(Intptr+IndexHigh), 8, *(Floatptr+IndexHigh));
	fp(fPtr, "\nThe average amount of all account balance's: %.2f\n", AVG);
	
}






