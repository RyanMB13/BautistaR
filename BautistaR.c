#include <stdio.h>
#include <string.h>

typedef char String50 [51];
 /* displayMainMenu displays the main menu with a user-friendly (text based interface)
 @returns the players choice among M, P, or E
 */
char displayMainMenu()
{
    char cChoice;
    printf("Please choose a mode:\n [M]anage Data\n [P]lay\n [E]xit\n");
    scanf("%c", &cChoice);
    do
    {
        if (cChoice != 'M' && cChoice != 'P' && cChoice != 'E')
        {
            printf("Invalid input!\n");
        }
    } while (cChoice != 'M' && cChoice != 'P' && cChoice != 'E');
    return cChoice;
}


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




int main()
{
    char cMode;
    while(cMode != 'E')
    {
        cMode = displayMainMenu();
        if (cMode == 'M')
        {

        }
        if (cMode == 'P')
        {

        }
    }
    return 0;
}