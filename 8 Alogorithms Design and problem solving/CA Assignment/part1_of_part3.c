/*******************************************************************************
Description: This programme will take in three files and store them it in one
file. It will store them in diffrerent arrays, then sort them within those
arrays. Once taht is completed, all three will be copied into an fourth array.
After written into tha forth, another sorting method will sort them so they are
ordered. There are 20 Funded EU students, 6 non funded and 10 international.
Two sorting methods are used, intially the merge sort with the inclusion of the
insertion sort. The course is already decided and it is full time, lasting one
year. The only we do not know is the age, student id, firstname and surname. We
know if what type of student they are based on the file we are reading from. We
are sorting this basing on student id, as that is the only unique item amoung
amoung them (We know if two students have the same first name and last name, their
student id would be different).
*******************************************************************************/

//header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//symbolic names
#define FIRSTNAME 11
#define SURNAME 21
#define STUDENT_ID 10
#define YEAR 3
#define FUNDED_EU 20
#define UNFUNDED_EU 6
#define TOTAL 36
#define STATUS 15
#define t 1
#define f 0

//strucuture template
struct student_details
{
	char firstname [FIRSTNAME];
	char surname [SURNAME];
	char student_id [STUDENT_ID];
	char type [STATUS];
	char age [YEAR];
};

//function prototype
void merge_sort (int, int, int, struct student_details *);
void merge (int, int, int, int, struct student_details *);
void insertion_sort (int, int, int, struct student_details *);

//implementing the main body
void main()
{
	//int variables
	int index;

	//struct variables
	struct student_details eu_funded [FUNDED_EU];
	struct student_details eu_nonfunded [UNFUNDED_EU];
	struct student_details international [STUDENT_ID];
	struct student_details altogether [TOTAL];

	//FILE variables
	FILE *fp = fopen("funded EU.docx","r");
	FILE *fp2 = fopen("unfunded eu.docx","r");
	FILE *fp3 = fopen("international students.docx","r");
	FILE *fp_final = fopen("DT_265_postgratuate_student_list.docx","w");

	//checking for existence of the files
	if (fp == NULL || fp2 == NULL || fp3 == NULL)
	{
		puts("One or more of the files does not exist");
	}

	else
	{
		//Ensuring we start from the begining
		rewind(fp);
		rewind(fp2);
		rewind(fp3);
		rewind(fp_final);

		//Getting input fromn the first file
		for (index = 0; index < FUNDED_EU; index++)
		{
			//getting input from a file into a struct array
			fscanf(fp,"%10S %20S %2S %9S\n",eu_funded[index].firstname,eu_funded[index].surname,eu_funded[index].age,eu_funded[index].student_id);

			//making sure we know the status of the student when we write it into another file
			strcpy(eu_funded[index].type,"EU Funded");
		}//end for loop

		//getting input from the second file
		for (index = 0; index < UNFUNDED_EU ; index++)
		{
			//getting input from a file into a struct array
			fscanf(fp2,"%10S %20S %2S %9S\n",eu_nonfunded[index].firstname,eu_nonfunded[index].surname,eu_nonfunded[index].age,eu_nonfunded[index].student_id);

			//making sure we know the status of the student when we write it into another file
			strcpy(eu_funded[index].type,"EU Unfunded");
		}//end for loop

		//getting input from the third file
		for (index = 0; index < STUDENT_ID; index++)
		{
			//getting input from a file into a struct array
			fscanf(fp3,"%10S %20S %2S %9S\n",international[index].firstname,international[index].surname,international[index].age,international[index].student_id);

			//making sure we know the status of the student when we write it into another file
			strcpy(eu_funded[index].type,"International");
		}//end for loop

		//sorting the first array
		merge_sort(0, FUNDED_EU - 1, FUNDED_EU, eu_funded);

		//sorting the second array
		merge_sort(0, UNFUNDED_EU - 1,UNFUNDED_EU, eu_nonfunded);

		//sorting the third array
		merge_sort(0, STUDENT_ID - 1, STUDENT_ID, international);

		//Starting to copy the contents of the three arrays into one

		//copiny the contents of the EU funded students into the altogether array
		for(index = 0; index < FUNDED_EU; index++)
		{
			strcpy(altogether[index].firstname,eu_funded[index].firstname);
			strcpy(altogether[index].surname,eu_funded[index].surname);
			strcpy(altogether[index].student_id,eu_funded[index].student_id);
			strcpy(altogether[index].type,eu_funded[index].type);
			strcpy(altogether[index].age,eu_funded[index].age);
		}//end for loop

		//copiny the contents of the EU not funded students into the altogether array
		for(index = 0; index < UNFUNDED_EU; index++)
		{
			//ensuring it is from 20th postion onwards that gets copied into
			strcpy(altogether[FUNDED_EU + index].firstname,eu_nonfunded[index].firstname);
			strcpy(altogether[FUNDED_EU + index].surname,eu_nonfunded[index].surname);
			strcpy(altogether[FUNDED_EU + index].student_id,eu_nonfunded[index].student_id);
			strcpy(altogether[FUNDED_EU + index].type,eu_nonfunded[index].type);
			strcpy(altogether[FUNDED_EU + index].age,eu_nonfunded[index].age);
		}//end for loop

		//copiny the contents of the international students into the altogether array
		for(index = 0; index < STUDENT_ID; index++)
		{
			//ensuring we copy from the 26th postion onwards
			strcpy(altogether[(FUNDED_EU + UNFUNDED_EU) + index].firstname,eu_funded[index].firstname);
			strcpy(altogether[(FUNDED_EU + UNFUNDED_EU) + index].surname,eu_funded[index].surname);
			strcpy(altogether[(FUNDED_EU + UNFUNDED_EU) + index].student_id,eu_funded[index].student_id);
			strcpy(altogether[(FUNDED_EU + UNFUNDED_EU) + index].type,eu_funded[index].type);
			strcpy(altogether[(FUNDED_EU + UNFUNDED_EU) + index].age,eu_funded[index].age);
		}//end for loop

		insertion_sort (0, TOTAL - 1, TOTAL, altogether);

		//writing the details to a file now
		for(index = 0; index < TOTAL; index++)
		{
			fprintf(fp_final,"Name: %s Surname: %s Age: %s Student Status: %s Student ID: %s\
			\n",altogether[index].firstname,altogether[index].surname,altogether[index].age,altogether[index].type,altogether[index].student_id);
		}//end for loop

		//closing the pointers to the files
		fclose(fp);
		fclose(fp2);
		fclose(fp3);
		fclose(fp_final);

		puts("\nProgramme completed");
	}//end else

	getchar();
	fflush(stdin);
}//end main body

