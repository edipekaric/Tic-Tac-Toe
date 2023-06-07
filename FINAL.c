#include <stdio.h>
#include <stdbool.h>

char fields[10] = {'0','1','2','3','4','5','6','7','8','9'};
int counter = 0; //If this number is even that means that X is on the move, and if it is odd then O is on the move
int xWins = 0, oWins = 0; //Counting how many wins O and X has

void grid();
void checkWin();
void clearBoard();

int main()
{
    int *ptr;                        //Declearing a pointer
    int choice;                      //Int that the user inputs for which grid number will be his sign
    int control = 0;                 //Controls if the game is over or not. If 0 then game is still playing
    ptr = &control;                  //Pointer points to adress of variable control
    printf("        Tic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("Type 0 for ending the sessions\n\n\n");
    do
    {
        grid();                      //Printing the grid
        char player;                 //Char X or O, which player is on the move
        if(counter % 2 == 0)         //Determening whether X or O is on the move
        {
            player = 'X';
        }
        else
        {
            void yellow();
            player = 'O';
            void reset();
        }
        error1:                     //if the user input a number that is not 1-9
        printf("Player %c, enter number: ", player);
        scanf("%i", &choice);       //Entering the number that the user inputs
        if(choice == 1 && fields[1] == '1')
        {
            fields[1] = player;     //If the user inputs 1, then that field will become a char that the
            counter++;              //player variable is at the time
        }
        else if(choice == 2 && fields[2] == '2')
        {
            fields[2] = player;     //If the user inputs 2, then that field will become a char that the
            counter++;              //player variable is at the time
        }
        else if(choice == 3 && fields[3] == '3')
        {
            fields[3] = player;     //If the user inputs 3, then that field will become a char that the
            counter++;              //player variable is at the time
        }
        else if(choice == 4 && fields[4] == '4')
        {
            fields[4] = player;     //If the user inputs 4, then that field will become a char that the
            counter++;              //player variable is at the time
        }
        else if(choice == 5 && fields[5] == '5')
        {
            fields[5] = player;     //If the user inputs 5, then that field will become a char that the
            counter++;              //player variable is at the time
        }
        else if(choice == 6 && fields[6] == '6')
        {
            fields[6] = player;     //If the user inputs 6, then that field will become a char that the
            counter++;              //player variable is at the time
        }
        else if(choice == 7 && fields[7] == '7')
        {
            fields[7] = player;     //If the user inputs 7, then that field will become a char that the
            counter++;              //player variable is at the time
        }
        else if(choice == 8 && fields[8] == '8')
        {
            fields[8] = player;     //If the user inputs 8, then that field will become a char that the
            counter++;              //player variable is at the time
        }
        else if(choice == 9 && fields[9] == '9')
        {
            fields[9] = player;     //If the user inputs 9, then that field will become a char that the
            counter++;              //player variable is at the time
        }
        else if(choice == 0)
        {
            //Stores 1 in adress of Pointer
            *ptr = 1;               //If the choice is 0, that means that the game has to end
            printf("Good game!\n"); //We set the control to 1 because of the do while loop, it exists the
            if(xWins > oWins)       //the do-while loop when the control is != 0
            {                       //Here we are checking who won the game until line 94
                printf("X wins the session with %i wins", xWins);
            }
            else if(oWins > xWins)
            {
                printf("O wins the session with %i wins", oWins);
            }
            else
            {
                printf("Its a draw!");
            }
        }
        else
        {
            //If the input is diferent then 0-9 then it will goto error1, so the value has to be input again
            printf("Invalid input, try again!\n");
            goto error1;
        }
        checkWin(); //When we have done the above code, i.e. we have entered a char into the grid we check for a win
    }
    while(*ptr == 0);
}

void grid()
{
    //Function for printing the grid
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", fields[1], fields[2], fields[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", fields[4], fields[5], fields[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", fields[7], fields[8], fields[9]);
    printf("     |     |     \n\n");
}

void checkWin()
{
    //Function for checking if there is a winner
    //"\033[31m" is for color red of text
    //"\033[0;33m" is for color yellow of text
    //"\033[0;35m" is for color purple of text
    //"\033[0m" is for default color of text
    if(fields[1] == 'X' && fields[2] == 'X' && fields[3] == 'X')
    {
        //If fields 1,2,3 are all X, X wins (Top horiztontally)
        xWins++;      //We add 1 onto the variable xWins because X has won
        clearBoard(); //Clearing the board
        printf("\n\n\n\033[31mX Wins!\033[0m\n\n\n"); //Printing that X won
    }
    else if(fields[4] == 'X' && fields[5] == 'X' && fields[6] == 'X')
    {
        //If fields 4,5,6 are all X, X wins (Middle horiztontally)
        xWins++;
        clearBoard();
        printf("\n\n\n\033[31mX Wins!\033[0m\n\n\n");
    }
    else if(fields[7] == 'X' && fields[8] == 'X' && fields[9] == 'X')
    {
        //If fields 7,8,9 are all X, X wins (Bottom horiztontally)
        xWins++;
        clearBoard();
        printf("\n\n\n\033[31mX Wins!\033[0m\n\n\n");
    }
    else if(fields[1] == 'X' && fields[4] == 'X' && fields[7] == 'X')
    {
        //If fields 1,4,7 are all X, X wins (Left vertically)
        xWins++;
        clearBoard();
        printf("\n\n\n\033[31mX Wins!\033[0m\n\n\n");
    }
    else if(fields[2] == 'X' && fields[5] == 'X' && fields[8] == 'X')
    {
        //If fields 2,5,8 are all X, X wins (Central vertically)
        xWins++;
        clearBoard();
        printf("\n\n\n\033[31mX Wins!\033[0m\n\n\n");
    }
    else if(fields[3] == 'X' && fields[6] == 'X' && fields[9] == 'X')
    {
        //If fields 3,6,9 are all X, X wins (Right vertically)
        xWins++;
        clearBoard();
        printf("\n\n\n\033[31mX Wins!\033[0m\n\n\n");
    }
    else if(fields[1] == 'X' && fields[5] == 'X' && fields[9] == 'X')
    {
        //If fields 1,5,9 are all X, X wins (Diagonally)
        xWins++;
        clearBoard();
        printf("\n\n\n\033[31mX Wins!\033[0m\n\n\n");
    }
    else if(fields[3] == 'X' && fields[5] == 'X' && fields[7] == 'X')
    {
        //If fields 3,5,7 are all X, X wins (Diagonally)
        xWins++;
        clearBoard();
        printf("\n\n\n\033[31mX Wins!\033[0m\n\n\n");
    }
    
    
    
    if(fields[1] == 'O' && fields[2] == 'O' && fields[3] == 'O')
    {
        //If fields 1,2,3 are all O, O wins (Top horiztontally)
        oWins++;
        clearBoard();
        printf("\n\n\n\033[0;33mO Wins!\033[0m\n\n\n");
    }
    else if(fields[4] == 'O' && fields[5] == 'O' && fields[6] == 'O')
    {
        //If fields 4,5,6 are all O, O wins (Middle horiztontally)
        oWins++;
        clearBoard();
        printf("\n\n\n\033[0;33mO Wins!\033[0m\n\n\n");
    }
    else if(fields[7] == 'O' && fields[8] == 'O' && fields[9] == 'O')
    {
        //If fields 7,8,9 are all O, O wins (Bottom horiztontally)
        oWins++;
        clearBoard();
        printf("\n\n\n\033[0;33mO Wins!\033[0m\n\n\n");
    }
    else if(fields[1] == 'O' && fields[4] == 'O' && fields[7] == 'O')
    {
        //If fields 1,4,7 are all O, O Wins (Left vertically)
        oWins++;
        clearBoard();
        printf("\n\n\n\033[0;33mO Wins!\033[0m\n\n\n");
    }
    else if(fields[2] == 'O' && fields[5] == 'O' && fields[8] == 'O')
    {
        //If fields 2,5,8 are all O, O Wins (Middle vertically)
        oWins++;
        clearBoard();
        printf("\n\n\n\033[0;33mO Wins!\033[0m\n\n\n");
    }
    else if(fields[3] == 'O' && fields[6] == 'O' && fields[9] == 'O')
    {
        //If fields 3,6,9 are all O, O Wins (Right vertically)
        oWins++;
        clearBoard();
        printf("\n\n\n\033[0;33mO Wins!\033[0m\n\n\n");
    }
    else if(fields[1] == 'O' && fields[5] == 'O' && fields[9] == 'O')
    {
        //If fields 1,5,9 are all O, O Wins (Diagonally)
        oWins++;
        clearBoard();
        printf("\n\n\n\033[0;33mO Wins!\033[0m\n\n\n");
    }
    else if(fields[3] == 'O' && fields[5] == 'O' && fields[7] == 'O')
    {
        //If fields 3,5,7 are all O, O Wins (Diagonally)
        oWins++;
        clearBoard();
        printf("\n\n\n\033[0;33mO Wins!\033[0m\n\n\n");
    }
    
    if(fields[1] != '1' && fields[2] != '2' && fields[3] != '3' && fields[4] != '4' && fields[5] != '5' && fields[6] != '6' && fields[7] != '7' && fields[8] != '8' && fields[9] != '9')
    {
        printf("\n\n\n\033[0;35mIts a draw!\033[0m\n\n\n");
        clearBoard();
    }
}

void clearBoard()
{
    //Function for restarting the board
    fields[1] = '1';
    fields[2] = '2';
    fields[3] = '3';
    fields[4] = '4';
    fields[5] = '5';
    fields[6] = '6';
    fields[7] = '7';
    fields[8] = '8';
    fields[9] = '9';
    counter = 0;
}