#include<stdio.h>

//Merge Sort is only sorting that require extra space

void Array_Merge(int arr[],int f,int m,int l){
	int i = f, j = m+1, p=0,x;
	int tem[l-f+1];
	while(i<=m && j<=l){
		if(arr[i] > arr[j])	tem[p++] = arr[j++];
		else	tem[p++] = arr[i++];
	}

	while(i<=m)	tem[p++] = arr[i++];
	while(j<=l)	tem[p++] = arr[j++];

	for(x=0;x<p;x++)	arr[f+x] = tem[x];

}


void IMerge_Sort(int arr[],int n){
	int i,j;
	for(i=2;i<=n;i=i* 2){
		for(j=0; j+i-1 < n; j = j+i){
			Array_Merge(arr,j,(j+j+i-1)/2,j+i-1);
		}
	}

	if(i/2<n)	Array_Merge(arr,0,(i/2)-1,n-1);
}

void RMerge_Sort(int arr[], int f,int l){        //Time Complexity O(nlogn)
    if(f<l){
        int mid = (f+l)/2;
        RMerge_Sort(arr,f,mid);
        RMerge_Sort(arr,mid+1,l);
        Array_Merge(arr,f,mid,l);
    }
}

int main()
{
	int n,i;
	printf("Enter the no of elements for Merge sort: ");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)	scanf("%d",&arr[i]);

	IMerge_Sort(arr,n);
//    RMerge_Sort(arr,0,n);
	printf("Sorted Elements: ");
	for(i=0; i<n; i++)	printf("%d ",arr[i]);

}
