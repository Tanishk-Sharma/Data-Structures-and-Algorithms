#include<stdio.h>
#include<time.h>
#define MAX 50
int partition(int [],int,int);
void quicksort(int [],int,int);
void swap(int *,int *);
void display(int [],int);

void main(){
	int a1[MAX],n,i,j;
	printf("\nArray Size:\t");
	scanf("%d",&n);
	printf("\nEnter elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a1[i]);
	quicksort(a1,0,n-1);
}

int partition(int A[],int p,int r){
	int pivot=A[r],i=p-1,j;
	for(j=p;j<=r-1;j++){
		if(A[j]<=pivot){
			i=i+1;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],&A[r]);
	return (i+1);
}

void swap(int *p,int *q){
	int temp=*p;
	*p=*q;
	*q=temp;
}

void quicksort(int A[],int p,int r){
	int q;
	if(p<r){
		q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}
