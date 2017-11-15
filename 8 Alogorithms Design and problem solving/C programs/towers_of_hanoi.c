/*This program is using a recursive call function to demonstrate the game "Towers of Hanoi"
by moving the pieces required in a given order so the game can move the pieces itself
13-02-2017
William Carey
*/

#include <stdio.h>

//function protype

void Tower_of_hanoi (int, char, char, char);

void main()
{
	char stick_1, stick_2, stick_3;
	stick_1 = '1';
	stick_2 = '2';
	stick_3 = '3';
	int disks;

	printf("Please enter the number of disks you want to use in the game of the Tower of hanoi\n");
	scanf("%d",&disks);

	Tower_of_hanoi(disks, stick_1,stick_2,stick_3);

	fflush(stdin);

	getchar();
}//end main


void Tower_of_hanoi (int diskS, char source, char dest, char spare)
{
	if (diskS == 0)
	{
		//move disk from source to dest

		printf("\nMoving disk number %d to destination %c\n",diskS, dest);
	}

	else
	{
		Tower_of_hanoi((diskS - 1), source, spare, dest);

		//move disk from source to dest

		printf("\nMoving disk number %d to destination %c\n",diskS, dest);

		Tower_of_hanoi((diskS - 1), spare, dest, source);
	}
}
