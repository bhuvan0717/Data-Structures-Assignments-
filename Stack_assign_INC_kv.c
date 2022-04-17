#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} *NODE;

NODE push(NODE top, int item)
{
    NODE tmp = (NODE)malloc(sizeof(struct stack));
    if(tmp==NULL)
    {
        printf("Memory error.\n");
        exit(0);
    }
    tmp->data = item;
    if(top==NULL)
        tmp->next = NULL;
    else
        tmp->next = top;
    return tmp;
}

NODE pop(NODE top)
{
    if(top==NULL)
    {
        printf("Shelf is empty.\n");
    }
    else
    {
        NODE tmp = top;
        top = top->next;
        //printf("%d\n", tmp->data);
        free(tmp);
    }
    return top;
}

void inc(NODE top, int k,int v, int d)
{
    if(top==NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        NODE cur = top;
        int i =0;
        while(cur != NULL)
        {
            if(i>=(d-k))
                cur->data += v;
            printf("%d ", cur->data);
            i++;
            cur = cur->next;
        }
        printf("\n");
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n_push, n_pop, k, v, d;
    NODE top = NULL;
    scanf("%d", &n_push);
    scanf("%d", &n_pop);
    scanf("%d", &k);
    scanf("%d", &v);
    for(int i=0; i<n_push; i++)
    {
        scanf("%d", &d);
        top = push(top, d);
    }
    for(int i=0; i<n_pop; i++)
        top = pop(top);
    d = n_push - n_pop;
    inc(top, k, v, d);
    return 0;
}
