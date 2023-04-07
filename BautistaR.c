#include <stdio.h>
#include <string.h>

typedef char String50 [51];

 /* displayMainMenu displays the main menu with a user-friendly (text based interface)
 @returns the players choice among M, P, or E
 */

char displayMainMenu()
{
    char cChoice;
    printf("Please choose a mode:\n [M]anage Data as an admin\n [P]lay the game as a player\n [E]xit the program\n");
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


 /* displayMainMenu displays the main menu with a user-friendly (text based interface)
 @returns the players choice among P, V, or E
 */

char displayPlayMenu()
{
    char cChoice;
    printf("Please choose a mode:\n [P]lay\n [V]iew Scores\n [E]xit\n");
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

/*
int 
validPassword(String50 Password){
    
    char userInput;
    if (strlen(Password) == strlen(userInput) && strcmp(Password, userInput) == 0)
    {

        return 1;
    }
    else
    {
        return 0;
    }
} 
*/



int main()
{
    char cMode, cPlayMode;
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