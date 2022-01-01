#include<stdio.h>

#define MAX_VALUE 1000

// Time Complexity is O(n)
// But Takes a lot of space, as it creates an array of max size of input.
void Count_Sort(int arr[], int n){
	
	int i, max = arr[0];
	
	for(i=1;i<n;i++){
		if(max<arr[i])	max = arr[i];
	}
	
	int count[MAX_VALUE] = {0};
	for(i=0;i<n;i++)	count[arr[i]]++;
	
	int x=0;
	for(i=0;i<max+1;i++){
		if(count[i] != 0){
				count[i]--;
				arr[x++] = i--;
		}
	}
	
	
	
}

int main(){
	printf("Enter the size of array for Count Sort: ");
	int n;
	scanf("%d",&n);
	printf("Enter the elements of array: ");
	int i, arr[n];
	for(i=0;i<n;i++)	scanf("%d",&arr[i]);
	
	Count_Sort(arr,n);
	
	printf("Sorted Array: ");
	for(i=0;i<n;i++)	printf("%d ",arr[i]);	

	return 0;
}
