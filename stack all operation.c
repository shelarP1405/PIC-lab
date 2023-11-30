#include <stdio.h>
# define size 5
int stack[size];
int top=-1;
void push()
{
    if(top==size-1)
    {
        printf("overflow,cannot push item\n");
    }
    else
    {
        int value;
        printf("Enter value to push:");
        scanf("%d",&value);
        top++;
        stack[top]=value;
        printf("pushed element is%d",value);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("stack is empty:");
    }
    else
    {
        int item;
        item=stack[top];
        top--;
        printf("popped %d from the stack\n",item);
    }
}

void peek()
{
    if(top==-1)
    {
        printf("stack is empty:\n" );
    }
    else
    {
        printf("peek=%d\n",stack[top]);
    }
}

void display()
{
    int i;
    if(top==-1)
    {
        printf("stack is empty:\n" );
    }
    else
    {
    printf("stack elements:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}
}
int main() {
   int choice;
   
   do
   {
       printf("Enter the Number:\n");
     printf("1. push\n");
    printf("2. pop\n");
    printf("3. peek\n");
    printf("4. display\n");
     printf("5. exit\n");
     printf("Enter your choice:");
     scanf("%d",&choice);

   switch(choice)
   {
       case 1:
       push();
       break;
       case 2:
       pop();
       break;
       case 3:
       peek();
       break;
       case 4:
       display();
       break;
       default:
       printf("Invalid choice please Enter valid choice\n");
   }
   }while(choice!=0);
    return 0;
}
