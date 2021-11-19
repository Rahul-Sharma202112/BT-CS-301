#include<stdio.h>
#include<stdlib.h>
typedef int entry_list;
typedef struct node
{
	entry_list entry;
	struct node *next;
}NODE;

//delcelaration of function

NODE* creatNode(entry_list entry);
NODE* insertBegin(NODE *header,entry_list entry);
NODE* insertEnd(NODE *header,entry_list entry);
NODE* insertAtPosition(NODE *header,entry_list entry,int position);
NODE* reverseList(NODE *header);
NODE* DeleteNode(NODE *header,entry_list entry);
void printList(NODE *header);
void update_data(int old, int new);

int main()
{
	NODE *header;
	int choice=-1;
	int position;
	header=NULL;
	entry_list x;
	while(choice)
	{
		printf(" 1: Insert at beginning\n");
		printf(" 2: Insert at end\n");
		printf(" 3: update linked list\n");
		printf(" 4: Insert at position\n");
		printf(" 5: Delete Node from List\n");
		printf(" 6: Reverse a Linked List\n");
		printf(" 7: Print Linked List\n");
		printf(" 0: Exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("enter data to add on begining in linked list ");
			fflush(stdin);
			scanf("%d",&x);
			header=insertBegin(header,x);
			break;
			case 2:
			printf("enter data to add on begining in linked list ");
			fflush(stdin);
			scanf("%d",&x);
			header=insertEnd(header,x);
			break;
			case 3:
			printf("update linked list ");
			update_data(4,65);
			break;
			case 4:
			printf("enter data to insert at a position ");
			fflush(stdin);
			scanf("%d",&x);
			printf("enter position ");
			scanf("%d",&position);
			header=insertAtPosition(header,x,position);
			break;
			case 5:
			printf("enter the element to delete ");
			fflush(stdin);
			scanf("%d",&x);
			header=DeleteNode(header,x);
			break;
			case 6:
			header=reverseList(header);
			printf("Linked list reveresed successfully\n");
			break;
			case 7:
			printList(header);
			break;
			default:
			printf("program is over\n");
		}
	}
	return 0;
}
NODE* creatNode(entry_list x)
{
	NODE *temp;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->entry=x;
	temp->next=NULL;
	return temp;
}
NODE* insertBegin(NODE *header,entry_list x)
{
	NODE *temp;
	temp=creatNode(x);
	if(header==NULL)
	{
		header=temp;
	}
	else
	{
		temp->next=header;
		header=temp;
	}
	return header;
}
NODE* insertEnd(NODE *header,entry_list x)
{
	NODE *temp,*curr;
	temp=creatNode(x);
	if(header==NULL)
	{
		header=temp;
	}
	else
	{
		curr=header;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr->next=temp;
	}
	return(header);
}

NODE* insertAtPosition(NODE *header,entry_list x,int position)
{
	NODE *temp,*curr;
	int i;
	temp=creatNode(x);
	if(header==NULL&&position==1)
	{
		header=temp;
	}
	else
	{
		if(header==NULL&&position!=1)
		{
			printf("Cannot insert at given position\n");
		}
		else
		{
			if(header!=NULL&&position==1)
			{
				temp->next=header;
				header=temp;
			}
			else
			{
				if(header!=NULL&&position>1)
				{
					curr=header;
					for(i=1;curr->next!=NULL&&i<position-1;i++)
					{
						curr=curr->next;
					}
					if(curr==NULL)
					{
						printf("Cannot insert at given position\n");
					}
					else
					{
						temp->next=curr->next;
						curr->next=temp;
						printf("Data inserted successfully\n");
					}
				}
				
			}
		}
	}
	return header;
}
void printList(NODE *header)
{
	NODE *curr;
	if(header==NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		curr=header;
		while(curr!=NULL)
		{
			printf("%d -> ",curr->entry);
			curr=curr->next;
		}
		printf("NULL\n");
	}
}
NODE* DeleteNode(NODE *header,entry_list x)
{
	NODE *prev,*curr;
	if(header==NULL)
	{
		printf("error: List is empty: \n");
	}
	else
	{
		if(header->entry==x)
		{
			prev=header;
			curr=header->next;
			free(prev);
			header=curr;
		}
		else
		{
			curr=header;
			while(curr!=NULL&&curr->next->entry!=x)
			{
				curr=curr->next;
			}
			if(curr==NULL)
			{
				printf("Node not found\n");
			}
			else
			{
				prev=curr->next;
				curr->next=curr->next->next;
				free(prev);
				printf("Node deleted successfully\n");
			}
		}
	}
	return header;
}
NODE * reverseList(NODE * header)
{
	NODE *prev, * curr, * next;
	if(header != NULL)
	{
		curr = header;
		prev= NULL;
		next = curr->next;
		while(curr != NULL)
		{
			curr->next = prev;
			prev = curr;
			curr = next;
			if(curr != NULL)
			{
				next = curr->next;
			}
		}
		header = prev;
	}
	return(header);
}

void update_data(int old, int new) {
   int pos = 0;
   NODE *current,*head;
   if(head==NULL) {
      printf("Linked List not initialized");
      return;
   } 

   current = head;
   while(current->next!=NULL) {
      if(current->entry == old) {
         current->entry = new;
         printf("\n%d found at position %d, replaced with %d\n", old, pos, new);
         return;
      }
      
      current = current->next;
      pos++;
   }
   
   printf("%d does not exist in the list\n", old);
}











