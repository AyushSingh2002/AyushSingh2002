#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void createList(int n);
void addAtFirst(int num);
void addAtLast(int num, int len);
void delFirstNode();
void delLastNode();
void delCLL();
void display();

struct node
{
	int data;
	struct node *next;
}

struct node *head;

int main()
{
	int n, choice=1, data;
	printf("\n		MENU");
	printf("\nPress 1 to create a Circular Linked List.");
	printf("\nPress 2 to insert a node at the beginning of the List.");
	printf("\nPress 3 to insert a node at the end of the List.");
	printf("\nPress 4 to delete a node at the front of List.");
	printf("\nPress 5 to delete a node at the end of the Lsit.");
	printf("\nPress 6 to delte the Circular Linked List.");
	printf("\nPress 7 to Display the List.");
	printf("\nPress 0 to Exit.");
	while(choice!=0)
	{
		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the number of nodes you want to insert in the list: ");
				scanf("%d", &n);
				createList(n);
				break;
			case 2:
				printf("\nEnter the number you want to insert at the first node of the List: ");
				scanf("%d", &data);
				addAtFirst(data);
				n++;
				break;
			case 3:
				printf("\nEnter the number you want to insert at the last node of the List: ");
				scanf("%d", &data);
				addAtLast(data, n);
				n++;
				break;
			case 4:
				delFirstNode();
				break;
			case 5:
				delLastNode();
				break;
			case 6:
				delCLL();
				break;
			case 7:
				display();
				break;
			case 0:
				break;
			default:
				printf("\nError! Invalid Choice. Please enter a valid Input between 0 and 7.");
		}
		printf("\n\n\n");
	}
}
void createList(int n)
{
	int num, i;
	struct node *prevNode, *nextNode;
	if(n>=1)
	{
		head = (struct node *)malloc(sizeof(struct node));
		printf("\nEnter data of node 1: ");
		scanf("%d", &num);
		head->data = num;
		head->next = NULL;
		prevNode = head;
		for(i=2; i<=n; i++)
		{
			nextNode = (struct node *)malloc(sizeof(struct node));
			printf("\nEnter data of node %d: ",i);
			scanf("%d", &num);
			nextNode->data = num;
			nextNode->next = NULL;
			prevNode->next = nextNode;
			prevNode = nextNode;
		}
		prevNode->next = head;
		printf("\nCircular Linked List Created Sucessfully!");
	}
	else
	{
		printf("\n\nEnter a valid number of nodes.");
	}
}

void addAtFirst(int num)
{
	struct node *newNode, *current;
	if(head == NULL)
	{
		printf("\n\nLIST IS EMPTY!");
	}
	else
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data = num;
		newNode->next = head;
		current = head;
		while(current->next != head)
		{
			current = current->next;
		}
		current->next = newNode;
		head = newNode;
		printf("\nNode Sucessfully added at the beginning of the Linked List.");
	}
}

void addAtLast(int num, int len)
{
	int i;
	struct node *newNode, *current;
	if(head == NULL)
	{
		printf("\nLIST IS EMPTY!");
	}
	else
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data = num;
		current = head;
		for(i=2; i<=len-1; i++)
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		printf("\nNode Sucessfully added at the end of the Linked List.");
	}
}

void delFirstNode()
{
}

void delLastNode()
{
}

void delCLL()
{
}

void display()
{
	int n=1;
	struct node *current;
	if(head==NULL)
	{
		printf("\n\nList is Empty.");
	}
	else
	{
		current = head;
		printf("\nDATA IN THE LIST: ");
		do
		{
			printf("\nData %d: ",n, current->data);
			current = current->next;
			n++;
		}
		while(current!=head);
	}
	printf("\n----END OF LIST----");
}
