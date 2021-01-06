#include <stdio.h>
#include <stdlib.h>

//A structure which has one value per node and a pointer to a similar node.
struct node{
    int data;
    struct node *next;
};

//A function to create and return a new node after assigning the given value to it.
struct node *create(int d)
{
struct node *new_node=(struct node *)malloc(sizeof(struct node));
new_node->data=d;
new_node->next=NULL;
}

//A function to insert a new element at the beginning of the linked list.
void insertBeg(struct node **head,int d)
{
struct node *temp=create(d);

temp->next=*head;
*head=temp;
}

//A function to insert a new element at the end of the list.
void insertEnd(struct node **head,int d)
{
struct node *temp=create(d),*f=*head;;
if(*head==NULL){
*head=temp;
return;
}
while(f->next!=NULL)
    f=f->next;
    
f->next=temp;
return;
}

void delete(struct node **head,int dk){
struct node *temp=*head,*pre; 
if(*head!=NULL&& (*head)->data==dk){
*head=temp->next;
free(temp);
return;
}
else{
    while(temp!=NULL&&temp->data!=dk){
        pre=temp;     
        temp=temp->next;
    }
    
//This condition implies that the whole list has been traversed but value to be deleted is not found.
    if(temp==NULL){
        printf("Element to be deleted not found");
        return;
    }
//If the node with the required value is found, the following is executed.
    pre->next=temp->next;
    temp->next=NULL;
    free(temp);
    printf("\n %d has been deleted.\n",dk);
}
}


//A fuction to display the linked list
void display(struct node *temp) {
    if(temp==NULL)
    {
      printf("There are no elements in the linked list\n"); 
    }
printf("The elements of the linked list:\n");
  while (temp != NULL) {
    printf(" %d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void main()
{
struct node *head=NULL;
int c,k;
while(1){
    printf("\nMenu (Linked List):\n1. Insert at the beginning\n2. Insert at the end\n3. Delete the specified element\n4.Display the Linked List\n5.Exit\n");
    printf("Enter your choice:\n");  
    scanf("%d",&c);
    switch(c){
        case 1: printf("Enter the element to be inserted:");
        scanf("%d",&k);
        insertBeg(&head,k);
        printf("\n %d has been inserted.\n",k);
        break;
        
        case 2: printf("Enter the element to be inserted:");
        scanf("%d",&k);
        insertEnd(&head,k);
        printf("\n %d has been inserted.\n",k);
        break;

        case 3: printf("Enter the element to be deleted:");
        scanf("%d",&k);
        delete(&head,k);
        break;
        
        case 4:
        display(head);
        break;
        
        case 5: exit(0);
        break;
        
        default: printf("Invalid choice\n");
    }
    
}

}
