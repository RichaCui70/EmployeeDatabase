#include "../include/headerA3.h"

//Rearranges linked list in ascending empId order
void sortEmployeesId (struct employee * headLL)
{
    if (headLL == NULL)
    {
        printf("There are currently no employees\n");
        return;
    }
    a3Emp *temp = headLL;
    a3Emp swap;
    int sizeLL = 0;
    while(temp != NULL)
    {
        sizeLL++;
        temp = temp->nextEmployee;
    }

    int counter = 0;
    while (counter < sizeLL)
    {
        a3Emp *temp = headLL;
        while (temp->nextEmployee != NULL)
        {
            if (temp->empId > temp->nextEmployee->empId)
            {
                // swap(temp, temp->nextEmployee);
                strcpy(swap.fname,temp->fname);
                strcpy(swap.lname,temp->lname);
                swap.empId = temp->empId;
                swap.numDependents = temp->numDependents;
                swap.dependents = temp->dependents;


                temp->empId = temp->nextEmployee->empId;
                strcpy(temp->fname,temp->nextEmployee->fname);
                strcpy(temp->lname,temp->nextEmployee->lname);
                temp->numDependents = temp->nextEmployee->numDependents;
                temp->dependents = temp->nextEmployee->dependents;

                temp->nextEmployee->empId = swap.empId;
                strcpy(temp->nextEmployee->fname,swap.fname);
                strcpy(temp->nextEmployee->lname,swap.lname);
                temp->nextEmployee->numDependents = swap.numDependents;
                temp->nextEmployee->dependents = swap.dependents;
                //a b t
                // t = a
                // a = b
                // b = temp
            }
            temp = temp->nextEmployee;
        }
        counter++;
    }
    printAll(headLL);

    return;
}