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
    int nCounter = 0;
    int nNumber = 0;
    int bRightChoice;
    int bQuestionAlreadyPresent;
    int bAnswerAlreadyPresent;
    String20 sTopic;
    String30 sAnswer, sChoice1, sChoice2, sChoice3;
    String150 sQuestion;
    printf("Please input a question: \n");
    scanf(" %[^\n]s", &sQuestion);
    printf("Please input an answer: \n");
    scanf(" %[^\n]s", &sAnswer);
    //checks how many records are present
    for (i = 0; i < n; i++)
    {
        if ((A+i)->number >= 1)
        {
            nCounter++;
        }
    }
    //checks if pair are already present
    for (i = 0; i < n; i++)
    {
        bQuestionAlreadyPresent = strcmp(sQuestion, (A+i)->question);
        bAnswerAlreadyPresent = strcmp(sAnswer, (A+i)->answer);
    }
    // if qna are already present
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
    // if qna are not yet present
    if (bQuestionAlreadyPresent != 0 && bAnswerAlreadyPresent != 0)
    {
        printf("Question: %s\n", sQuestion);
        printf("Answer: %s\n", sAnswer);
        printf("Please input a topic: \n");
        scanf(" %[^\n]s", &sTopic);
        do //loops until there is a match between choices and answer
        {
            printf("Please input choice 1: \n");
            scanf(" %[^\n]s", &sChoice1);
            printf("Please input choice 2: \n");
            scanf(" %[^\n]s", &sChoice2);
            printf("Please input choice 3: \n");
            scanf(" %[^\n]s", &sChoice3);
            if (strcmp(sAnswer, sChoice1) == 0 ||
                strcmp(sAnswer, sChoice2) == 0 ||
                strcmp(sAnswer, sChoice3) == 0)
            {
                bRightChoice = 1;
            }
            else
            {
                printf("None of the choices match with the answer.\nPlease try again.\n");
                bRightChoice = 0;
            }
        } while (bRightChoice != 1);
        for (i = 0; i < n; i++)
        {
            if(strcmp(sTopic, (A+i)->topic) == 0)
            {
                nNumber += 1;
            }
        }
        strcpy((A+nCounter)->topic, sTopic);
        (A+nCounter)->number = nNumber;
        strcpy((A+nCounter)->question, sQuestion);
        strcpy((A+nCounter)->choice1, sChoice1);
        strcpy((A+nCounter)->choice2, sChoice2);
        strcpy((A+nCounter)->choice3, sChoice3);
        strcpy((A+nCounter)->answer, sAnswer);
        printf("You have successfully added a record!\n");
    }
}

