#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}
node;

node* create_node(int data);
void push(int data);
void pop();
void display(node* head);

node *top = NULL;

int main() {
    printf("\n");
    int array[] = {65, 90, 12, 53};
	
	for(int i=0; i<4; i++)
    {
		push(array[i]);
    }
	printf("display: ");
	display(top);
	printf("\n");
	pop();
	pop();
	printf("display: ");
	display(top);
	printf("\n");

}

node* create_node(int data) {
    node *new = (node*) malloc(
					sizeof(node));
	new->data = data;
	new->next = NULL;

	return new;
}

void push(int data) {
    node *new = create_node(data);

	if(!top)
    {
		top = new;
		printf("%d as head\n", new->data);
		return;
    }

	node *temp = top;
	top = new;
	top->next = temp;
	printf("%d pushed\n", new->data);
}

void pop()
{
    node *temp = top;
	top = top->next;
	printf("%d popped\n", temp->data);
	free(temp);
}

void display(node* top)
{
    if(!top)
		return;
	printf("%d ", top->data);
	display(top->next);
}

