/*

This program uses pointer notation,pass by reference and functions outside of main.Firstly it takes in a 4 digit array,
Encrypt that array and check if those 4 digits entered match access_code which is a preset code.
Then it decrypt that code.It will also display the ammout of times the code matchs access_code and 
display either correct times or incorrect times. Finally it can be ended piecefully by pressing 5 in the menu. 
The menu will continue to run and repeat back to menu unless the user specifially asks the program to end.

Author : Eoin O'Toole Carrick
Date Editied : 4/03/2021
Compiler : VSC

*/


#include <stdio.h>
#include <stdlib.h>

#define SIZE 4 //defining size of arrays

int access_code[SIZE];
void user_input(int *); // function for code input in function
void menu(); // function for menu
void encrypt(int *, const int *, int *, int * ,int *); // function to encrypt the code entered
void decrypt(int *,int *,int *); // function to decrypt the code that was entered
void print_attempts(int *, int *);// function to display the ammount of times the code entered matchs access_code
void exit_option(int *,int *);

int main(void) //start main
{
    
    int menu_num = 0;
    int new_input[SIZE];
    const int access_code[SIZE] = {4, 5, 2, 3};
    int Correct = 0;
    int Incorrect = 0;
    int check = 0;
    int check_input = 0;
    int check2 = 0;
    int exit_option1 = 0;

    while (menu_num != 5) // loop menu unless you enter 5
    {
        menu();
        printf("\n\nEnter: ");
        scanf("%d", &menu_num); // to take in menu option
        getchar(); // to try and catch characters 

        switch (menu_num)
        {
            case 1: // option 1 to input numbers into array
            {
                user_input(new_input);

                check_input = check_input + 1; // adding 1 for option 3 check

                check2 = check2 + 1; // adding 1 for option 2 check

                break;
            }
        

            case 2: // option 2 to encrypt code and check if it matchs access_code and display
            {
                encrypt(new_input, access_code, &Correct, &Incorrect,&check_input);

                check = check + 1; // adding 1 for the check

                check_input = 0; // resetting value to check if option 1 was done before option 2

                break;
            }


            case 3: //  option 3 to decrypt code and display 
            {
                decrypt(new_input,&check,&check2);
                
                check = 0; // resetting the value of the check if option 2 was done before option 3

                check2 = 0;  // resetting the check to see if option 1 was done before option 2 and then option 3
                
                break;
            }


            case 4: //option 4 to display the ammout of times the code entered matchs correctly or incorrectly 
            {
                print_attempts(&Correct, &Incorrect);

                break;
            }


            case 5: // option 5 to end the program gracefully
            {
                exit_option(&menu_num,&exit_option1);

                if (exit_option1 == 2)
                {
                    menu_num = 1;
                }
                if (exit_option1 == 1)
                {
                    printf("\nThank you for using my code\n\n");
                }
                else
                {
                    printf("\nPlease enter a number for an option listed above");

                    menu_num = 1;

                }
                

                break;
            }

            
            default: // If the wrong charecter was entered then goes here and displays error message
            {
                printf("The number you have entered is wrong please try again");

                break;
            }
        }


    } 
    

    return 0;
}//end main

void user_input(int *new_input)
{//start function
    int i;
    
    printf("Please enter your 4 digit code\n ");

    for ( i = 0; i < SIZE; i++)// start for
    {
        scanf("%d", & *(new_input + i)); // input into array
        getchar();

        if (*(new_input + i) < 0 || *(new_input + i) > 9)// to check if number is greater than 0 and less than 9
        {//start if
            printf("The number you have entered is wrong please try again");
            i = i - 1;
        }//end if
        
    } //end for 


    for ( i = 0; i < SIZE; i++)//start for 
    {
        printf("%d", *(new_input + i)); //print array 
        
    } // end for 
    return;
    
}//end function


void menu() // function for menu
{//start function

    printf("\n\n********************            Menu            *************************");
    printf("\n\nChoose an option:");
    printf("\n\n 1. Enter any code");
    printf("\n 2. Encrypt code entered and verify if correct");
    printf("\n 3. Decrypt code");
    printf("\n 4. Display the number of times the encrypted code entered matches the authorised code (i) Successfully (ii) Incorrectly");
    printf("\n 5. Exit Program");
    printf("\n\n*************************************************************************");

}//end function

