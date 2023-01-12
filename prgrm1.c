#include<stdio.h>
void main()
{
int a[10],b[15],c[20],i,j,k,m,n1,n2;
printf("enter the array limit n1 of first array");
scanf("%d",&n1);
printf("enter the array elements:\n");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the array limit n2 of the second array");
	scanf("%d",&n2);
	printf("enter the array elements:\n");
	for(j=0;j<n2;j++)
	{
		scanf("%d",&b[j]);
	}
//comparison
i=0;j=0;k=0;
	while(i<n1 && j<n2)
	{
		if(a[i]>b[j])
		{
		c[k]=b[j];
		j++;
		k++;
		}
		else if(a[i]<b[j])
		{
		c[k]=a[i];
		i++;
		k++;
		}
		else
		{
		c[k]=a[i];
		i++;
		j++;
		k++;
		}
	}
while(i<n1)
{
c[k]=a[i];
i++;
k++;
}
while(j<n2)
{
c[k]=b[j];
j++;
k++;
}
m=k;
for(k =0;k<m;k++)
{
printf("the new array is:%d",c[k]);
}
}
		
