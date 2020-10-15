#include<stdio.h>
#include<time.h>
#define MAX 50


int partition(int [],int,int);
void quicksort(int [],int,int);
void swap(int *,int *);
void display(int [],int);
void arrayCopy(int [],int [],int);
void bubbleSort(int [],int);
void insertionSort(int [],int);


void main(){
	int a1[MAX],a2[MAX],a3[MAX],n,i,j;
	time_t t1,t2;
  
	printf("\nArray Size:\t");
	scanf("%d",&n);
  
	printf("\nEnter elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a1[i]);
    
	arrayCopy(a1,a2,n);
	arrayCopy(a1,a3,n);
  
	t1=clock();
	quicksort(a1,0,n-1);
	t2=clock();
	printf("\nQuickSort: %lf",((double) (t2 - t1)) / CLOCKS_PER_SEC);
	display(a1,n);
  
	t1=clock();
	bubbleSort(a2,n);
	t2=clock();
	printf("\nBubble Sort: %lf",((double) (t2 - t1)) / CLOCKS_PER_SEC);
	display(a2,n);
  
	t1=clock();
	insertionSort(a3,n);
	t2=clock();
	printf("\nInsertion Sort: %lf",((double) (t2 - t1)) / CLOCKS_PER_SEC);
	display(a3,n);
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
	if(p<r)	{
		q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

void display(int A[],int n){
	int i;
	printf("\nArray:\n");
	for(i=0;i<n;i++)
		printf("%4d",A[i]);
	printf("\n");
}

void arrayCopy(int src[],int target[],int n){
	int i;
	for(i=0;i<n;i++)
		target[i]=src[i];
}

void bubbleSort(int a[],int n){
	int i,j,tmp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
}

void insertionSort(int a[],int n){
	int tmp,i,j,sorted=0,pos;
	for(i=sorted+1;i<n;i++){
		j=sorted;
		pos=i;
		do{
			if(a[j]>a[pos]){
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
