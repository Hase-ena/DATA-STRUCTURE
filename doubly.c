#include<stdio.h>
#include<stdlib.h>
void create();
void insert_beg();
void insert_end();
void insert_position();
void delete_beg();
void del_end();
void del_position();
void display();
void search();
struct node
{
struct node *next;
struct node *prev;
int data;
};
struct node *head=NULL;
struct node *new=NULL;

void create()
{
int x;
new=(struct node*)malloc(sizeof(struct node));
if(new==NULL)
printf("insufficient memory");
else
{
printf("\n enter the data to insert \n");
scanf("%d",&x);
new->data=x;
new->next=NULL;
}
}
void insert_beg()
{
		struct node *ptr;
		int item;
		ptr=(struct node*)malloc(sizeof(struct node));
		if (ptr==NULL)
		{
		  printf("\nOverflow");
		}
		else
		{
		  printf("\nEnter item:");
		  scanf("%d",&item);
		
		if(head==NULL)
		{
		  ptr->next=NULL;
		  ptr->prev=NULL;
		  ptr->data=item;
		  head=ptr;
		}
		
		else
		{
		  ptr->data=item;
		  ptr->prev=NULL;
		  ptr->next=head;
		  head->prev=ptr;
		  head=ptr;
		}
		}
		
		printf("Node is inserted\n");
	}
void insert_end()
{
		struct node *ptr,*temp;
		int item;
		ptr=(struct node*)malloc (sizeof(struct node));
		if (ptr==NULL)
		{
		  printf("\nOverflow");
		}
		else
		{
		  printf("\nEnter item:");
		  scanf("%d",&item);
		  ptr->data=item;
		if(head==NULL)
		{
		  ptr->next=NULL;
		  ptr->prev=NULL;
		  head=ptr;
		}
		
		else
		{
		  temp=head;
		while(temp->next!=NULL)
		{
		  temp=temp->next;	
		}
		  temp->next=ptr;
		  ptr->prev=temp;
		  ptr->next=NULL;
		}
		}
		
		printf("Node is inserted\n");
	}
	
void insert_position()
{
		struct node *ptr,*temp;
		int item,i,loc;
		ptr=(struct node*)malloc(sizeof(struct node));
		if (ptr==NULL)
		{
		  printf("\nOverflow");
		}
		else
		{
		  temp=head;
		  printf("Enter the location:");
		  scanf("%d",&loc);
		  for (i=1;i<loc-1;i++)
		   {
		     temp=temp->next;
		     if(temp==NULL)
			{
				printf("there are less than %d elements\n",loc);
				return;
			}	

		   }
		   printf("Enter value:");
		   scanf("%d",&item);
		   ptr->data=item;
		   ptr->next=temp->next;
		   ptr->prev=temp;
		   temp->next=ptr;
		   temp->next->prev=ptr;
		   printf("\nNode is inserted\n");
		}
	}
	
void delete_beg()
{
		struct node *ptr;
		if(head==NULL)
		{
		  printf("Underflow\n");
		}

		else if(head->next==NULL)
		{
		  head=NULL;
		  free(head);
		  printf("\n node is deleted\n");	
		}

		else
		{
		  ptr=head;
		  head=head->next;
		  head->prev=NULL;
		  free(ptr);
		  printf("\n node is deleted\n");
		}
	}
 void del_end()
{
		struct node *ptr,*temp;
		if (head==NULL)
		{
		printf("\nUnderflow");
		}
		else if(head->next==NULL)
		{
		  head=NULL;
		  printf("\nnode is deleted\n");	
		}
		else
	        {
		  ptr=head;
		  while(ptr->next!=NULL)
		  {
	             ptr=ptr->next;
		  }
		  temp=ptr->prev;
		  temp->next=NULL;
		  ptr->prev=NULL;
		  printf("\nNode is deleted\n");
		}

	}
void del_position()
{
		struct node *ptr,*temp1,*temp;
		int val;

		printf("enter the position to delete:\n");
		scanf("%d",&val);

		ptr=head;

		while(ptr->data!=val)
		       {	
		        ptr=ptr->next;
		       }
			temp=ptr->prev;
			temp1=ptr->next;
			temp->next=temp1;
			ptr->prev=NULL;
			ptr->next=NULL;
			temp1->prev=temp;
		
		   
	}
void display()
{
struct node *ptr;
printf("The linked list is:");
ptr=head;
while(ptr!=NULL)
{
printf("%d\n",ptr->data);
ptr=ptr->next;
}
}

void search()
 	{
	 	struct node *ptr;
		int item,i=0,flag;
		ptr=head;
		if(ptr==NULL)
		{
		printf("Empty list\n");
		}
		else
		{
		 printf("Enter the element you want to search:");
		 scanf("%d",&item);
		}
		while (ptr!=NULL)
		{
		   if(ptr->data==item)
			{
			  printf("Item you have searched is found at the location %d",i+1);
			  flag=0;
			  break;
			}
		   else
			{
			  flag=1;
			}
			  i++;
			  ptr=ptr->next;
		}
		if(flag==1)
		{
		  printf("Item you have searched for is not found at the location.\n");
		}
	}
	
int main()
{
int c,opt;
do
{
printf("\n1.insert at beginning \n 2.insertion at end \n 3.insertion at specific position \n 4.delete beg \n 5.delete_end \n  6. delete_position \n 7.display \n 8.search \n");
scanf("%d",&opt);
switch(opt)
{

  case 1:insert_beg();
         display();
         break;
  case 2:insert_end();
         display();
         break;
  case 3:insert_position();
         display();
         break;
  case 4:delete_beg();
         display();
         break;
  case 5:del_end();
         display();
         break;
  case 6:del_position();
         display();
         break;
  case 7:display();
         break;
  case 8:search();
         break;
  default:printf("\n invalid");
}
printf("do you want to continue (1/2):");
 scanf("%d",&c);
}
while(c==1);
}

