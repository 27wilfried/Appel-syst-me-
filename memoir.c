#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

// Functions du prof
node *init_node(void);
node *addHead(node *head, int new_elmt);
void addTail(node *head, int new_elmt);
void display_list(node *head);

// Perso
int list_empty(node *list);
void delete (node *list);

int main(int argc, char *argv[])
{
    int i;
    node *head = NULL;

    // Ajout de 10 éléments
    for (i = 1; i <= 10; i++)
    {
        head = addHead(head, i);
    }

    addTail(head, 17);

    display_list(head);
    printf("\n");
    return 0;
}

node *init_node(void)
{
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        exit(1);
    }
    n->val = -1;
    return n;
}

int list_empty(node *list)
{
    return (list == NULL);
}

node *addHead(node *head, int new_elmt)
{
    node *p;
    p = init_node();
    p->val = new_elmt;
    p->next = head;
    head = p;
    return head;
}

void addTail(node *head, int new_elmt)
{
    if (head == NULL)
        addHead(head, new_elmt);
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        node *p = init_node();
        p->val = new_elmt;
        head->next = p;
    }
}

void display_list(node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// void delete (node *list)
// {
//     if (list == NULL)
//     {
//         exit(1);
//     }
// }
