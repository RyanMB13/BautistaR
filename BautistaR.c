/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.
Ryan Matthew Mabanag Bautista, DLSU ID# 12113972
*********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <conio.h>

#define SIZE 30

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
struct playerRecord
{
    String20 name;
    int score;
    char ch;
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
@returns the players choice among 1 or 0.
*/

char displayPasswordMenu()
{
    char cChoice;
    printf("\nYou have entered the wrong password. Please choose between:\n[1]Try again\n[0]Back to main menu\n");
    do
    {
        printf("Enter your choice: \n");
        scanf(" %c", &cChoice);
        if (cChoice != '1' && cChoice != '0')
        {
            printf("Invalid input!\n");
        }
    }   while (cChoice != '1' && cChoice != '0');
    return cChoice;
}

/*
addRecord allows the user to add a record if their question and answer input are unique. If the input is already present, the function indicates it.
@param questionRecord *A the array of structures that stores the information about the questions.
@param n the maximum number of array elements
*/
void addRecord(struct questionRecord *A, int n)
{
    int i;
    int nNumber = 0;
    int bQuestionAlreadyPresent;
    int bAnswerAlreadyPresent;
    String20 sTopic;
    String30 sAnswer, sChoice1, sChoice2, sChoice3;
    String150 sQuestion;
    printf("Please input a question: \n");
    scanf(" %[^\n]s", sQuestion);
    printf("Please input an answer: \n");
    scanf(" %[^\n]s", sAnswer);
    for (i = 0; i < n; i++)
    {
        bQuestionAlreadyPresent = strcmp(sQuestion, (A+i)->question);
        bAnswerAlreadyPresent = strcmp(sAnswer, (A+i)->answer);
    }
    if (bQuestionAlreadyPresent == 0 && bAnswerAlreadyPresent == 0)
    {
        printf("Topic: %s\n", (A+i)->topic);
        printf("Question Number: %d\n", (A+i)->number);
        printf("Question: %s\n", (A+i)->question);
        printf("Choice 1: %s\n", (A+i)->choice1);
        printf("Choice 2: %s\n", (A+i)->choice2);
        printf("Choice 3: %s\n", (A+i)->choice3);
        printf("Answer: %s\n", (A+i)->answer);
        printf("The question and answer are already listed in the records.\n");
    }
    if (bQuestionAlreadyPresent != 0 && bAnswerAlreadyPresent != 0)
    {
        printf("Question: %s\n", sQuestion);
        printf("Answer: %s\n", sAnswer);
        printf("Please input a topic: \n");
        scanf(" %[^\n]s", sTopic);
        printf("Please input choice 1: \n");
        scanf(" %[^\n]s", sChoice1);;
        printf("Please input choice 2: \n");
        scanf(" %[^\n]s", sChoice2);;
        printf("Please input choice 3: \n");
        scanf(" %[^\n]s", sChoice3);
        for (i = 0; i < n; i++)
        {
            if(strcmp(sTopic, (A+i)->topic) == 0)
            {
                nNumber += 1;
            }
        }
        for (i = 0; i < n; i++)
        {
            if ((A+i)->number == '\0' )
            {
                strcpy((A+i)->topic, sTopic);
                (A+i)->number = nNumber;
                strcpy((A+i)->question, sQuestion);
                strcpy((A+i)->choice1, sChoice1);
                strcpy((A+i)->choice2, sChoice2);
                strcpy((A+i)->choice3, sChoice3);
                strcpy((A+i)->answer, sAnswer);
            }

        }
    }
    
}

int main()
{
    int i = 0;
    int j = 0;
    int bPassword = 0;
    int bAskPassword = 1;
    int bMatchingPassword;
    char ch;
    String30 sAdminPassword, sInputPassword;
    char cMode, cPlayMode, cAdminMode, cPasswordMode;
    struct questionRecord questionItems[SIZE];
    displayIntro();
    while (cMode != 'E')
    {
        cMode = displayMainMenu();
        bAskPassword = 1;
        if (cMode == 'M')
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
            if (bPassword == 1 && bAskPassword == 1)
            {
                do
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
                    j = 0; // input password reset
                    sInputPassword[0] = '\0'; // input password reset
                    if (bMatchingPassword != 0)
                    {
                        cPasswordMode = displayPasswordMenu();
                        if (cPasswordMode == '1')
                        {
                            bAskPassword = 1;
                        }
                        if (cPasswordMode == '0')
                        {
                            cAdminMode = 'B';
                            bAskPassword = 0;
                        }
                    }
                } while (bMatchingPassword != 0 && bAskPassword == 1);
                if (bMatchingPassword == 0)
                {
                    printf("\nYou have entered the correct password.\n");
                    do
                    {
                        bAskPassword = 0;
                        cAdminMode = displayAdminMenu();
                        if (cAdminMode == 'A')
                        {
                            printf("You chose Add a record!\n");
                            addRecord(questionItems, SIZE);
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
                    } while (cAdminMode != 'B');
                }
            }
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
