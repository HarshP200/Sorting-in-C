#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void swap(int *x,int *y){
	int tem = *x;
	*x = *y;
	*y = tem;
}


void Bubble_Sort(int arr[],int n){
	int flag;
	int i;
	for(i=0;i<n-1;i++){
		flag = 0;
		int j;
		for(j=0;j<n-1-i;j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				flag++;
			}
		}
		if(flag == 0)	break;
	}
}



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


void Merge_Sort(int arr[],int n){
	int i,j;
	for(i=2;i<=n;i=i* 2){
		for(j=0; j+i-1 < n; j = j+i){
			Array_Merge(arr,j,(j+j+i-1)/2,j+i-1);
		}
	}

	if(i/2<n)	Array_Merge(arr,0,(i/2)-1,n-1);
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



int arr16[16], arr32[32], arr64[64], arr128[128], arr256[256], arr512[512], arr1024[1024], arr2048[2048];

void random(){
	int i;
	srand(time(0));
	for(i=0;i<16;i++){
		arr16[i] = rand();
	}
	
	srand(time(0));
	for(i=0;i<32;i++){
		arr32[i] = rand();
	}
	
	srand(time(0));
	for(i=0;i<64;i++){
		arr64[i] = rand();
	}
	
	srand(time(0));
	for(i=0;i<128;i++){
		arr128[i] = rand();
	}
	
	srand(time(0));
	for(i=0;i<256;i++){
		arr256[i] = rand();
	}
	
	srand(time(0));
	for(i=0;i<512;i++){
		arr512[i] = rand();
	}
	
	srand(time(0));
	for(i=0;i<1024;i++){
		arr1024[i] = rand();
	}
	
	srand(time(0));
	for(i=0;i<2048;i++){
		arr2048[i] = rand();
	}
}


void fun1(){
	
	printf("\nBubble Sort:\t\t");
	
	clock_t begin, end;
	double time_spent;
	
	begin = clock();
	
	Bubble_Sort(arr16, 16);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr32, 32);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr64, 64);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr128, 128);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr256, 256);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr512, 512);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr1024, 1024);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr2048, 2048);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	
	printf("\nBubble Sort(Sorted):\t");
	
	
	begin = clock();
	
	Bubble_Sort(arr16, 16);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr32, 32);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr64, 64);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr128, 128);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr256, 256);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr512, 512);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr1024, 1024);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Bubble_Sort(arr2048, 2048);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	printf("\n");
	
}

void fun2(){
	
	printf("\nInsertion Sort:\t\t");
	
	clock_t begin, end;
	double time_spent;
	
	begin = clock();
	
	Insertion_Sort(arr16, 16);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr32, 32);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr64, 64);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr128, 128);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr256, 256);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr512, 512);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr1024, 1024);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr2048, 2048);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	
	printf("\nInsertion Sort(Sorted):\t");
	
	
	begin = clock();
	
	Insertion_Sort(arr16, 16);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr32, 32);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr64, 64);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr128, 128);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr256, 256);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr512, 512);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr1024, 1024);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Insertion_Sort(arr2048, 2048);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	printf("\n");
	
}

void fun3(){
	
	printf("\nMerge Sort:\t\t");
	
	clock_t begin, end;
	double time_spent;
	
	begin = clock();
	
	Merge_Sort(arr16, 16);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr32, 32);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr64, 64);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr128, 128);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr256, 256);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr512, 512);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr1024, 1024);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr2048, 2048);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	
	printf("\nMerge Sort(Sorted):\t");
	
	
	begin = clock();
	
	Merge_Sort(arr16, 16);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr32, 32);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr64, 64);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr128, 128);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr256, 256);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr512, 512);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr1024, 1024);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Merge_Sort(arr2048, 2048);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	printf("\n");
	
}

void fun4(){
	
	printf("\nQuick Sort:\t\t");
	
	clock_t begin, end;
	double time_spent;
	
	begin = clock();
	
	Quick_Sort(arr16, 0, 15);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr32, 0, 31);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr64, 0, 63);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr128, 0, 127);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr256, 0, 255);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr512, 0, 511);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr1024, 0, 1023);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr2048, 0, 2047);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	
	printf("\nQuick Sort(Sorted):\t");
	
	
	begin = clock();
	
	Quick_Sort(arr16, 0, 15);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr32, 0, 31);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr64, 0, 63);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr128, 0, 127);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr256, 0, 255);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr512, 0, 511);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr1024, 0, 1023);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	begin = clock();
	
	Quick_Sort(arr2048, 0, 2047);
	sleep(1);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.4lf\t",time_spent-1);
	
	printf("\n");
	
}


int main(int argc, char** argv) {
	
	
	printf("1) Bubble Sort\n2) Insertion Sort\n3) Merge Sort\n4) Quick Sort\n"); 
	printf("\nChoice (Enter continuous number for multiple selection): ");
	
	int choice;
	scanf("%d",&choice);
	
	int ch[5] = {0};
	while(choice>0){
		if(choice%10 > 0 && choice%10 < 5){
			ch[choice%10] = 1;
		}
		choice = choice/10;
	}
	
	printf("\n\n\t\t\t16\t32\t64\t128\t256\t512\t1024\t2048\n");
	printf("---------------------------------------------------------------------------------------");
	
	if(ch[1] == 1)	fun1();
	if(ch[2] == 1)	fun2();
	if(ch[3] == 1)	fun3();
	if(ch[4] == 1)	fun4();
	
	
	
	return 0;
}