/*
changeRecord allows the user to edit a record.
@param questionRecord *A the array of structures that stores the information about the questions.
@param n the maximum number of array elements
*/
void changeRecord(struct questionRecord *A, int n)
{
    int i;
    int bCorrectInput;
    int nNumberOfQuestions = 0;
    int nInputNumber;
    char bDelete;
    char cChoice;
    String20 sTopic;
    String30 sAnswer, sChoice1, sChoice2, sChoice3;
    String150 sQuestion;
    do
    {
        printf("Would you like to change a record?\n[Y]es\n[N]o\n");
        do
        {
            printf("Enter your choice: \n");
            scanf(" %c", &bDelete);
            if (bDelete != 'Y' && bDelete != 'N')
            {
                printf("Invalid input!\n");
            }
        } while (bDelete != 'Y' && bDelete != 'N');
        if (bDelete == 'Y')
        {
            // prints the topic if the question number is equal to 1
            printf("The topics are: \n");
            for(i = 0; i < n; i++)
            {
                if((A+i)->number == 1)
                {
                    printf("%s\n", (A+i)->topic);
                }
            }
            printf("Please choose a topic to edit.\n");
            scanf(" %[^\n]s", &sTopic);
            // prints the question and question number if topic is the same as input
            for (i = 0; i < n; i++)
            {
                if (strcmp(sTopic, (A+i)->topic) == 0)
                {
                    printf("Question: %s\n", (A+i)->question);
                    printf("Question Number: %d\n", (A+i)->number);
                    nNumberOfQuestions += 1;
                }
            }
        do // loop to check if input is less than or equal to the number of questions under the topic.
        {
                printf("Please choose a question number to change.\n");
                scanf(" %d", &nInputNumber);
                if (nInputNumber > nNumberOfQuestions)
                {
                    printf("Invalid input!\n");
                    bCorrectInput = 0;
                }
                if (nInputNumber <= nNumberOfQuestions)
                {
                    bCorrectInput = 1;
                }
            } while (bCorrectInput != 1);
            printf("Topic: %s\n", (A+nInputNumber)->topic);
            printf("Question: %s\n", (A+nInputNumber)->question);
            printf("Choice 1: %s\n", (A+nInputNumber)->choice1);
            printf("Choice 2: %s\n", (A+nInputNumber)->choice2);
            printf("Choice 3: %s\n", (A+nInputNumber)->choice3);
            printf("Answer: %s\n", (A+nInputNumber)->answer);
            printf("Which field will be changed?\n[T]opic\n[Q]uestion\n[1]Choice 1\n[2]Choice 2\n[3]Choice 3\n[A]nswer\n");
            {
                printf("Enter your choice: \n");
                scanf(" %c", &cChoice);
                if (cChoice != 'T' && cChoice != 'Q' && cChoice != '1' && cChoice != '2' && cChoice != '3' && cChoice != 'A')
                {
                    printf("Invalid input!\n");
                }
            }   while (cChoice != 'T' && cChoice != 'Q' && cChoice != '1' && cChoice != '2' && cChoice != '3' && cChoice != 'A');
            if (cChoice == 'T')
            {
                printf("Please input a topic: \n");
                scanf(" %[^\n]s", &sTopic);
                strcpy((A+nInputNumber)->topic, sTopic);
            }
            if (cChoice == 'Q')
            {
                printf("Please input a question: \n");
                scanf(" %[^\n]s", &sQuestion);
                strcpy((A+nInputNumber)->question, sQuestion);
            }
            if (cChoice == '1')
            {
                printf("Please input choice 1: \n");
                scanf(" %[^\n]s", &sChoice1);
                strcpy((A+nInputNumber)->choice1, sChoice1);
            }
            if (cChoice == '2')
            {
                printf("Please input a choice 2: \n");
                scanf(" %[^\n]s", &sChoice2);
                strcpy((A+nInputNumber)->choice2, sChoice2);
            }
            if (cChoice == '3')
            {
                printf("Please input a choice 3: \n");
                scanf(" %[^\n]s", &sChoice3);
                strcpy((A+nInputNumber)->choice3, sChoice3);
            }
            if (cChoice == 'A')
            {
                printf("Please input an answer: \n");
                scanf(" %[^\n]s", &sAnswer);
                strcpy((A+nInputNumber)->answer, sAnswer);
            }
        }
    } while (bDelete != 'N');   
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
        bAskPassword = 1; // indicates that password does not need to be asked
        if (cMode == 'M')
        {
            if (bPassword == 0) // asks a password if one isnt present.
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
            if (bPassword == 1 && bAskPassword == 1) // if there is a password and if the program needs to ask for it
            {
                do // loops until password is correct or back to main menu is called
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
                        cPasswordMode = displayPasswordMenu(); // asks if the user wants to try again or wants to go back to the main menu
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
                if (bMatchingPassword == 0) // executes if and only if password is correct
                {
                    printf("\nYou have entered the correct password.\n");
                    do
                    {
                        bAskPassword = 0; // indicates to not ask the password
                        cAdminMode = displayAdminMenu();
                        if (cAdminMode == 'A')
                        {
                            addRecord(questionItems, SIZE);
                        }
                        if (cAdminMode == 'C')
                        {
                            changeRecord(questionItems, SIZE);
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
