#include <stdio.h>
#include <string.h>
#include <conio.h>

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
    printf("A two player general knowledge quiz game!\n");
}

 /* 
 displayMainMenu displays the main menu with a user-friendly text based interface.
 @returns the players choice among M, P, or E.
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
 @returns the players choice among P, V, or E.
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

/* 
 displayMainMenu displays the player menu with a user-friendly text based interface.
 @returns the players choice among A, C, D, I, E, B.
 */

char displayAdminMenu()
{
    char cChoice;
    printf("You are now viewing the Admin Menu. Please choose a mode:\n[A]dd a record\n[C]hange a record\n[D]elete a record\n[I]mport data\n[E]xport data\n[B]ack to the main menu.\n");
    do
    {
        printf("Enter your choice: \n");
        scanf(" %c", &cChoice);
        if (cChoice != 'A' && cChoice != 'C' && cChoice != 'D' && cChoice != 'I' && cChoice != 'E' && cChoice != 'B')
        {
            printf("Invalid input!\n");
        }
    } while (cChoice != 'A' && cChoice != 'C' && cChoice != 'D' && cChoice != 'I' && cChoice != 'E' && cChoice != 'B');
    return cChoice;
}

/* 
 displayPasswordMenu displays the password menu with a user-friendly text based interface.
 @returns the players choice among T or B.
 */

char displayPasswordMenu()
{
    char cChoice;
    printf("You have entered the wrong password. Please choose between:\n[T]ry again\n[B]ack to main menu\n");
    do
    {
        printf("Enter your choice: \n");
        scanf(" %c", &cChoice);
        if (cChoice != 'T' && cChoice != 'B')
        {
            printf("Invalid input!\n");
        }
    }   while (cChoice != 'T' && cChoice != 'B');
    return cChoice;
}

int main()
{
    int i = 0;
    int j = 0;
    int bPassword = 0;
    int bMatchingPassword;
    char ch;
    String30 sAdminPassword, sInputPassword, sInputPassword2;
    char cMode, cPlayMode, cAdminMode, cPasswordMode;
    displayIntro();
    while (cMode != 'E')
    {
        cMode = displayMainMenu();
        if (cMode == 'M')
        {
           do 
           {
                if (bPassword == 0)
                {
                    printf("Please enter a password: \n");
                    while((ch = _getch()) != 13)
                    {
                        sAdminPassword[i] = ch;
                        i++;
                        printf("*");
                    }
                    sAdminPassword[i] = '\0';
                    printf("\nYou have successfully set an admin password!\n");
                    bPassword = 1;
                }
                if (bPassword == 1)
                {
                    printf("Please enter the admin password: \n");
                    while((ch = _getch()) != 13)
                    {
                        sInputPassword[j] = ch;
                        j++;
                        printf("*");
                    }
                    sInputPassword[j] = '\0';
                    bMatchingPassword = strcmp(sAdminPassword, sInputPassword);
                    if(bMatchingPassword != 0)
                    {
                        // code to check again or return to main menu
                    }
                    if (bMatchingPassword == 0)
                    {
                        printf("\nYou have entered the correct password.\n");
                        cAdminMode = displayAdminMenu();
                        if (cAdminMode == 'A')
                        {
                            printf("You chose Add a record!\n");
                        }
                        if (cAdminMode == 'C')
                        {
                            printf("You chose Change a record!\n");
                        }
                        if (cAdminMode == 'D')
                        {
                            printf("You chose Delete a record!\n");
                        }
                        if (cAdminMode == 'I')
                        {
                            printf("You chose Import data!\n");
                        }
                        if (cAdminMode == 'E')
                        {
                            printf("You chose Export data!\n");
                        }
                    }
                }
            } while (cAdminMode != 'B');
        }
        if (cMode == 'P')
        {
            do
            {
                cPlayMode = displayPlayMenu();
                if (cPlayMode == 'P')
                {
                    printf("You chose Play!\n");
                }
                if (cPlayMode == 'V')
                {
                    printf("You chose View Scores!\n");
                }
            } while (cPlayMode != 'E');
        }
    }
    return 0;
}
