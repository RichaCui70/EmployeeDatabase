#include "../include/headerA3.h"

//Adds a node to the linked list
void recruitEmployee(struct employee ** headLL)
{
    a3Emp *node = malloc(sizeof(a3Emp));

    printf("\n\nEnter first name of employee: ");
    fgets(node->fname, MAX_LENGTH, stdin);
    node->fname[strlen(node->fname) - 1] = '\0';
    printf("Enter last name of employee: ");
    fgets(node->lname, MAX_LENGTH, stdin);
    node->lname[strlen(node->lname) - 1] = '\0';

    node->nextEmployee = NULL;

    char answer[MAX_LENGTH];
    char buffer[MAX_LENGTH];
    bool exit = false;
    node->dependents = NULL;
    node->numDependents = 0;
    do
    {
        node->numDependents++;
        if (node->dependents == NULL)
        {
            node->dependents = malloc(sizeof(char*));
        }
        else
        {
            node->dependents = realloc(node->dependents, sizeof(char*) * node->numDependents);
        }

        printf("\nEnter the name of dependent #%i: ", node->numDependents);
        fgets(buffer, MAX_LENGTH, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        
        node->dependents[node->numDependents - 1] = malloc(sizeof(char) * strlen(buffer) + 1);
        strcpy(node->dependents[node->numDependents - 1], buffer);

        do
        {
            printf("Do you have any more dependents? ");
            fgets(answer, MAX_LENGTH, stdin);
            answer[strlen(answer) - 1] = '\0';
            if (toupper(answer[0]) == 'Y' || toupper(answer[0]) == 'N')
            {
                exit = true;
            }
            else
            {
                printf("Pick Y or N\n");
                exit = false;
            }
        }
        while (!exit);
    }
    while(toupper(answer[0]) == 'Y');
    printf("\nYou have %i dependents.\n", node->numDependents);

    node->empId = 0;
    for (int a = 0; a < strlen(node->fname); a++)
    {
        node->empId = node->empId + (int)node->fname[a];
    }
    node->empId = node->empId + strlen(node->lname);

    a3Emp *temp;
    if (*headLL == NULL)
    {
        *headLL = node;
    }
    else
    {
        do
        {
            exit = true;
            temp = *headLL;
            while (temp->nextEmployee  != NULL)
            {
                if (temp->empId == node->empId)
                {
                    node->empId = node->empId + (rand() % 999);
                    exit = false;
                }
                temp = temp->nextEmployee;
            }
        } while (!exit);

        temp->nextEmployee = node;
    }
    printf("\nYour computer-generated empId is %i\n\n", node->empId);

    /*
    for (int a = 0; a < node->numDependents; a++)
    {
        free(node->dependents[a]);
    }
    free(node->dependents);
    free(node);
    */
    return;
}