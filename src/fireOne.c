#include "../include/headerA3.h"

//Frees one node and attaches the previous node to the one adjecent to the one being freed
void fireOne (a3Emp ** fhead, int whichOne)
{
    if (*fhead == NULL)
    {
        printf("There are currently no employees\n");
    }
    a3Emp *temp0 = *fhead;
    a3Emp *temp1 = *fhead;
    int counter = 0; 
    bool first = true;
    while(temp1 != NULL)
    {
        counter++;
        if (counter == whichOne)
        {
            if (first)
            {
                *fhead = temp1->nextEmployee;
            }
            else
            {
                temp0->nextEmployee = temp1->nextEmployee;
            }
            
            for (int a = 0; a < temp1->numDependents; a++)
            {
                free(temp1->dependents[a]);
            }
            free(temp1->dependents);
            free(temp1);
            return;
        }
        if (!first)
        {
            temp0 = temp0->nextEmployee;
        }
        temp1 = temp1->nextEmployee;
        first = false;
    }
    printf("Employee in position %i does not exist\n\n", whichOne);
    return;
}