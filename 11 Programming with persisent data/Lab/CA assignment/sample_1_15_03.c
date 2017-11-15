#include <stdio.h>
#include <string.h>

#define SIZE 3
#define NAME 21
#define CODE 7

struct hotel
{
	char name[NAME];
	char code [CODE];
	float price;
};

void display(struct display a)
{
	int i;

	for (i = 0; i < SIZE; i++)
	{
		printf("\n%s %s %.2f\n",a[i].name, a[i].code, a[i].price);
	}//end for loop
}//end display

int main()
{
	sturct hotel spain [SIZE], ENG [SIZE], temp;
	ENG [0] = {"Ritz",
			"A123",
			200.00};
	ENG [1] = {"Carlton",
				"B234",
				500.00};

int i, j;
FILE *fp;

//Get input from user

for (i = 0; i < SIZE; i++)
{
	puts("Whats the hotel name?");
	scanf("%20s",spain[i].name);
	puts("	Whats the price?");
	scanf("%f",spain[i].price);
}//end for loop

puts("Hotel Data");
display(spain);

for (i = 0; i < SIZE; i++)
{
	for (j = 0; j < SIZE; j++)
	{
		if 
	}
}
return 0;
}