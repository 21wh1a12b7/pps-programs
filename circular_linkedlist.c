#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}node;
node *getnode();
node *head = NULL;
node *temp = NULL;
void insert_beg();
void traverse();
void insert_end();
void delete_beg();
void delete_end();
/*void delete_at_posk();*/
void insert_at_posk();
void display();
void main()
{
	int ch;
	while(1)
	{
		printf("1.Insert at begining\n2.Display the circular list\n3.Insert at end\n4.Insertion at position k\n5.Delete at beginning\n6.Deletion at end\n7.Deletion at position k\n8.exit\n");
		printf("Enter your position\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : printf("Insertion at begining\n");
				 insert_beg();
				 break;
			case 2 : if(head==NULL)
				 {
					 printf("List is EMPTY!\n");
				 }
				 else
				 {
					 printf("Display the list\n");
				 }
				traverse();
				break;
			case 3 : printf("Insertion at end\n");
				 insert_end();
				 break;
			case 4 : printf("Insertion at position k\n");
				 insert_at_posk();
				 break;
			case 5 : printf("Delete at beginning\n");
				 delete_beg();
				 break;
			case 6 : printf("Delete at end\n");
				 delete_end();
				 break;
			/*case 7 :printf("Delete at position k\n");
				 delete_at_posk();
				 break;*/
			case 8 : exit(0);
				 break;
		}
	}
}
void traverse()
{
	node *curr = head;
	if(curr == NULL)
		printf("list is EMPTY!\n");
	else
	{
		while(curr->next != head)
		{
			printf("%3d",curr->data);
			curr = curr->next;
		}
		printf("%3d",curr->data);
	}
}
void insert_beg()
{
	node *new = getnode();
	if(head==NULL)
	{
		head = new;
		head->next = head;
		temp = head;
	}
	else
	{
		new->next = head;
		temp->next = new;
		head = new;
	}
}
node *getnode()
{
	node *new = (node *)malloc(sizeof(node));
	printf("enter data:");
	scanf("%d",&new->data);
	new->next = NULL;
	return new;
}
void insert_end()
{
	node *new = getnode();
	if(head==NULL)
	{
		head = new;
		head->next = head;
		temp = head;
	}
	else
	{
		temp->next=new;
		new->next=head;
		temp=new;
	}
}
void delete_beg()
{
	node *new = getnode();
	node *ptr = head;
	if(head->next == head)
	{
		head = NULL;
		temp = NULL;
		free(ptr);
	}
	else
	{
		temp->next = head->next;
		head = head->next;
		free(ptr);
	}
}
void insert_at_posk(int k)
{
	printf("Enter k:");
	scanf("%d",&k);
	int i;
	node *new = getnode();
	temp = head;
	for(i=1; i<=k; i++)
		temp = temp->next;
		new->next = temp->next;
		temp->next = new;
}
void delete_end()
{
	node *new = getnode();
	node *ptr = head;
	if(head->next==head)
	{
		head = NULL;
		temp = NULL;
		free(ptr);
	}
	else
	{
		node *temp1 = head;
		while(temp->next != temp)
		{
			temp1 = temp1->next;
			temp1->next = head;
			temp1 = temp;
			free(ptr);
		}
	}
}
