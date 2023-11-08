#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void linked_list_traversal(struct node *ptr) // *ptr pointer first points to head and value of head is first store in *ptr pointer
{
	while(ptr !=NULL)  // while loop is used for traversing the list and ptr !=null menas ptr goes from head to null at last in linked list
	{
	printf("element:%d\n",ptr->data);  // ptr->head is used to print data in list
	ptr=ptr->next;  // ptr->next means ptr point to next node 
}
}
 int main()
 {
 	struct node*head;
 	struct node*second;
 	struct node*third;
 	// allocate meomry for nodes in the linked list in heap
 	head=(struct node*)malloc(sizeof(struct node));
 	second=(struct node*)malloc(sizeof(struct node));
 	third=(struct node*)malloc(sizeof(struct node));
 	// link first and second nodes
 	head->data=7;
 	head->next=second;
 	// link second and third nodes
 	second->data=11;
 	second->next=third;
 	// terminate the list at the third node
 	third->data=66;
 	third->next=NULL;
 	linked_list_traversal(head); // it is function call and here head is passed in function because value of head is stored in *ptr pointer
 	return 0;
 }
