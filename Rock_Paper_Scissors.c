// Program to make a rock, paper & scissor game
//  Author : Hello Coder! I'm Joy and I made this simple game using C language.
//           I hope this game will help you for better understanding the logic.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void instructions();
int generateRandomNumber(int); // This is used to generate random numbers in a given range
char *selected_option(int);    // This is used to show the selected option, this function returns a string value

int main()
{
    int i, rule, player_choice, computer_choice, player_points = 0, computer_points = 0, restart, validity;
    char player_name[30];
    printf("Welcome to ROCK, PAPER & SCISSORS Game!\n");
    printf("\nDo you know the rules?\n");
    printf("If you don't know the rules then enter 1 to skip this press any key.\n");
    fflush(stdin);
    scanf("%d", &rule);
    if (rule == 1) // Rules of the game
    {
        instructions();
    }
    printf("\nLet's start the game.\n"); // Game started
    fflush(stdin);
    printf("\nPlease enter your name : "); // Taking the name of the player
    scanf("%s", &player_name);             // You can also use gets(player_name); and fgets(player_name, 30, stdin);
    fflush(stdin);

    do
    {
        printf("\nEnter 1 for Rock, 2 for Paper & 3 for Scissors.\n");
        for (i = 1; i <= 3; i++) // Main game loop
        {
            printf("\nRound %d is starting ...\n", i); // Round starting notification

            printf("\nHi %s it's your turn.\n", player_name); // Player's turn
            do
            {
                scanf("%d", &player_choice);

                if (player_choice < 1 || player_choice > 3) // In case if player enter a wromg option
                {
                    printf("\nINVALID OPTION!\nCHOOSE ONLY BETWEEN 1, 2 & 3 : ");
                    fflush(stdin);
                    validity = 0;
                }
                else
                {
                    validity = 1;
                }

            } while (validity == 0);

            printf("You chose %s!\n", selected_option(player_choice));

            // Computer's turn
            printf("\nComputer is choosing ... \n");
            computer_choice = generateRandomNumber(2) + 1;
            printf("\nThe computer chose %s!\n", selected_option(computer_choice));

            // Condition where player wins
            if ((player_choice == 2 && computer_choice == 1) || (player_choice == 3 && computer_choice == 2) || (player_choice == 1 && computer_choice == 3))
            {
                printf("\nRound result : %s wins.\nPoint --> +1\n", player_name);
                player_points++;
            }

            else if (player_choice == computer_choice)
            {
                printf("\nRound result : Draw!\n");
            }

            else
            {
                printf("\nRound result : Computer wins!\nPoint --> +1\n");
                computer_points++;
            }

            printf("\nCurrent score is : \n%s --> %d points.\nComputer --> %d points.\n", player_name, player_points, computer_points); // Total score at the end of the round
        }
        if (player_points > computer_points)
        {
            printf("\nCongratulations %s!\nYou have won.\n", player_name);
        }
        else if (player_points < computer_points)
        {
            printf("\nOops!\nComputer has won.\nBetter luck next time.\n");
        }
        else
        {
            printf("\nMatch is ended with Draw!\nBetter luck next time.\n");
        }
        printf("\nDo you want to play again?\nEnter 1 to restart otherwise enter anything.\n");
        scanf("%d", &restart);
        if (restart == 1) // To play again
        {
            printf("Hey %s good luck!", player_name); // Send the control to the main for loop
            player_points = 0;
            computer_points = 0;
        }
    } while (restart == 1);

    printf("\nThank you for playing this game %s.", player_name);
    return 0;
}

void instructions()
{
    printf("The rules are very simple.\n");
    printf("Rock vs Scissors --> Rock wins.\n");      // 1 vs 3 --> 1 wins.
    printf("Rock vs Paper --> Paper wins.\n");        // 1 vs 2 --> 2 wins.
    printf("Paper vs Scissors --> Scissors wins.\n"); // 2 vs 3 --> 3 wins.
    printf("If both are same then it's draw.\n");
    printf("You will get points each round for wining the round.\n");
}

int generateRandomNumber(int n) // Random number generator
{
    srand(time(NULL));
    return rand() % n;
}

char *selected_option(int n) // Decides rock, paper or scissors
{
    char *option;
    if (n == 1)
    {
        option = "Rock";
    }
    else if (n == 2)
    {
        option = "Paper";
    }
    else
    {
        option = "Scissor";
    }
    return option;
}
