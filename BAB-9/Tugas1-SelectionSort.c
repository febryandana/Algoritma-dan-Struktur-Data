#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int Data[MAX];
int count=1;
void Tukar (int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	count++;
}
void SelectionSort(){
	int i, j, k;
	for(i=0; i<MAX-1;i++){
		k = i;
		for (j=i+1; j<MAX; j++){
			if(Data[k] > Data[j]){
				k = j;}}
		Tukar(&Data[i], &Data[k]);
	}}
void main(){
	int i;
	srand(0);
	printf("=== DATA SEBELUM TERURUT ===");
	for(i=0; i<MAX; i++){
		Data[i] = (int) rand()/1000+1;
		printf("\nData ke %d : %d ", i, Data[i]);}
	SelectionSort();
	printf("\n\n=== DATA SETELAH TERURUT ===");
	for(i=0; i<MAX; i++){
		printf("\nData ke %d : %d ", i, Data[i]);}
	printf("\n\nBanyak Iterasi : %d", count);
}
