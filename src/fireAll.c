#include "../include/headerA3.h"

//Frees all nodes in a linked list
void fireAll(a3Emp **fhead)
{
    if (*fhead == NULL)
    {
        printf("There are currently no employees\n");
        return;
    }

    bool exit;
    char answer;
    do
    {
        printf("Are you sure you want to fire everyone: ");
        scanf("%c", &answer);
        answer = toupper(answer);
        if (answer == 'Y' || answer == 'N')
        {
            exit = true;
        }
        else
        {
            printf("bruh pick Y or N\n");
            exit = false;
        }
        getchar();
    } while (!exit);
    if (answer == 'N')
    {
        return; 
    }

    a3Emp *temp = *fhead;
    while (*fhead != NULL)
    {
        temp = *fhead;
        *fhead = (*fhead)->nextEmployee;
        for (int a = 0; a < temp->numDependents; a++)
        {
            free(temp->dependents[a]);
        }
        free(temp->dependents); 
        free(temp);
    }
    printf("All fired. Linked list is now empty\n");
    return;
}