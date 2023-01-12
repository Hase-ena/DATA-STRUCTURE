//doubly


#include<stdio.h>
#include<stdlib.h>
void display();
void insert_first();
void insert_beg();
void insert_end();
void delete_beg();
void create();
void insert_position();
struct node
{
struct node *next;
struct node *prev;
int data;
};
struct node *head=NULL;
struct node *new=NULL;
struct node *ptr=NULL;
struct node *temp=NULL;
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
void insert_first()
{
struct node *prev;
create();
if(head==NULL)
{
head=new;
}
else
{
ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
prev=ptr;
}
ptr->next=new;
new->next=NULL;
}
}
void insert_beg()
{
create();
if(head==NULL)
{
head=new;
}
else
{
new->next=head;
head=new;
}
}
void insert_end()
{
struct node *ptr;
struct node *prev;
create();
ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
prev=ptr;
}
ptr->next=new;
new->next=NULL;
}
void insert_position()
{
int key;
struct node *ptr1;
struct node *prev;
create();
printf("enter the position to be inserted");
scanf("%d",&key);
ptr=head;
while(ptr->next!=NULL && ptr->data!=key)
{
ptr=ptr->next;
prev=ptr;
}
if(ptr->next==NULL)
{
ptr->next=new;
new->prev=ptr;
}
else
{
ptr1=ptr->next;
new->next=ptr1;
new->prev=ptr;
ptr->next=new;
ptr1->prev=new;

}
}
void delete_beg()
{
if(head==NULL)
{
printf("no elements");
}
else
{
ptr=head;
head=ptr->next;
}
}
 void dele()

{

ptr=head;

while(ptr->next!=NULL)

{

ptr=ptr->next;

}

if(ptr->next==NULL)

{

temp=ptr->prev;

temp->next=NULL;

ptr->prev=NULL;

printf("\n %d is deleted ",ptr->data);

}

}
void delm()

{

int key;

printf("enter the key to be deleted ");

scanf("%d",&key);

if(head->data==key)

{

head=head->next;

}

temp=head;

ptr=head->next;

while(ptr!=NULL)

{

if(ptr->data==key)

{

temp->next=ptr->next;

temp->prev=ptr->prev;

free(ptr);

printf("\n %d is deleted ",key);

}

else

{

temp=ptr;

ptr=ptr->next;

}

}

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
int main()
{
int c,opt;
do
{
printf("\n1.creation \n 2.insert at beginning \n 3.insertion at end \n 4.insertion at specific position \n 5.delete \n 6.delete_end \n  7. delete_position \n 8.display \n");
scanf("%d",&opt);
switch(opt)
{

  case 1:insert_first();
         break;
  case 2:insert_beg();
         display();
         break;
  case 3:insert_end();
         display();
         break;
  case 4:insert_position();
         display();
         break;
  case 5:delete_beg();
         display();
         break;
  case 6:dele();
         display();
         break;
  case 7:delm();
         display();
         break;

  case 8:display();
         break;
  default:printf("\n invalid");
}

 printf("do you want to continue (1/2):");
 scanf("%d",&c);
}
while(c==1);
}

