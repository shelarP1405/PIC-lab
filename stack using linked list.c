#include <stdio.h>
#include<stdlib.h>

struct stack {
    int data;
    struct stack *link;
};

struct stack *top=0; // initially top=0

void push(int x)
{
	struct stack* newnode;
	newnode=(struct stack *)malloc(sizeof(struct stack));
	newnode->data=x;
	newnode->link=top;
	top=newnode;
}

int pop()
{
	struct stack *temp;
	temp=top;
	if(top==0)
	{
		printf("stack is underflow:");
	}
	else
	{
		printf("popped element is %d",top->data);
		top=top->link; // top->link means top is pointing to prevoius node of popped node
		free(temp);  // free(temp)	means we free memory of popped element
}
}
void display()
{
	struct stack *temp;
	temp=top;  // address of top is stored in temp pointer
	while(temp!=0)
	{
		printf("%d \n",temp->data);
		temp=temp->link;
	}
}
int main() {
    
	int choice, value;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                // Do nothing, just exit the loop
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
