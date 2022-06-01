#include<stdio.h>
#include<stdlib.h>

typedef struct baggage{
    int baggage_id;
    char name[20];
    int weight;
    struct baggage *next;
    struct baggage *prev;
}*node;

node getnode(){
    node new = (node)malloc(sizeof(struct baggage));
    if(new == NULL){
        printf("Node not created\n");
        exit(0);
    }
    // printf("Enter the data\n");
    scanf("%d%s%d",&new->baggage_id,new->name,&new->weight);
    new->prev = new;
    new->next = new;
    return new;
}

node insertEnd(node head)
{
    node cur = head;
    node new = getnode();
    if (head == NULL)
    {
        head = new;
        return head;
    }
    while (cur->next != head)
    {
        cur = cur->next;
    }
    cur->next = new;
    new->prev = cur;
    head->prev = new;
    new->next = head;
    return head;
}

node compare(node head){
    node cur = head, temp1, temp2, temp3;

    while (cur->next != head)
    {
        if (cur->weight > cur->prev->weight && cur->weight < cur->next->weight)
        {
            temp1 = cur->prev;
            temp2 = cur->next;
            temp1->next = temp2;
            temp2->prev = temp1;

            free(cur);
            return head;
        }
        cur = cur->next;
    }

    if (cur->weight > cur->prev->weight && cur->weight < cur->next->weight)
    {
        temp3 = cur->prev;
        temp3->next = head;
        head->prev = temp3;

        free(cur);
        return head;
    }
    return head;
}

void display(node head)
{
    node cur = head;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (cur->next != head)
        {
            printf("%d %s %d",cur->baggage_id,cur->name,cur->weight);
            cur = cur->next;
            printf("\n");
        }
        printf("%d %s %d",cur->baggage_id,cur->name,cur->weight);
    }
}

int main(){
    node head = NULL;
    int count,i;
    scanf("%d",&count);
    while(count--){
        head = insertEnd(head);
    }
    scanf("%d",&i);
    while(i--){
        head = compare(head);
    }
    display(head);
    return 0;
}
