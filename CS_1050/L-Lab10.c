#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define p printf
#define s scanf

int length(char *s);
char* copy(char *s);
void clear(char *s);
char* reverse(char *s);
int compare(char *a, char *b);
char* merge(char *a, char *b);
int palindrome(char *a);

int main(){

	
	
	char *Cptr = (char *)malloc(MAX);
	printf("\nString Manipulator 9000\nEnter first string: ");
	scanf("%s", Cptr);
	p("\nThe length of the string is: %d",length(Cptr));
	
	char *Copyptr = copy(Cptr);
	p("\nThe copy of the string is: %s", Copyptr);
	
	char *Reverseptr = reverse(Cptr);
	p("\nThe reversed version is: %s", Reverseptr);
	
	char *Secptr = (char *)malloc(MAX);
	p("\nPlease enter a new string for comparison: ");
	s("%s", Secptr);
	
	compare(Cptr, Secptr);
	
	p("\nThe merged string is: %s", merge(Cptr, Secptr));
	
	char *Triptr = (char *)malloc(MAX);
	p("\nPlease enter a new string for comparison: ");
	s("%s", Triptr);
	if(palindrome(Triptr) == 1){p("\nThe input is a palindrome.\n");}
	if(palindrome(Triptr) != 1){p("\nThe input is not a palindrome.\n");}
	
	return (0);
}

int length(char *s){	
	char *Assitptr;
	int Length = 0;
	Assitptr = s;
	
	while(*Assitptr != '\0')
	{
		Assitptr++;
		Length++;
	}
	
	return Length;
}

char* copy(char *s){
		char *CopyptrAssit = (char *)malloc(length(s));
		CopyptrAssit = s;
		return CopyptrAssit;
}

char* reverse(char *s){
	
	int len = length(s);
	char* ReverseString = (char *)malloc(length(s));
	int i = 0;
	len--;
	while(*(s+i) != '\0'){
		
		*(ReverseString+i) = *(s+len);
		i++;
		len--;
	}
	
		return ReverseString;
	}
	
int compare(char *a, char *b){
	int ResUlt = 0;
	char *AssitptrA;
	AssitptrA = a;
	char *AssitptrB;
	AssitptrB = b;
	char c;
	char d;
	int asciival = 0;
	int asciival2 = 0;
	
	while (*AssitptrA == *AssitptrB){
		AssitptrA++;
		AssitptrB++;
	}
	
	c = *AssitptrA;
	d = *AssitptrB;
	
	asciival = (int) c;
	asciival2 = (int) d;
	
	ResUlt = asciival - asciival2;
	
	if(ResUlt > 0){p("\n%s is larger then %s.", a, b);}
	if(ResUlt < 0){p("\n%s is smaller then %s.", a, b);}
	if(ResUlt == 0){p("\n%s and %s are the same.", a, b);}
	
	return ResUlt;
}
	
char* merge(char *a, char *b){
	
	char* Mergeptr = (char *)malloc(MAX);
	int i = 0;
	int j = 0;
	int n = 0;
	
	while(*(a + j) != '\0' && *(b + n) != '\0')
	{
		*(Mergeptr + i) = *(a + j);
		i++;
		j++;
		*(Mergeptr + i) = *(b + n);
		i++;
		n++;
	}
	while(*(a + j) != '\0')
	{
		*(Mergeptr + i) = *(a + j);
		i++;
		j++;
	}

	while(*(b + n) != '\0')
	{
	*(Mergeptr + i) = *(b + n);
		i++;
		n++;	
	}
	
return 	Mergeptr;
}

int palindrome(char *s){
	int End = 0;
	if(s == reverse(s))
	{
		End = 1;
	}
		
	return End;
}

