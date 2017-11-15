/*Descrition: To take six numbers, display them all.
Then display the biggest, the smallest and the average
 of all the variables
 Author: William Carey
 Date: 08-11-2016
 */

 # include <stdio.h>

 # define row 3
 # define col 2
 # define source_1 0

 int main()
 {
  int Two_D_Array [row][col] = {0,};
  int count_for_loop_1 = 0;
  int count_for_loop_2 = 0;
  int smallest_value = 0;
  int largest_value = 0;
  int total = 0;
  float average = 0;

  printf("Please input six numbers individually \n");

  for (count_for_loop_1 = 0; count_for_loop_1 < row; count_for_loop_1 ++)
  {
      for (count_for_loop_2 = 0; count_for_loop_2 < col; count_for_loop_2 ++)
      {
          scanf("%d",&Two_D_Array [count_for_loop_1][count_for_loop_2]);
      } //end inner for loop 1
  }//end outer for loop 1

  for (count_for_loop_1 = 0; count_for_loop_1 < row; count_for_loop_1 ++)
  {
    for   (count_for_loop_2 = 0; count_for_loop_2 < col; count_for_loop_2 ++)
        {
            printf("%d is in %d %d postion\n", Two_D_Array [count_for_loop_1] [count_for_loop_2], count_for_loop_1,
                   count_for_loop_2);
        } //end  inner for loop 2
  } //end outer for loop 2

  smallest_value = Two_D_Array [source_1][source_1];

  for (count_for_loop_1 = 0; count_for_loop_1 < row; count_for_loop_1 ++)

  {
      for (count_for_loop_2 = 0; count_for_loop_2 < col; count_for_loop_2 ++)
      {
          if (smallest_value > Two_D_Array [count_for_loop_1][count_for_loop_2])
          {
              smallest_value = Two_D_Array [count_for_loop_1][count_for_loop_2];
          }//end if statement inside for loop 3
      } //end inner for loop 3
  }// end outer for loop 3

  printf("\nThe smallest value in the array is %d\n",smallest_value);

  largest_value = Two_D_Array [source_1][source_1];

  for (count_for_loop_1 = 0; count_for_loop_1 < row; count_for_loop_1 ++)

  {
      for (count_for_loop_2 = 0; count_for_loop_2 < col; count_for_loop_2 ++)
      {
          if (largest_value < Two_D_Array [count_for_loop_1][count_for_loop_2])
          {
              largest_value = Two_D_Array [count_for_loop_1][count_for_loop_2];
          }//end if statement inside for loop 4
      } //end inner for loop 4
  }// end outer for loop 4

  printf("\nThe largest value in the array is %d\n",largest_value);

   for (count_for_loop_1 = 0; count_for_loop_1 < row; count_for_loop_1 ++)

  {
      for (count_for_loop_2 = 0; count_for_loop_2 < col; count_for_loop_2 ++)
      {
          total = total + Two_D_Array [count_for_loop_1][count_for_loop_2];
      } //end inner for loop 5
  }// end outer for loop 5

  printf("\nThe Total amount by adding all the numbers is %d\n",total);

  average = (float) total / (row*col);

  printf("\nThe average nummber between all the inputed numbers is %.2f\n",average);

  fflush(stdin);

  getchar();

  return(0);

 }//end main
