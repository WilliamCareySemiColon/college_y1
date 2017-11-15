/* Description: To operate a machine that shares silmilar
qualities to an A.T.M. machine for a bank
Author: William Carey
Date Started: 30-10-2016
*/

#include <stdio.h>

#define array_size 4


int main()
{
    int option = 0;
    int personal_idenfication_number [array_size] = {1,2,3,4};
    int count_for_case_1 = 0;
    int count_for_case_1_right = 0;
    int count_wrong = 0;
    int count_right = 0;
    int count_for_case_2 = 0;
    int count_for_case_2_right = 0;
    int checker [array_size] = {0,};
    int new_pin_1 [array_size] = {0,};
    int new_pin_2 [array_size] = {1,};



    /*The following is the procedure of an atm machine, since all atm machines does not have characters except numbers
    we can stick to integers. The do while loop can be an while as either would work
    */



    do
    {


        printf("\nYou have the following options\n"); //from this point onwords, the "\n" used before the sentence are used to make the output more readable
        printf("\n 1:To vertify your pin\n");
        printf("\n 2: To change your pin\n");
        printf("\n 3: To display the amount of times you have entered your pin (i) Correct and (ii) incorrect\n");
        printf("\n 4: Exit the program\n");
        printf("\n so pick which option you want\n");

        scanf("%d",&option);
        system("cls");   //This clears te screen, so the user can focues on what they want to do

        switch (option)
        {
            /*Case 1 is checking to make sure your pin is correct using an for loop and if..else if..else statement
            */
            case 1:
                {
                        printf("please enter your pin\n");

                        for (count_for_case_1 = 0; count_for_case_1 < array_size; count_for_case_1 ++)
                        {
                            scanf("%d",&checker[count_for_case_1]);

                                if (checker[count_for_case_1] != personal_idenfication_number [count_for_case_1])
                                {
                                    printf("your pin is invalid\n");
                                    count_wrong ++;
                                    break;
                                }//end if satementin case 1

                                else if (checker[count_for_case_1] == personal_idenfication_number [count_for_case_1])
                                {
                                    count_for_case_1_right++;
                                } //end else statement for case 1

                                if (count_for_case_1_right == array_size)
                                    {
                                        printf("your pin is correct");
                                        count_right ++;
                                    } //end final if staement for case 1
                        } //end for loop for case 1



                        break;
                } //end case 1

            /*case 2 is the option to change your pin. It checks to make sure you enter your pin correct when you want to change your pin
            */
            case 2:
                {
                        printf("\nplease enter your new pin one by one, each time pressing enter\n");

                        for ( count_for_case_2 = 0; count_for_case_2 < array_size; count_for_case_2 ++)
                        {
                            scanf("%d",&new_pin_1[count_for_case_2]);

                            if (-1 > new_pin_1 [count_for_case_2])
                            {
                                printf("\n Invalid pin\n");
                                break;
                            }
                            else if (new_pin_1 [count_for_case_2] > 10)
                            {
                                printf("\n Invalid pin\n");
                                break;
                            }

                            else
                            {
                                printf("\n It is valid \n");
                            }
                        }//end for loop for pin 1

                           system("cls");
                            printf("\n Please re-enter your new pin\n");

                             for ( count_for_case_2 = 0; count_for_case_2 < array_size; count_for_case_2 ++)
                                {
                                    scanf("%d",&new_pin_2[count_for_case_2]);

                                    if (-1 > new_pin_2 [count_for_case_2])
                                        {
                                            printf("\n Invalid pin\n");
                                            break;
                                        }
                                    else if (new_pin_2 [count_for_case_2] > 10)
                                        {
                                            printf("\n Invalid pin\n");
                                            break;
                                        }
                                    else
                                        {
                                            printf("\n It is valid \n");
                                        }
                                } //end loop for second pin

                                for ( count_for_case_2 = 0; count_for_case_2 < array_size; count_for_case_2 ++)
                                {
                                    if (new_pin_1 [count_for_case_2] != new_pin_2 [count_for_case_2])
                                    {
                                        printf("your pin does not match");

                                        break;
                                    } //end if staement

                                    else
                                    {
                                                personal_idenfication_number [count_for_case_2] = new_pin_1 [count_for_case_2];
                                                count_for_case_2_right ++;

                                    }

                                 if ( count_for_case_2_right == array_size)
                                 {
                                     printf("\n Thank you, you're new pin is %d %d %d %d\n",personal_idenfication_number [0], personal_idenfication_number [1], personal_idenfication_number [2], personal_idenfication_number [3] );
                                 }

                                }





                                    break;
                    }//end case 2



            case 3:
                    {
                        printf("\n You have entered you pin %d times right and %d times wrong\n", count_right, count_wrong);
                        break;
                    }//end case 3

            case 4:
                    {
                        printf("\n Thank you and please come again");
                        break;

                    }//End case 4

            default:
                    {
                        printf("\nThat is not one of the options\n");
                    }

            }//End Switch

    }   while ( option != 4);


    fflush(stdin);

    getchar();

    return(0);

}//End main
