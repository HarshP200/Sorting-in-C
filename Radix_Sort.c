#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int data;
	struct node *next;
};

int max_count(int arr[],int n){
	int max = arr[0];
	int i;
	for(i=1;i<n;i++)	if(max<arr[i])	max = arr[i];
	return max;
}

int digit_count(int n){
	int count = 0;
	while(n>0){
		n = n/10;
		count++;
	}
	return count;
}


void Insert(struct node **a,int val){
	struct node *tem = (struct node *)malloc (sizeof(struct node));
	tem->data = val;
	tem->next = NULL;
	
	struct node *root = tem;
	root->next = *a;
	*a = root;
}


int Delete(struct node **a){
	struct node *tem = *a;
	if(tem->next == NULL){
		int x = tem->data;
		*a = NULL;
		free(tem);
		return x;
	}
	
	struct node *tem1;
	while(tem->next){
		tem1 = tem;
		tem = tem->next;
	}
	
	int x = tem->data;
	free(tem);
	tem1->next = NULL;
	return x;
}


void Radix_Sort(int arr[],int n){
	
	int max = max_count(arr,n);
	int max_digit = digit_count(max);
	struct node *radix[10];
	int i;
	for(i=0;i<10;i++)	radix[i] = NULL;
	
	int digit = 0;
	while(digit < max_digit){
		for(i=0;i<n;i++){
			int a = (int)(arr[i]/pow(10,digit))%10;
			Insert(&radix[a],arr[i]);
		}
		
		int x = 0;
		for(i=0;i<10;i++){
			while(radix[i]){
				arr[x++] = Delete(&radix[i]);
			}
		}
		
		digit++;
	}
	
}

int main()
{
	printf("Enter the size of array: ");
	int n;
	scanf("%d",&n);
	printf("Enter the elements to sort: ");
	int arr[n];
	int i;
	for(i=0;i<n;i++)	scanf("%d",&arr[i]);
	Radix_Sort(arr,n);
	for(i=0;i<n;i++)	printf("%d ",arr[i]);
	return 0;
}
