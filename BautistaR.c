#include <stdio.h>
#include <string.h>

typedef char String20 [21];
typedef char String30 [31];
typedef char String150 [151];

struct questionRecord
{
    String20 topic;
    int number;
    String150 question;
    String30 choice1;
    String30 choice2; 
    String30 choice3;
    String30 answer;
};

/*
displayIntro displays the introductory message for the player to know what they are playing.
*/

void displayIntro()
{
    printf("Welcome to Quizlet!\n");
    printf("A two player general knowledge quiz game.\n");
}


 /* 
 displayMainMenu displays the main menu with a user-friendly text based interface.
 @returns the players choice among M, P, or E
 */

char displayMainMenu()
{
    char cChoice;
    printf("You are now viewing the Main Menu. Please choose a mode:\n[M]anage Data as an admin\n[P]lay the game as a player\n[E]xit the program\n");
    do
    {
        printf("Enter your choice: \n");
        scanf(" %c", &cChoice);
        if (cChoice != 'M' && cChoice != 'P' && cChoice != 'E')
        {
            printf("Invalid input!\n");
        }
    } while (cChoice != 'M' && cChoice != 'P' && cChoice != 'E');
    return cChoice;
}


 /* 
 displayMainMenu displays the player menu with a user-friendly text based interface.
 @returns the players choice among P, V, or E
 */

char displayPlayMenu()
{
    char cChoice;
    printf("You are now viewing the Play Menu. Please choose a mode:\n[P]lay\n[V]iew Scores\n[E]xit\n");
    do
    {
        printf("Enter your choice: \n");
        scanf(" %c", &cChoice);
        if (cChoice != 'P' && cChoice != 'V' && cChoice != 'E')
        {
            printf("Invalid input!\n");
        }
    } while (cChoice != 'P' && cChoice != 'V' && cChoice != 'E');
    return cChoice;
}

int main()
{
    char cMode, cPlayMode, cAdminMode;
    displayIntro();
    while(cMode != 'E')
    {
        cMode = displayMainMenu();
        if (cMode == 'M')
        {
            printf("You chose Manage Data!\n");
        }
        if (cMode == 'P')
        {
            do
            {
                cPlayMode = displayPlayMenu();
                if(cPlayMode == 'P')
                {
                    printf("You chose Play!\n");
                }
                if(cPlayMode == 'V')
                {
                    printf("You chose View Scores!\n");
                }
            } while (cPlayMode != 'E');
        }
    }
    return 0;
}