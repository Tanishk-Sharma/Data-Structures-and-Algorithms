#include<stdio.h>
#include<conio.h>
void setCount(int [],int [],int);
void updateCount(int []);
void countSort(int [],int [],int [],int);
void display(int []);
void main()
{
	int arr[10],count[10],sorted[10],i,lower,upper;
	clrscr();
	printf("\nEnter lower bound and upper bound:\n");
	scanf("%d",&lower);
	scanf("%d",&upper);
	printf("\nEnter 10 elements:\n");
	for(i=0;i<10;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<10;i++)
		count[i]=0;
	setCount(count,arr,lower);
	printf("\ncount 1:");
	display(count);
	updateCount(count);
	printf("\ncount 2:");
	display(count);
	countSort(count,arr,sorted,lower);
	printf("\nSorted array:");
	display(sorted);
	getch();
}
void setCount(int freq[],int a[],int lower)
{
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			if(a[j]==(i+lower))
				freq[i]++;
}

void updateCount(int freq[])
{
	int i;
	for(i=1;i<10;i++)
		freq[i]=freq[i]+freq[i-1];
}
void display(int arr[])
{
	int i;
	printf("\n");
	for(i=0;i<10;i++)
		printf("%3d",arr[i]);
}
void countSort(int freq[],int a[],int sorted[],int lower)
{
	int i;
	for(i=10-1;i>=0;i--)
	{
	  sorted[freq[a[i]-lower]-1]=a[i];
	  freq[a[i]-lower]--;
	}
}
