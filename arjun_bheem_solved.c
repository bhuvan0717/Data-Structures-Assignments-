#include<stdio.h>
#include<stdlib.h>
struct coin
{
    int denom;
    struct coin *next;
};
typedef struct coin *NODE;

NODE arjun_head, bheem_head,temp,nnode;

NODE select_coin(NODE);
NODE remove_coin(NODE);
void display_coins(NODE);

int arjun_count=0,bheem_count=0,count=0;

NODE new_node;

int main()
{
  int n,i;
  arjun_head=NULL;
  bheem_head=NULL;
  printf("enter the number of coins to be selected by arjun and bheem\n");
  scanf("%d",&n);

  printf("select %d coins for arjun\n",n);
  for(i=1;i<=n;i++)
  {
     arjun_head=select_coin(arjun_head);
  }

  printf("select %d coins for bheem\n",n);
  for(i=1;i<=n;i++)
  {
     bheem_head=select_coin(bheem_head);
  }

  printf("arjun's stack of coins\n");
  display_coins(arjun_head);

  printf("bheem's stack of coins\n");
  display_coins(bheem_head);

  printf("start counting the 10 rupees coins of arjun\n");
  for(i=1;i<=n;i++)
  {
    arjun_head=remove_coin(arjun_head);
  }
   arjun_count=count;
   printf("start counting the 10 rupees coins of bheem\n");
   count=0;
  for(i=1;i<=n;i++)
  {
    bheem_head=remove_coin(bheem_head);
  }
   bheem_count=count;
  if(arjun_count>bheem_count)
    printf("arjun won the game\n");
  else if(arjun_count<bheem_count)
    printf("bheem won the game\n");
  else
    printf("both arjun and bheem won the game\n");
}

NODE get_node()
{
    nnode=(NODE)malloc(sizeof(struct coin));
    if(nnode==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    else
    {
        //printf("enter the denomination of coin\n");
        scanf("%d",&nnode->denom);
        nnode->next=NULL;
    }
return(nnode);
}

NODE select_coin(NODE head)
{
    new_node=get_node();
     if(head==NULL)
     {
         head=new_node;
        // head->next=NULL;
     }
     else
     {
         new_node->next=head;
         head=new_node;
     }
    return(head);
}

NODE remove_coin(NODE chead)
{
    int sum=0;
    if(chead==NULL)
        printf("no coins to remove\n");
    else
    {
        printf("coin removed is %d\n",chead->denom);
          if(chead->denom==10)
            count++;
        temp=chead;
        chead=chead->next;
        free(temp);
    }
    return(chead);
}

void display_coins(NODE chead)
{
    if(chead==NULL)
        printf("No coins to display\n");
    else
    {
        temp=chead;
        printf("coins are\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->denom);
            temp=temp->next;
        }
    }
}
