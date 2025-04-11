#include<stdio.h>
void main()
{
	int m,bs[10],n,ps[10],alloc[10],i,j;
	printf("Enter the no. of memory blocks: ");
	scanf("%d",&m);
	printf("Enter the size of the blocks: ");
	for(i=0;i<m;i++)
	{
		scanf("%d",&bs[i]);	
    }
	printf("Enter the no. of process:");
	scanf("%d",&n);
	printf("Enter the process size:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ps[i]);
		alloc[i]=-1;		
    }
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(bs[j]>=ps[i])
			{
				alloc[i]=j;
				bs[j]=bs[j]-ps[i];
				break;
			}
		}
	}
	printf("Process no.\tProcess size\tBlock no.\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t",i,ps[i]);
		if(alloc[i]!=-1)
		{
			printf("%d\n",alloc[i]);	}
		else
			printf("Not allocated\n");
	}
}