#include<stdio.h>
#include<stdlib.h>

struct node{ 
	int data;
	struct node *next;
};

struct node *top=NULL;

void push()
{
struct node *new =NULL;
new = (struct node*)malloc(sizeof(struct node));
if (new == NULL)
{
printf("OverFlow\n");
}
else
{
printf("Enter the element:");
scanf("%d",&new->data);
new->next = top;
top = new;	 
}
}

void pop()
{
struct node *ptr;
if(top == NULL)
{
printf("UnderFlow\n");
}
else
{
printf("Poped element :%d",top->data);
ptr = top;
top=top->next;
free(ptr);
}
}

void display()
{
struct node *ptr;
if(top == NULL)
{
printf("Stack is Empty\n");
}
else
{
printf("The Stack elements:");
ptr=top;
while(ptr !=NULL)
{
printf("%d",ptr->data);
ptr=ptr->next;		
}
}
}

void main()
{
int opt;
do
{
printf("\n/......Stack...../\n");
printf("\nEnter the Options\n1.push\n2.pop\n3.display\nExit->0:");
scanf("%d",&opt);
	
switch(opt){
case 1:push();
break;
case 2:pop();
break;
case 3:display();
break;
case 4 :exit(0);
break;
}
}
while(opt != 0);
	
}