/*****************************************************************************************
The following function applies to the merge sort alogorithm. This function is to break the
problem into sub problems and call two other functions to bring it together. Once this has
sorted three arrays we know we are done with this function
Functions that this function is going to call: Merge and insertion
*****************************************************************************************/

void merge_sort (int low, int high, int count, struct student_details *original)
{
    int mid;
	if (count < 8)
	{
		insertion_sort(count, low, high, original);
	}

	else
	{
		if (count % 2 == 0)
		{
			mid = (high + low)/2;

			merge_sort((count/2), low, mid, original);

			merge_sort((count/2),(mid + 1),high, original);

			merge( count, low, mid, high, original);
		}

		else
		{
			mid = (high + low)/2;

			merge_sort((count/2), low, mid, original);

			merge_sort(((count/2) + 1),(mid + 1),high, original);

			merge(count, low, mid, high, original);
		}

	}//end if..else statemnt
}//end merge_sort function

/*****************************************************************************************
The following is the merge function. This will use the passed parameters to sort the array
and then put them back together.
*****************************************************************************************/

void merge (int count, int low, int mid, int high, struct student_details *original)
{
	//strcture variables
	struct student_details temp [TOTAL];

	//variables to compare with
	char student_idefication_1 [STUDENT_ID], student_idefication_2 [STUDENT_ID];
	//other variables
	int index, joy;
    joy = 0;
	//postion variables
	int middle = mid;
	int start = low;

	while (low < middle && mid < high)
	{
		strcpy(student_idefication_1, (original + low)->student_id);
		strcpy(student_idefication_2,(original + mid)->student_id);

		//to get rid of the letter so we can use the atoi function
		for (index = 0; index < STUDENT_ID && (index + 1) < STUDENT_ID; index++)
		{
			student_idefication_1[index] = student_idefication_1[index + 1];
			student_idefication_2 [index] = student_idefication_2 [index + 1];
		} //end for loop

		//now checking which variables are bigger and which are smaller
		if (atol(student_idefication_1) < atol(student_idefication_2))
		{
			//coping the contents of the variables that is smaller
			strcpy(temp[joy].firstname,(original + low)->firstname);
			strcpy(temp[joy].surname,(original + low)->surname);
			strcpy(temp[joy].student_id,(original + low)->student_id);
			strcpy(temp[joy].type,(original + low)->type);
			strcpy(temp[joy].age,(original + low)->age);

			low++;
		}
		else
		{
			//coping the contents of the variables that is smaller
			strcpy(temp[joy].firstname,(original + mid)->firstname);
			strcpy(temp[joy].surname,(original + mid)->surname);
			strcpy(temp[joy].student_id,(original + mid)->student_id);
			strcpy(temp[joy].type,(original + mid)->type);
			strcpy(temp[joy].age,(original + mid)->age);

			mid++;
		}//end if...else statement

		joy++;
	}//end while loop

	if (low < middle)
	{
		while (low < middle)
		{
			//coping the contents of the variables that is smaller
			strcpy(temp[joy].firstname,(original + low)->firstname);
			strcpy(temp[joy].surname,(original + low)->surname);
			strcpy(temp[joy].student_id,(original + low)->student_id);
			strcpy(temp[joy].type,(original + low)->type);
			strcpy(temp[joy].age,(original + low)->age);

			low++;
			joy++;
		}//end while loop
	}

	else
	{
		//coping the contents of the variables that is smaller
			strcpy(temp[joy].firstname,(original + mid)->firstname);
			strcpy(temp[joy].surname,(original + mid)->surname);
			strcpy(temp[joy].student_id,(original + mid)->student_id);
			strcpy(temp[joy].type,(original + mid)->type);
			strcpy(temp[joy].age,(original + mid)->age);

			mid++;
		joy++;
	}//end if...else statement

	low = start;
	joy = 0;

	while (low < high && joy < count)
	{
		//writing
		strcpy((original + low)->firstname,temp[joy].firstname);
		strcpy((original + low)->surname,temp[joy].surname);
		strcpy((original + low)->student_id,temp[joy].student_id);
		strcpy((original + low)->type,temp[joy].type);
		strcpy((original + low)->age,temp[joy].age);

		low++;
		joy++;
	}//end while loop
}//end merge()


