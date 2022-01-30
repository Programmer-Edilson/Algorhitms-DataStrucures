#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
}
node;

node* create_node(int data);
void enqueue(int data);
void dequeue();
void display(node* head);

node *head = NULL;

int main() {
    printf("\n");
    int array[] = {65, 90, 12, 53};
	
	for(int i=0; i<4; i++)
    {
		enqueue(array[i]);
    }
	printf("display: ");
	display(head);
	printf("\n");
	dequeue();
	dequeue();
	printf("display: ");
	display(head);
	printf("\n");

}

node* create_node(int data) {
    node *new = (node*) malloc(
					sizeof(node));
	new->data = data;
	new->prev = NULL;

	return new;
}

void enqueue(int data) {
    node *new = create_node(data);

	if(!head)
    {
		head = new;
		printf("%d as head\n", new->data);
		return;
    }

	node *temp = head;
	while(temp->prev)
    {
		temp = temp->prev;
	}

	temp->prev = new;
	printf("%d enqueded\n", new->data);
}

void dequeue()
{
    node *temp = head;
	head = head->prev;
	printf("%d dequeded\n", temp->data);
	free(temp);

}

void display(node* head)
{
    if(!head)
		return;
	printf("%d ", head->data);
	display(head->prev);
}

