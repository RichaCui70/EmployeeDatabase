#include "../include/headerA3.h"

//Traverses through the linked lists and counts how many nodes it traverses through
int countEmployees (a3Emp * headLL)
{
    if (headLL == NULL)
    {
        printf("There are currently no employees\n");
        return 0;
    }

    int counter = 0;
    a3Emp *temp = headLL;
    while (temp != NULL)
    {
        counter++;
        temp = temp->nextEmployee;
    }

    return counter;
}