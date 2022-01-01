#include<stdio.h>

//Both Stable and Adaptive
void Insertion_Sort(int arr[],int n){
	int i;
	for(i=1;i<n;i++){
		int x = arr[i],j = i-1;
		while(j>=0 && arr[j]>x){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = x;
	}
}


int main()
{
	int arr[50],n;
	printf("Enter the no of elements for Insertion sort: ");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)	scanf("%d",&arr[i]);
	
	Insertion_Sort(arr,n);
	
	printf("Sorted Elements: ");
	for(i=0; i<n; i++)	printf("%d ",arr[i]);
	
	return 0;
}