void encrypt(int *new_input,const int *access_code,int *Correct, int *Incorrect , int *check_input)
{//start function
    int temp;
    int i;
    
    if (*check_input == 1) // to check if option 1 was done before option 2
    {
        temp = *new_input;              //Code to swap the 1st number and the 3rd number
        *new_input = *(new_input + 2);  
        *(new_input + 2) = temp;

        temp = *(new_input + 1);        // code to swap the 2nd number and the 4th number
        *(new_input + 1) = *(new_input + 3);
        *(new_input + 3) = temp;

        for (i = 0; i < SIZE; i++) // start for 
	    {
		*(new_input + i) = *(new_input + i) + 1;        // adds 1 number to each digit
        }  // end for
    

        for (i = 0; i < SIZE; i++) // start for
        {
            if (*(new_input + i) == 10) // if number is = 10 make it = 0
		    {
                *(new_input + i) = 0;
            }
	    } // end for 

        printf("\nYour encrypted code is now  ");

	    for ( i = 0; i < SIZE; i++) // start for
        {

            printf("%d",*(new_input + i)); // code to print the encrypted code

        } // end for

	    for (i = 0; i < SIZE; i++)// start for
	    {
		    if (*(new_input + i) != *(access_code + i)) // to check if the user input matchs access_code and if not display the printf below
		    {
			    printf("\n\nThe code you have entered doesnt match\n");

			    *Incorrect = *Incorrect + 1; // add 1 to Incorrect

			    return;
		    }
	    } //  end for 
    
        printf("\n\nThe code you have entered matchs Congrats!!!\n"); // print if codes match

        *Correct = *Correct + 1; // adds 1 to correct
    }

    else
    {
        printf("\nPlease input a code in option 1 before using option 2\n"); // prints if option 1 hasnt been done first
    }

    return;

}// end function
void decrypt(int *new_input, int *check, int *check2) // function to decrypt array
{//start function
    int i;
    int temp;
    
    if (*check2 == 1) // to check if option 1 and 2 have been done first
    {

        if (*check == 1) // to check if the user had done option 2 before option 3
        {
            for (i = 0; i < SIZE; i++) // start for 
            {
                *(new_input + i) = *(new_input + i) - 1; // taking away 1 from each digit
            } // end for 

            for (i = 0; i < SIZE; i++) // start for 
            {
                if (*(new_input + i) == -1) // if statement to check if number = -1 
                {
                    *(new_input + i) = 9; // if yes then change it to 9
                }
            } // end for 

            temp = *new_input;              // code to swap the 1st number with the 3rd number
            *new_input = *(new_input + 2);
            *(new_input + 2) = temp;

            temp = *(new_input + 1);        // code to swap the 2nd with the 4th number
            *(new_input + 1) = *(new_input + 3);
            *(new_input + 3) = temp;

            printf("\nThe Decrypted code is : "); // print the decrypted code

            for (i = 0; i < SIZE; i++)//start for 
            {
                printf("%d",*(new_input + i)); // print the decrypted code
            } // end for

            
        }

        else 
        {
            printf("\nPlease pick option 2 before choosing option 3\n");
        }
    }

    else 
    {
        printf("\nPlease input a code in option 1 then encrypt code in option 2 before decrypting the code\n");
    }
    
    return;
    
} // end function

void print_attempts(int *Correct, int *Incorrect) // function to display if the number of times the code matchs or not
{ //start function

    printf("\nNumber of times the code was correct: %d", *Correct); // displays the number of times they matchs
    printf("\nNumber of times the code was incorrect: %d\n", *Incorrect); // displays the number of times they do not match

} // end function

void exit_option(int *menu_num, int *exit_option1)
{
    printf("Are you sure you want to\n\n");
    printf("Choose 1 to exit or 2 to go back to menu : ");
    scanf("%d",exit_option1);
    return ;
}
