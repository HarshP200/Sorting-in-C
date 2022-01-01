#include<stdio.h>

void Shell_Sort(int arr[],int n){
	int gap,i,j;
	
	for(gap = n/2;gap>=1;gap/=2){
		for(i = gap;i<n;i++){
			int tem = arr[i];
			j = i-gap;
			while(j>=0 && arr[j]>tem){
				arr[j+gap] = arr[j];
				j-=gap;
			}
			arr[j+gap] = tem;
		}
	}
}


int main()
{
	int arr[50],n,i;
	printf("Enter the no of elements for Shell sort: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)	scanf("%d",&arr[i]);
	
	Shell_Sort(arr,n);
	
	printf("Sorted Elements: ");
	for(i=0; i<n; i++)	printf("%d ",arr[i]);
	
}
