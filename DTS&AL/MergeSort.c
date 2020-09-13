#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Merge(int *A,int *L ,int leftCount ,int *R, int rightCount){
	int i,j,k;
	//i: danh dau chi so mang trai
	//j: danh dau chi so mang phai
	//k: danh dau mang con da tron
	i = j = k = 0;
	while(i<leftCount && j<rightCount){
		//Neu phan tu mang con trai nho hon phan tu mang con phai, fill vao mang A (Tang k, tang i)
		if(L[i] <= R[j]) A[k++] = L[i++]; 
		//nguoc lai, fill phan tu mang phai vao A (Tang k, tang j)
		else A[k++] = R[j++]; 
	}
	//Vong lap thoat 1 trong 2 mang Right hoac Left se con phan tu
	while(i<leftCount) A[k++] = L[i++];
	while(j<rightCount) A[k++] = R[j++];
	
}
void MergeSort(int *A, int n){
	int i, mid, *L, *R;
	if(n<2) return; //Truong hop co so de dung (pause) de quy.
	mid = n/2; //
	
	L = (int *)malloc(mid*sizeof(int)); //Mang Left kich thuoc mid
	R = (int *)malloc((n-mid)*sizeof(int)); //Mang Right kich thuoc n-mid
	
	for(i=0; i<mid; i++) L[i] = A[i]; //Khoi tao mang Left
	for(i=mid; i<n; i++) R[i-mid] = A[i]; //Khoi tao mang Right
	
	MergeSort(L,mid); //De quy sort mang con Left
	MergeSort(R,n-mid); //De quy sort mang con Right
	Merge(A,L,mid,R,n-mid); //Hop nhat
	free(L);
	free(R);
}
int main(){
	int arr[] = {40,50,20,60,70,10,26,1,6,2,6,76,1,2,6,6,12,25,6,1,2,5,51,1}; 
	int i;
	int n = sizeof(arr)/sizeof(arr[0]);
	MergeSort(arr,n); 
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
return 0;
}

