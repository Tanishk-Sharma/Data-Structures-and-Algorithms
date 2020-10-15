#include<stdio.h>

int main(){
	int arr[100], i, n, j, tmp, ele, begin=0, end, mid, flag=0;
	printf("\nPlease Enter size of array(Max. 100): ");
	scanf("%d",&n);
	printf("\n\nEnter Number at:\n");
	for(i=0;i<n;i++){
		printf("\nIndex %d:\t",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nSorted array:\n");
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
  for(i=0;i<n;i++)
		printf("  %d  ",arr[i]);
 }
