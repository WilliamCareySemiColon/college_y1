/**************************************************************************************************************
Description: Program to use the merge sort alogorthm to take in 8 rhandom numbers and sort them into order from
smallest to biggest. It should dispaly the content of before it is sorted and after it is sorted. IT is then 
will use the binary search to search for the index of the numbers location, and print this out to user. Program 
will be modularised for efficiency
Date started: 20-03-2017
William Carey
**************************************************************************************************************/

//header files
#include <stdio.h>

//Symbolic names
#define SIZE 8

//Function prototypes
void get_array(void);
void print_message(void);
int merge_sort(int *, int *);
void merge(int *, int *, int *);
void bin_search(int *);

//Global Arrays
int unsorted_array [SIZE];
int sorted_array [SIZE];

//Implementing main body now
void main()
{

	//calling input array
	get_array();

	//printing message
	print_message();

	//Implememting the merge sort alogorithm
	merge_sort(unsorted_array,unsorted_array+(SIZE-1));
}//end main

/************************************************************
Getting user input for the array, Expecting it to be random. 
************************************************************/

void get_array()
{
	int i;

	puts("Please enter your eight numbers");

	for (i = 0; i < SIZE; i++)
	{
		scanf("%d",&*(unsorted_array+i));
	}//end for loop
}//end get_array()

/************************************************************
Displaying the contents of the array,so the user can see 
the difference. 
************************************************************/

void print_message()
{
	int i;

	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", &*(unsorted_array+i));
	}//end for loop
}//end message

/************************************************************
Implementing the merge sort alogirithm. This is a recusive 
function
************************************************************/

void merge_sort(int *low, int *high)
{
	int *mid; 
	if (*low == *high)
	{
		return *low
	} 
	else 
	{
		mid = (high + low)/2;
		merge_sort(low, mid);
		merge_sort(mid + 1, high);
		merge(low,mid,high);
	}
}//end of merge_sort function

/************************************************************
Implementing the merge alogirithm. This is a recusive 
function
************************************************************/

void merge(Int *low, int *mid, *high)
{
	int temp [SIZE];
	int i, j, k,l;

	for (i = 0; i < SIZE; i++)
	{

	}
}