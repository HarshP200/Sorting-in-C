#include<stdio.h>


void swap(int *x,int *y){
	int tem = *x;
	*x = *y;
	*y = tem;
}


//Both Stable and Adaptive
void Bubble_Sort(int arr[],int n){
	int i, j, flag;
	for(i=0;i<n-1;i++){
		flag = 0;
		for(j=0;j<n-1-i;j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				flag++;
			}
		}
		if(flag == 0)	break;
	}
}


int main()
{
	int arr[50],n;
	printf("Enter the no of elements for Bubble sort: ");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)	scanf("%d",&arr[i]);
	
	Bubble_Sort(arr,n);
	
	printf("Sorted Elements: ");
	for(i=0; i<n; i++)	printf("%d ",arr[i]);
	
	return 0;
}
