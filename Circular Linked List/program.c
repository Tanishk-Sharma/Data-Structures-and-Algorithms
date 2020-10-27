#include<stdio.h>
#include<alloc.h>
#include<conio.h>
struct node
{
	int data;
	int key;
	struct node *next;
}*last=NULL;
void createList();
void displayList();
void insertFirst();
void insertLast();
void insertAfter();
struct node *delFirst();
struct node *delLast();
struct node *delAfter();
struct node *delAt();
struct node *findKey(int);

void main()
{
	int choice;
	char ch;
	clrscr();
	printf("\nPlease Create the list before further operations are done:\n");
	createList();
	do{
		printf("\n\tMENU:\n");
		printf("\n1.Insert Node at Beginning of List.\n");
		printf("2.Insert Node at End of List.\n");
		printf("3.Insert Node after a given Node in the list.\n");
		printf("4.Delete First Node from the list.\n");
		printf("5.Delete Last Node from the list.\n");
		printf("6.Delete a Node after a given Node from the list.\n");
		printf("7.Delete a Node at a given position from the list.\n");
		printf("8.EXIT.\n");
		printf("\nEnter Choice:\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				createList();
				displayList();
				break;
			case 1:
				insertFirst();
				displayList();
				break;
			case 2:
				insertLast();
				displayList();
				break;
			case 3:
				insertAfter();
				displayList();
				break;
			case 4:
				free(delFirst());
				displayList();
				break;
			case 5:
				free(delLast());
				displayList();
				break;
			case 6:
				free(delAfter());
				displayList();
				break;
			case 7:
				free(delAt());
				displayList();
				break;
			case 8:
				exit(1);
				break;
		}
		printf("\nShow Menu? Y/N : \t");
		ch=getch();
	}while(ch=='y');
	getch();
}

void createList()
{
	char ch;
	struct node *ptr,*cpt;
	printf("\nEnter First Node Info:\n");
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("\nKEY:\t");
	scanf("%d",&ptr->key);
	printf("\nData:\t");
	scanf("%d",&ptr->data);
	last=ptr;
	ptr->next=last;
	printf("\nInsert More Nodes?: Y/N\t");
	ch=getch();
	if(ch=='y')
	{
		do{
			cpt=(struct node *)malloc(sizeof(struct node));
			printf("\nEnter New Node info:\n");
			printf("\nKEY:\t");
			scanf("%d",&cpt->key);
			printf("\nData:\t");
			scanf("%d",&cpt->data);
			last->next=cpt;
			cpt->next=ptr;
			last=cpt;
			displayList();
			printf("\nInsert More Nodes?: Y/N\t");
			ch=getch();
		}while(ch=='y');
	}
}

void insertFirst()
{
	struct node *new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter New Node info:\n");
	printf("\nKEY:\t");
	scanf("%d",&new_node->key);
	printf("\nData:\t");
	scanf("%d",&new_node->data);
	if(last==NULL)			//FOR EMPTY LIST
	{
		last=new_node;
		last->next=new_node;
	}
	else
	{
		new_node->next=last->next;
		last->next=new_node;
	}
}

void insertLast()
{
	struct node *new_node,*ptr;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter New Node info:\n");
	printf("\nKEY:\t");
	scanf("%d",&new_node->key);
	printf("\nData:\t");
	scanf("%d",&new_node->data);
	if(last==NULL)			//FOR EMPTY LIST
	{
		last=new_node;
		last->next=new_node;
	}
	else
	{
		new_node->next=last->next;
		last->next=new_node;
		last=new_node;
	}
}
void insertAfter()
{
	int key_before;
	struct node *ptr,*new_node;
	printf("\nPlease Enter the Key of List Item after which Insertion is to be done:\t");
	scanf("%d",&key_before);
	ptr=findKey(key_before);
	if(ptr!=NULL)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter New Node info:\n");
		printf("\nKEY:\t");
		scanf("%d",&new_node->key);
		printf("\nData:\t");
		scanf("%d",&new_node->data);
		new_node->next=ptr->next;
		ptr->next=new_node;
	}
	else
		printf("\nGiven Key NOT FOUND!");
}
struct node *delFirst()
{
	struct node *delItem;
	if(last==NULL)
	{
		printf("\nNothing to DELETE, List is EMPTY!");
		return NULL;
	}
	delItem=last->next;
	last->next=delItem->next;
	return delItem;
}
struct node *delLast()
{
	struct node *ptr,*delItem;
	if(last==NULL)
	{
		printf("\nNothing to DELETE, List is EMPTY!");
		return NULL;
	}
	ptr=last->next;
	do{
		ptr=ptr->next;
	}while(ptr->next!=last);
	delItem=last;
	ptr->next=last->next;
	last=ptr;
	return delItem;
}
struct node *delAfter()
{
	int key_before;
	struct node *ptr,*delItem;
	if(last==NULL)
	{
		printf("\nNothing to DELETE, List is EMPTY!");
		return NULL;
	}
	printf("\nPlease Enter the Key of List Item after which Deletion is to be done:\t");
	scanf("%d",&key_before);
	ptr=findKey(key_before);
	if(ptr!=NULL)
	{
		//FOR REMOVING FIRST LINK-in Circular Linked List, 'last->next' is the first link.
		if(ptr->next==last->next)
			return delFirst();
		//FOR REMOVING THE LAST LINK
		if(ptr->next==last)
			return delLast();
		delItem=ptr->next;
		ptr->next=ptr->next->next;
		return delItem;
	}
	else
	{
		printf("\nGiven Key NOT FOUND!");
		return NULL;
	}
}

struct node *delAt()
{
	int key_at;
	struct node *ptr,*delItem;
	if(last==NULL)
	{
		printf("\nNothing to DELETE, List is EMPTY!");
		return NULL;
	}
	printf("\nPlease Enter the Key of List Item which is to be Deleted:\t");
	scanf("%d",&key_at);
	//ACCOUNTING FOR THE EXTREMITIES
	//FOR THE FIRST LINK
	if(last->next->key==key_at)
		return delFirst();
	//FOR THE LAST LINK
	if(last->key==key_at)
		return delLast();	
	ptr=findKey(key_at);
	if(ptr!=NULL)
	{
		delItem=ptr;
		ptr=last->next;
		while(ptr->next!=delItem){ ptr=ptr->next; }
		ptr->next=delItem->next;
		return delItem;
	}
	else
	{
		printf("\nGiven Key NOT FOUND!");
		return NULL;
	}
}

struct node *findKey(int k)
{
	struct node *ptr=last->next;
	do
	{
		if(ptr->key==k)
			return ptr;
		ptr=ptr->next;
	}while(ptr!=last->next);
	return NULL;
}

void displayList()
{
	struct node *ptr;
	printf("\nCircular Linked list is:\n");
	if(last==NULL)
		printf("EMPTY!\n");
	else
	{
		ptr=last->next;
		printf("\nKEY\tDATA\n");
		printf("---\t----");
		do
		{
			printf("\n%d\t%d",ptr->key,ptr->data);
			ptr=ptr->next;
		}while(ptr!=last->next);
		printf("\n");
	}
}
