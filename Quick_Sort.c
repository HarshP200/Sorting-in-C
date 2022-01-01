#include<stdio.h>

void swap(int *x,int *y){
	int tem = *x;
	*x = *y;
	*y = tem;
}


int Partition(int arr[], int m, int n){
	int tem = arr[m];
	int i=m,j=n+1;
	
	do{
		do{i++;}	while(arr[i]<tem && i<=n);
		do{j--;}	while(arr[j]>tem && j>=m);
		
		if(i<j)	swap(&arr[i],&arr[j]);
	}while(i<j);
	swap(&arr[m],&arr[j]);
	return j;
}


void Quick_Sort(int arr[],int m,int n){
	int x;
	if(m<n){
		x = Partition(arr,m,n);
		Quick_Sort(arr,m,x-1);
		Quick_Sort(arr,x+1,n);
	}
}


int main()
{
	int i,arr[50],n;
	printf("Enter the no of elements for Quick sort: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&arr[i]);
	
	Quick_Sort(arr,0,n-1);
	
	printf("Sorted Elements: ");
	for(i=0; i<n; i++)	printf("%d ",arr[i]);
	
	return 0;
}
