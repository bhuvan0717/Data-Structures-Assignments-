#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct playlist
{
	char song[25];
	char singer[25];
	char movie[25];
    float size_of_song;
	struct playlist *next;
	struct playlist *previous;
};
typedef struct playlist *NODE;

NODE GetNewNode()
 {
	NODE newNode = (NODE)malloc(sizeof(struct playlist));
	if(newNode==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
	printf("Enter details\n");
	scanf("%s\t %s\t %s\t %f\n", newNode->song, newNode->singer,
                newNode->movie, &newNode->size_of_song);
	newNode->previous = NULL;
	newNode->next = NULL;
	return newNode;
}

NODE insert_front(NODE head)
{
	NODE NewNode = GetNewNode();

	if(head == NULL)
	{
	    	NewNode -> next = NULL;
		head = NewNode ;
  		return NewNode ;
	}
	NewNode ->next = head;
	head->previous = NewNode ;
	head = NewNode ;
	return head;
}

NODE insertAtEnd(NODE head)
{
NODE NewNode = GetNewNode();

if(head == NULL)
{ 	NewNode -> previous = NULL;
 	head = NewNode;
}
else
{ 	NODE temp = head;
	while(temp -> next != NULL)
	temp = temp -> next;
	temp -> next = NewNode;
	NewNode -> previous = temp;
	return head;
}
}

NODE insertAfter(NODE head, char sname[])
{
    NODE newn = GetNewNode();
    NODE cur = head, back = NULL;
    if(head==NULL)
    printf("Adding song is not possible. list is empty\n");
    else
    {
    while(cur -> next != NULL)
    {
        if(strcmp(cur->song, sname)==0)
        break;
        back = cur;
        cur = cur->next;
    }
    //one time shift.
        back = cur;
        cur = cur->next;
    if(cur == NULL && strcmp(back->song, sname)==0)
    {
        back->next = newn;
        newn->previous = back;
    }
    else if(cur != NULL)
    {
        back->next = newn;
        newn->previous = back;
        newn->next = cur;
        cur->previous = newn;
    }
    else
        printf("Song not present in the playlist\n");
    }
    return head;
}

NODE deleteBeginning(NODE head)
{
if(head == NULL)
{
	printf("List is Empty!!! Deletion not possible!!!");
    return head;
}
else
{
NODE temp = head;
if(temp -> previous == temp -> next)
{
	head = NULL; free(temp); return head;
}
else
{
head = temp -> next;
head -> previous = NULL;
free(temp);
return head;
}
	printf("\n Deletion success!!!");
}
}

NODE deleteEnd(NODE head)
{
	NODE temp = head;
if(head == NULL)
{
	printf("List is Empty!!! Deletion not possible!!!");
	return head;
}
else if(temp -> previous == temp -> next)
{
head = NULL; free(temp); return head;
}
else
{
while(temp -> next != NULL)
temp = temp -> next;
temp -> previous -> next = NULL;
free(temp);
return head;
}
	printf("\n Deletion success!!!");
}

NODE deleteSpecific(NODE head, char delValue[])
{
if(head == NULL)
printf("List is Empty!!! Deletion not possible!!!");
else
{
NODE temp = head;
while(strcmp(head->song, delValue)!=0)
{
if(temp -> next == NULL)
{
printf("\nGiven node not found!");
exit(0);
}
else
{
temp = temp -> next;
}
}
if(temp == head)
{
head = NULL;
free(temp);
return head;
}
else
{
temp -> previous -> next = temp -> next;
temp -> next ->previous = temp -> previous;
free(temp);
return head;
}
printf("\nDeletion success!!!");
}
}

void display(NODE head)
{
if(head == NULL)
	printf("\nList is Empty!!!");
else
{
NODE temp = head;
printf("\nList elements are: \n");
while(temp -> next != NULL)
{
	   printf("%s\t %s\t %s\t %f\n", temp->song, temp->singer,temp->movie, temp->size_of_song);
}
}
}

void main()
{
    char sname[25],pos[25];
    int apos, choice;
    NODE head=NULL;
    for(;;)
    {
printf("********choose options from the below menu**********\n\n");
printf("1. Insert data at the beginning. \n 2. Insert data at the end. \n 3. Insert data after specified position. \n 4. Delete data at specific \n 5. Delete data at the end. \n 6. Display all the elements. \n 7.exit \n");
scanf("%d",&choice);
            switch(choice)
            {
                case 1: printf("Enter Candidate details\n");
                        head=insert_front(head);break;

                case 2: printf("Enter Candidate details\n");
                        head=insertAtEnd(head); break;

                case 3: printf("enter the position to be inserted\n");
                        scanf("%s",sname);
                        head=insertAfter(head,sname); break;

                case 4: printf("first element deleted\n");
                        head=deleteBeginning(head); break;

                case 5: printf("last element deleted\n");
                        head=deleteEnd(head); break;

                case 6: printf("enter position\n");
                        scanf("%s,pos");
                        head=deleteSpecific(head,pos);break;

                case 7: printf("Display List\n");
                        display(head); break;
                default : exit(0);
            }

        }
}
