#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *next;
};


void Insert(struct node **a){
	struct node *tem = (struct node *) malloc (sizeof(struct node));
	tem->next = NULL;
	if(*a == NULL){
		*a = tem;
		return;
	}
	
	struct node *a1 = *a;
	while(a1->next != NULL){
		a1 = a1->next;
	}
	a1->next = tem;
}


void Delete(struct node **a){
	struct node *tem = *a;
	if(tem->next == NULL){
		*a = NULL;
		free(tem);
		return;
	}
	
	struct node *tem1;
	while(tem->next){
		tem1 = tem;
		tem = tem->next;
	}
	
	free(tem);
	tem1->next = NULL;
	return;
}


void Bin_Sort(int arr[], int n){
	int i, max = arr[0];
	for(i=0;i<n;i++){
		if(max<arr[i])	max = arr[i];
	}
	
	struct node *bin[max + 1];
	for(i=0;i<max+1;i++)	bin[i] = NULL;
	
	for(i=0;i<n;i++){
		Insert(&bin[arr[i]]);
	}
	int x = 0;
	for(i=0;i<max+1;i++){
		while(bin[i]){
			Delete(&bin[i]);
			arr[x++] = i;
		}
	}
	
	
}

int main(){
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	int i, arr[n];
	for(i=0;i<n;i++)	scanf("%d",&arr[i]);
	
	Bin_Sort(arr,n);
	
	for(i=0;i<n;i++)	printf("%d ",arr[i]);	
	
	return 0;
}
