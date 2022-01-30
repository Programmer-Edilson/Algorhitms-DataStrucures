#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
	struct node *left;
	struct node *right;
}
node;

node* create_node(int data);
node* insert(node *head, int data);
node* search(node *head, int key);
void show_in_order(node *head);

int main()
{
    node *head = NULL; //make it global to avoid pass as parameter
    head = insert(head, 10);
    head = insert(head, 8);
    head = insert(head, 15);
    head = insert(head, 12);
    head = insert(head, 20);
    head = insert(head, 10);

	node *result = search(head, 20);
    if(result)
		printf("%d found\n", result->data);

    printf("in order: ");
    show_in_order(head);
    printf("\n");

    return 0;
}

node* create_node(int data)
{
    node *new = (node*) malloc(sizeof(node));
	
	new->data = data;
	new->left = NULL;
	new->right = NULL;

	return new;
}

// linear insertion
node* insert(node *head, int data)
{
    node *new = create_node(data);

	if(!head)
    {
		head = new;
		printf("%d as head\n", new->data);
		return head;
	}

	node *parent = head;
	node *current = head;

	while(1)
    {
		if(current->data > new->data)
		{
		    if(!current->left)
		    {
				parent->left = new;
				printf("%d at left of %d\n", data, parent->data);
				break;
		     } else
				current = current->left;
		}
		else if(current->data <= new->data)
		{
		    if(!current->right)
		    {
				parent->right = new;
				printf("%d at right of %d\n", data, parent->data);
				break;
		    } else
				current = current->right;
		}
		parent = current;
	}	
	return head;
}

// recursive search
node* search(node *head, int key)
{
    if(!head)
		return NULL;
	if(head->data > key)
		return search(head->left, key);
	else if(head->data < key)
		return search(head->right, key);
	else
		return head;
}

// show from min element to max element
void show_in_order(node *head)
{
    if(!head)
		return;
	show_in_order(head->left);
	printf("%d ", head->data);
	show_in_order(head->right);
}
