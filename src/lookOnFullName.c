#include "../include/headerA3.h"


//Searches for employee via their full name
//Takes care of quirks such as extra space bars
int lookOnFullName (struct employee * headLL, char whichName [100])
{
    if (headLL == NULL)
    {
        printf("There are currently no employees\n");
        return 0;
    }

    for (int a = 0; a < strlen(whichName); a++)
    {
        if (whichName[a] == ' ')
        {
            for (int b = a; b < strlen(whichName); b++)
            {
                whichName[b] = whichName[b+1];
            }
            a--;
        }
    }

    a3Emp *temp = headLL;
    int counter = 1;
    char empName[100];
    while(temp != NULL)
    {
        for (int a = 0; a < 100; a++)
        {
            empName[a] = '\0';
        }
        strcpy(empName, temp->fname);
        strcat(empName, temp->lname);

        if (strcmp(empName, whichName) == 0)
        {
            printf("\nEmployee ID: %i\n", temp->empId);
            printf("First Name: %s\n", temp->fname);
            printf("Last Name: %s\n", temp->lname);
            
            printf("Dependents:");
            for (int a = 0; a < temp->numDependents; a++)
            {
                printf(" %s", temp->dependents[a]);
            }
            printf("\n\n");

            return counter;
        }
        counter++;
        temp = temp->nextEmployee;
    }

    printf("Employee %s does not exist\n", whichName);
    return counter;
}