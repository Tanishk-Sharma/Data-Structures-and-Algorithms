/*
Program to Sort a given set of numbers using insertion sort, and search an element within sorted array using Linear search
Date: 26/07/2017
*/
#include<stdio.h>
#include<conio.h>

void insort(int [],int);
int linsearch(int [],int,int);
void main(){
	int a[10],n,i,element,location;
	clrscr();
	printf("\nPlease enter the size of array:\t");
	scanf("%d",&n);
	printf("\nPlease enter the array:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	insort(a,n);
	printf("\n\nSorted array:\n");
	for(i=0;i<n;i++)
		printf("%4d",a[i]);
	getch();
}
void insort(int a[],int n){
	int tmp,i,j,sorted=0,pos;
	for(i=sorted+1;i<n;i++)	{
		j=sorted;
		pos=i;
		do{
			if(a[j]>a[pos])			{
				tmp=a[j];
				a[j]=a[pos];
				a[pos]=tmp;
				pos=j;
			}
			j--;
		}while(j>=0);
		sorted++;
	}
}
