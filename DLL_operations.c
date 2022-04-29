#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct playlist
{
	char name[25],singer[25],movie[25];
	float size;
	struct playlist *next,*prev;
};
typedef struct playlist *NODE;

//Function prototyping
NODE DLLgetnodeode();
NODE DLLinsert_front(NODE);
NODE DLLinsert_end(NODE);
NODE DLLinsert_after(NODE,char[]);

NODE DLLdelete_specific(NODE,char[]);
void DLLdisplay_playlist(NODE);

void search_singer(NODE,char[]);
NODE play_song(NODE,NODE,char[]);
NODE play_next(NODE playing);
NODE play_prev(NODE);

// Main function definition
int main()
{
    int choice=0;
    char key[25],songKey[25],singerNameKey[25];
    NODE playing=NULL,head=NULL;
    while(1)
    {
        printf("\n___________\nMusic Player\n___________\n");
        printf("\nMenu:\n====================\n");
        printf("\n1.Insert song at the beginning of the playlist");
        printf("\n2.Insert song at the end of the playlist");
        printf("\n3.Insert song after");
        printf("\n4.Display playlist");
        printf("\n5.Play song");
        printf("\n6.Play next song");
        printf("\n7.Play previous song");
        printf("\n8.Search song by singer name");
        printf("\n9.Delete song");
        printf("\nOther:Exit application\n____________________\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
            switch(choice)
                    {
                        case 1: head=DLLinsert_front(head);
                                break;
                        case 2: head=DLLinsert_end(head);
                                break;
                        case 3: printf("Enter the song after which the read song has to be entered: ");
                                scanf("%s",songKey);
                                head=DLLinsert_after(head, songKey);
                                break;
                        case 4: DLLdisplay_playlist(head);
                                break;
                        case 5: printf("\nEnter the song to be played: ");
                                scanf("%s",key);
                                playing=play_song(head, playing, key);
                                break;
                        case 6: playing=play_next(playing);
                                break;
                        case 7: playing=play_prev(playing);
                                break;
                        case 8: printf("\nEnter the singer name to be found: ");
                                scanf("%s",singerNameKey);
                                search_singer(head, singerNameKey);
                                break;
                        case 9: printf("Enter the song to be deleted: ");
                                scanf("%s", songKey);
                                head=DLLdelete_specific(head, songKey);
                                break;
                        default: return 0;
                    }
    }
    return 0;
}

//DLLgetNewNode function defination
NODE DLLgetnode()
 {
	NODE newn=(NODE)malloc(sizeof(struct playlist));
	if(newn==NULL)
	{
		printf("Song not created\n");
		exit(0);
	}
        printf("\nEnter the song details:\n");
        printf("Song name: ");
        scanf("%s", newn->name);
        printf("Singer name: ");
        scanf("%s", newn->singer);
        printf("Song size in MB: ");
        scanf("%f", &newn->size);
        printf("Movie name: ");
        scanf("%s",newn->movie);
        newn->prev=NULL;
        newn->next=NULL;
	return newn;
}

//DLLinsertFront() function definition
NODE DLLinsert_front(NODE head)
{
	NODE newn = DLLgetnode();

	if(head == NULL)		//if list empty
	{
		head = newn ;
		return head ;
	}
	newn ->next = head;		//inserting NODE at front
	head->prev = newn ;
	head = newn ;
	return head;
}

//DLLinsertAtEnd() function
NODE DLLinsert_end(NODE head)
{
	NODE newn = DLLgetnode();
	if(head == NULL)
	{
	head = newn;
	}
	else
	{ 	NODE cur = head;
		while(cur -> next != NULL)
			{
			cur = cur -> next;
			}
	cur -> next = newn;
	newn -> prev = cur;
	}
	return head;
}

//DLLinsertAfter() function definition
NODE DLLinsert_after(NODE head, char key[25])
{
	NODE newn = DLLgetnode();
	NODE cur = head, temp = NULL;
	int flag=0;
	if(head == NULL)
	{
		printf("Adding song is not possible as the play list is empty\n");
		return head;
	}
	while(cur->next!=NULL)
    {
        if(strcmp(cur->name,key)==0)
		{
		    flag=1;
            break;
		}
        cur=cur->next;
	}
	if(cur->next==NULL)
    {
        if(strcmp(cur->name,key)==0)
		{
                flag=1;
                cur->next=newn;
                newn->prev=cur;
                return head;
		}
		else
        {
                printf("Entered song is not found!! cant add new song\n");
                return head;
        }
    }
 /*  else if(temp1->next!=NULL && flag==1)
  {
		temp2 = temp1 -> next;
		temp1 -> next = newNode ;
		newNode -> previous = temp1;
		newNode -> next = temp2;
		temp2 -> previous = newNode ;
		return head;
  }*/
}

//DLLdiplayList() function
void DLLdisplay_playlist(NODE head)
{
	NODE cur = head;
	if(head == NULL)
		printf("\nList is Empty!!!");
	else
	{
		printf("\nList elements are: \n");
		while(cur != NULL)
		{
		printf("%s\t %s\t %s\t %0.2f\n", cur->name, cur->singer, cur->movie, cur->size);
		cur = cur->next;
		}
	}
}

//play song() function
NODE play_song(NODE head, NODE playing, char key[25])
{
	NODE cur = head;
	int flag=0;
	if(head == NULL)
		printf("\nList is Empty!!!");
	else
	{
		while(cur != NULL)
		{
		  if(strcmp(cur->name,key)==0)
		 {
            flag=1;
            printf("The song playing is: %s\t %s\t %s\t %0.2f\n", cur->name, cur->singer, cur->movie, cur->size);
            return head;
		 }
		cur = cur->next;
		}
		if(flag==0)
		{
		printf("Song %s not found", key);
		}
	}
    return playing;
}

//playNextSong function
NODE play_next(NODE playing)
{
	if(playing== NULL)
	{
		printf("\nNo next song found!!!");
	}
	else
	{
		  playing=playing->next;
		  if(playing!=NULL)
		  {
                printf("The song playing is: %s\t %s\t %s\t %0.2f\n", playing->name, playing->singer, playing->movie, playing->size);
                return playing;
		  }
		  else
		printf("\nNo next song found!!!");
	}
    return playing;
}

//playNextSong function
NODE play_prev(NODE playing)
{
    printf("Hi");
	if(playing==NULL)
	{
		printf("\nNo previous song found!!!");
	}
	else
	{
        playing=playing->prev;
		printf("The song playing is: %s\t %s\t %s\t %0.2f\n", playing->name, playing->singer, playing->movie, playing->size);
	}
return playing;
}

void search_singer(NODE head, char singerNameKey[25])
{
	NODE cur = head;
	int flag=0;
	if(head == NULL)
		printf("\nList is Empty!!!");
	else
	{
		while(cur != NULL)
		{
		 if(strcmp(cur->name,singerNameKey)==0)
		 {
            flag=1;
            printf("The song found is: %s\t %s\t %s\t %0.2f\n", cur->name, cur->singer, cur->movie, cur->size);
		 }
		 cur = cur->next;
		}
		if(flag==0)
		{
            printf("Song by %s not found", singerNameKey);
		}
	}
}

//delete from specific NODE
NODE DLLdelete_specific(NODE head, char songKey[25])
{
    NODE newnode;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if(head->next==NULL)
        {
        if(strcmp(head->name,songKey)==0)
            {
                printf("Deleted %s\n",head->name);
                free(head);
                head=NULL;
                return head;
            }
        }
     if(head->next!=NULL)
        {
        if(strcmp(head->name,songKey)==0)
            {
                NODE temp=head;
                head=head->next;
                printf("Deleted %s\n",temp->name);
                free(temp);
                return head;
            }
        }
        NODE cur=head,p=NULL;
        while(cur->next!=NULL)
        {
            if(strcmp(cur->name,songKey)==0 )
            {
                break;
            }
            p=cur;
            cur=cur->next;
        }
       if(cur->next==NULL)
        {
           if(strcmp(cur->name,songKey)==0)
            {
                p->next=NULL;
                printf("Deleted %s\n",cur->name);
                free(cur);
                return head;
            }
        else
            {
                printf("Song not found!!unable to delete\n");
                return head;
            }
        }
        else
        {
            p->next=cur->next;
            cur->next->prev=p;
            printf("Deleted %s\n",cur->name);
            free(cur);
            return head;
        }
}
