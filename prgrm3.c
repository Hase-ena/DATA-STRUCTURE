//CIRCULAR QUEUE
#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void display();
int A[10],F=-1,R=-1,n=4,e,i;
//insertion
void insert()
{
printf("Enter the items:");
scanf("%d",&e);
if(F==(R+1)%n)
	{
		printf("circular queue is full");
	}
else if(F==-1)
	{
		F=0;
		R=0;
		A[R]=e;
	}
else
	{
	R=(R+1)%n;
	A[R]=e;
	}
}
void delete_beg()
{
if(F==-1)
{
	printf("queue is empty");
}
else if(F==R)
{
	printf("enter the item to be deleted is %d",A[F]);
}
else
{
	F=(F+1)%n;
	printf("item deleted\n");
}
}
void display()
{
int i;
if(R<F)
{
	for(i=F;i<=n-1;i++)
	printf("%d\n",A[i]);
		if(F!=0)
		{
			for(i=0;i<=R;i++)
			printf("%d\n",A[i]);
		}
}
		else
		{
		for(i=F;i<=R;i++)
		printf("%d",A[i]);
		}
}
void main()
{
int x,opt;
	do
	{
	printf("enter the options\n 1.INSERT\n 2.DELETE\n 3.DISPLAY\n 4.EXIT\n");
	scanf("%d",&opt);
		switch(opt)
		{
		case 1:insert();
			break;
		case 2:delete_beg();
			break;
		case 3:display();
			break;
		case 4:exit(0);
		default:printf("invalid");
		}
		printf("do you want to continue 1/2\n");
		scanf("%d",&x);
	}
while(x==1);
}



