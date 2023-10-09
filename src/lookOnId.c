#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId)
{
    if (headLL == NULL)
    {
        printf("There are currently no employees\n");
        return 0;
    }
    a3Emp *temp = headLL;
    int counter = 1;
    bool found = false;
    while(temp != NULL)
    {
        if (temp->empId == whichEmpId)
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
        printf("EmpId %i does not exist\n", whichEmpId);
    }
    return counter;
}