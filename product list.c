#include<stdio.h>
#include<stdlib.h>
struct product
{
	int id;
	char name[20];
	int quantity;
	float price;
	struct product *next;
};

int main()
{
	struct product *product1;
	struct product *product2;
	struct product *product3;
	// allocate memory for product in linked list
	
	product1=(struct product*)malloc(sizeof(struct product));
	product2=(struct product*)malloc(sizeof(struct product));
	product3=(struct product*)malloc(sizeof(struct product));
	
	struct product *bill = NULL;
	
	//   add product to the bill
	product1->id=1;
	printf("Enter the name for product 1:");
	scanf("%s",product1->name);
	product1->price=10.0;
	product1->quantity=3;
	product1->next=NULL;
	bill=product1;
	
	product2->id=2;
	printf("Enter the name for product 2:");
	scanf("%s",product2->name);
	product2->price=5.0;
	product2->quantity=1;
	product2->next=NULL;
	product1->next = product2;
	
	product3->id=3;
	printf("Enter the name for product 1:");
	scanf("%s",product3->name);
	product3->price=8.0;
	product3->quantity=2;
	product3->next=NULL;
	product2->next=product3;
	
	// calculate and display product bill
	printf("Product BILL:\n");
	printf("---------------------------\n");
	printf("ID\tName\tprice\tQuantity\ttotal\n");
	printf("-----------------------------\n");
	
	struct product *current=bill;
	float total=0;
	while(current!=NULL)
	{
	printf("%d \t %s \t %f \t %d \t\t %f\n",current->id,current->name,current->price,current->quantity,(current->price*current->quantity));
	total+=(current->price*current->quantity);
	current = current->next;	
	}
	printf("------------------------------\n");
	printf("total:%f\n",total);
	return 0;
}