/*****************************************************************************************
The following is the insertion function This will use the passed parameters to sort the array
within the main function and when called by the merge function
*****************************************************************************************/

void insertion_sort (int count, int low, int high, struct student_details *original)
{
	//strcture variables
	struct student_details temp;

	//variables to compare with
	char student_idefication_1 [STUDENT_ID], student_idefication_2 [STUDENT_ID];

	//other variables
	int index, okie, dokie, statement;


	for (okie = 1; okie < count; okie++)
	{
		dokie = okie;
		statement = t;

		while (dokie != 0 && statement != f)
		{
			//intailising the variables
			strcpy(student_idefication_1, (original + dokie)->student_id);
			strcpy(student_idefication_2,(original + (dokie - 1))->student_id);

			//to get rid of the letter so we can use the atol function
			for (index = 0; index < STUDENT_ID && (index + 1) < STUDENT_ID; index++)
			{
				student_idefication_1[index] = student_idefication_1[index + 1];
				student_idefication_2 [index] = student_idefication_2 [index + 1];
			} //end for loop

			//now checking which variables are bigger and which are smaller
			if (atol(student_idefication_1) < atol(student_idefication_2))
			{
				//storing the contents into a tempoarary array
				strcpy(temp.firstname,(original + dokie)->firstname);
				strcpy(temp.surname,(original + dokie)->surname);
				strcpy(temp.student_id,(original + dokie)->student_id);
				strcpy(temp.type,(original + dokie)->type);
				strcpy(temp.age,(original + dokie)->age);

				//moving the bigger contents up one
				strcpy((original + dokie)->firstname,(original + (dokie - 1))->firstname);
				strcpy((original + dokie)->surname,(original + (dokie - 1))->surname);
				strcpy((original + dokie)->student_id,(original + (dokie - 1))->student_id);
				strcpy((original + dokie)->type,(original + (dokie - 1))->type);
				strcpy((original + dokie)->age,(original + (dokie - 1))->age);

				//moving the temparary location into place
				strcpy((original + (dokie - 1))->firstname, temp.firstname);
				strcpy((original + (dokie - 1))->surname,temp.surname);
				strcpy((original + (dokie - 1))->student_id,temp.student_id);
				strcpy((original + (dokie - 1))->type,temp.type);
				strcpy((original + (dokie - 1))->age,temp.age);

				dokie--;

			}

			else
			{
				statement = f;
			}//end if..else statement
		}//end while loop

	}//end for loop()

}//end insertion()
