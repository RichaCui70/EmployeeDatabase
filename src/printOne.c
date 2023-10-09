#include "../include/headerA3.h"

//Prints one specific node via its position
void printOne (struct employee * headLL, int whichOne)
{
    if (headLL == NULL)
    {
        printf("There are currently no employees\n");
        return;
    }
    
    a3Emp *temp = headLL;
    int counter = 1;
    bool found = false;
    while(temp != NULL)
    {
        if (counter == whichOne)
        {
            printf("Employee ID: %i\n", temp->empId);
            printf("First Name: %s\n", temp->fname);
            printf("Last Name: %s\n", temp->lname);
            
            printf("Dependents:");
            for (int a = 0; a < temp->numDependents; a++)
            {
                printf(" %s", temp->dependents[a]);
            }
            printf("\n\n");
            found = true;
            break;
        }
        counter++;
        temp = temp->nextEmployee;
    }
    if (!found)
    {
        printf("Employee in position %i does not exist\n\n", whichOne);
    }
    return;
}