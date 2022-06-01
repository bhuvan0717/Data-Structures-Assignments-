#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;

};
typedef struct Node *node;
node insert_rear(int item, node first);
node getnode();
void display_list1(node first);
node reverse_list(node first);
node insert_rear(int item, node second);
node merged_list(node first,node second);
main()
{
	node first = NULL,second=NULL;
	int choice,item;
	while(1)
	{
		printf("1-List1:Insert Rear\n2-Display List1\n3:Reverse\n4:List2:Insert Rear\n 5:Display List2\n6:Merge\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter item to be Inserted in List 1\n");
			        scanf("%d",&item);
			        first=insert_rear(item,first);
			        break;
			case 2: printf("Display List 1\n");
			        display_list(first);
			        break;
		     case 3: printf("Reverse List \n");
			        first=reverse_list(first);
			        break;
			 case 4: printf("Enter item to be Inserted in List 2\n");
			        scanf("%d",&item);
			        second=insert_rear(item,second);
			        break;
              case 5: printf("Display List2\n");
			        display_list(second);
			        break;
			    case 6: printf("Merged List\n");
                        first=merged_list(first,second);
			        break;

           // case 7: exit(0);

			default:exit(0);
		}
	}

}

node getnode()
{
	node t;
	t=(node *)malloc(sizeof(struct Node));
	if(t==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
	t->next = NULL;
	return t;
}

void display_list(node first)
{
	node t;
	if(first==NULL)
	{
		printf("Empty List\n");
		return;
	}
	printf("elements are\n");
	t=first;
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t= t->next;
	}
	printf("\n");
}
node insert_rear(int item, node first)
{
	node t,c;
	t=getnode();
	t->data = item;
	//t ->next = NULL;
	if(first ==NULL)
	  return t;
	c=first;
	while(c->next!=NULL)
	{
		c=c->next;
	}
	c->next = t;
	return first;
}

node reverse_list(node first)
{
	node next_node,c,prev=NULL;
	c=first;
	while(c!=NULL)
	{
	next_node=c->next;
	c->next=prev;
	prev=c;
	c=next_node;
	}
return prev;
}

node merged_list(node first,node second)
{
    node c,t;
    c=first;
    while(c->next!=NULL)
        c=c->next;
    c->next=second;
    return first;
}
