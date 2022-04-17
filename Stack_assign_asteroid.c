#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack
{
    signed int data;
    struct stack *next;
} *NODE;

NODE getNODE(int item)
{
    NODE n = (NODE)malloc(sizeof(struct stack));
    if(n==NULL)
    {
        printf("Node is not created.\n");
        exit(0);
    }
    n->data = item;
    n->next = NULL;
    return n;
}

NODE push(NODE top, int item)
{
    NODE temp = getNODE(item);
    if(top==NULL)
        return temp;
    NODE cur = top;
    while(cur->next != NULL)
        cur = cur->next;
    cur->next = temp;
    return top;
}

NODE pop(NODE top)
{
    if(top==NULL)
    {
        printf("Shelf is empty.\n");
    }
    else
    {
        NODE temp = top, prev = NULL;
        while(temp->next!=NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    return top;
}

void collision(NODE top1, NODE top2)
{
    NODE t1 = top1;
    NODE t2 = top2;
    int c0 = 0, c1 = 0;
    while(t1 != NULL)
    {
        if((t1->data>0 && t2->data>0) || (t1->data<0 && t2->data<0))
        {
            printf("0 ");
            c0++;
        }
        else if((t1->data>0 && t2->data<0) || (t1->data<0 && t2->data>0))
        {
            printf("1 ");
            c1++;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    printf("\n%d\n", c1);
    printf("%d\n", c0);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, d;
    NODE top1 = NULL, top2 = NULL;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &d);
        top1 = push(top1, d);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d", &d);
        top2 = push(top2, d);
    }
    collision(top1, top2);
    return 0;
}
