#include "../include/headerA3.h"

//Traverses through all nodes and prints info per node traversed
void printAll (struct employee * headLL)
{
    if (headLL == NULL)
    {
        printf("There are currently no employees\n");
        return;
    }
    int numEmployees = 0;
    a3Emp *temp = headLL;


    while(temp != NULL)
    {
        numEmployees++;
        printf("\nEmployee #%i:\n", numEmployees);
        printf("    Employee ID: %i\n", temp->empId);
        printf("    First Name: %s\n", temp->fname);
        printf("    Last Name: %s\n", temp->lname);
        
        printf("    Dependents [%i]:", temp->numDependents);
        for (int a = 0; a < temp->numDependents; a++)
        {
            printf(" %s", temp->dependents[a]);
        }

        printf("\n");
        temp = temp->nextEmployee;
    }
    printf("\nCurrently, there are %i employees\n\n", numEmployees);
    return;
}