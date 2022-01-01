#include<stdio.h>


void swap(int *x,int *y){
	int tem = *x;
	*x = *y;
	*y = tem;
}


//Neither Stable, Nor Adaptive
void Selection_Sort(int arr[],int n){
	int i, j;
	for(i=0;i<n-1;i++){
		int k=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[k])	k = j;
		}
		swap(&arr[k],&arr[i]);
	}
}


int main()
{
	int arr[50],n;
	printf("Enter the no of elements for Selection sort: ");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)	scanf("%d",&arr[i]);
	
	Selection_Sort(arr,n);
	
	printf("Sorted Elements: ");
	for(i=0; i<n; i++)	printf("%d ",arr[i]);
	
}
