#include "../include/headerA3.h"

bool userCheck (char userInput[MAX_LENGTH])
{
    return true;
}

int main(int argc, char *argv[])
{
    //This check if there are arguments in the command-line
    if (argc != 2)
    {
        printf("Usage: ./bin/proFile *textfile*.txt\n");
        return -1;
    }

    //This initializes the head of the linked list
    //loadEmpData creates 4 nodes to attach to the linked list
    a3Emp *headLL = NULL;
    /*
    loadEmpData(&headLL, argv[1]);

    //If for some reason there is an empty file, we'll stop the program
    if (headLL == NULL)
    {
        return -2;
    }
    */
    //This is the structure of the menu
    int menuOptions = 0;
    int empPosition = 0;
    char empName[MAX_LENGTH];
    bool exit = false;
    bool tfInput = true;
    do
    {
        //This asks the user for a number for 1-10.
        //It checks for numbers beyond the interval of 1-10, strings, characters.
        //It does it by allocating 25 (MAX_LENGTH) bytes in empName and inputting whatever the user inputs into that variable.
        //It then checks whether or not the inputted value is a string or not. It does this by firstly intializing every element in empName to NULL. This means if [1] isn't NULL then there's an unwanted string
        //If something goes wrong, we reprompt the user. 
        do
        {
            tfInput = true;
            for (int a = 0; a < MAX_LENGTH; a++)
            {
                empName[a] = '\0';
            }

            printf("\nChoose a menu option: ");

            fgets(empName, MAX_LENGTH, stdin);
            empName[strlen(empName) - 1] = '\0';
            menuOptions = (int)(empName[0]) - 48;

            if (empName[1] != '\0')
            {
                printf("Try again (0-9)\n");
                tfInput = false;
            }
            else if (menuOptions < 0 || menuOptions > 9)
            {
                printf("Try again (0-9)!!\n");
                tfInput = false;
            }
        } while (!tfInput);

        //After obtaining a number within 0-9, we travel into which function they decided
        switch (menuOptions)
        {
            case 1:
                recruitEmployee(&headLL);
                break;
            case 2:
                printAll(headLL);
                break;
            case 3:
                printf("\nEnter a position: ");
                scanf("%i", &empPosition);
                getchar();
                printf("\n");
                printOne(headLL, empPosition);
                break;
            case 4:
                printf("\nEnter an employee ID: ");
                scanf("%i", &empPosition);
                getchar();
                printf("\n");
                empPosition = lookOnId (headLL, empPosition);
                //printf("%i\n", empPosition);
                break;
            case 5:
                printf("\nEnter the full name of the employee: ");
                fgets(empName, MAX_LENGTH, stdin);
                empName[strlen(empName) - 1] = '\0';
                empPosition = lookOnFullName (headLL, empName);
                break;
            case 6:
                printf("\nNumber of employees: %i\n", countEmployees(headLL));
                break;
            case 7:
                printf("After sorting on empId, the employees are as follows: \n");
                sortEmployeesId (headLL);
                break;
            case 8: 
                empPosition = countEmployees(headLL);
                printf("\nCurrently, there are %i of employees\n", empPosition);
                printf("Which employee do you wish to fire - enter a value between 1 and %i: ", empPosition);
                scanf("%i", &empPosition);
                getchar();
                fireOne (&headLL, empPosition);
                printf("There are now %i employees\n", countEmployees(headLL));
                break;
            case 9:
                fireAll(&headLL);
                break;
            default:
                printf("Have a good day!\n");
                a3Emp * temp = headLL;
                while (headLL != NULL)
                {
                    temp = headLL;
                    headLL = headLL->nextEmployee;
                    for (int a = 0; a < temp->numDependents; a++)
                    {
                        free(temp->dependents[a]);
                    }
                    free(temp->dependents);
                    free(temp);
                }
                exit = true;
                break;
        }
    } while (!exit);
}