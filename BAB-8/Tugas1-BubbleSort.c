#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int Data[MAX];
int count=1;
void Tukar (int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSort(){
	int i, j;
	for(i=1; i<MAX-1; i++){
		for(j=MAX-1; j>=i; j--){
			if(Data[j-1] > Data[j]){
				Tukar(&Data[j-1], &Data[j]);}
			count++;
		}}}
int main(){
	int i;
	srand(0);
	printf("===DATA SEBELUM TERURUT===\n");
	for(i=0; i<MAX; i++){
		Data[i] = (int) rand()/1000+1;
		printf("\nData ke %d : %d ", i, Data[i]);}
	BubbleSort();
	printf("\n\n===DATA SETELAH TERURUT===\n");
	for(i=0; i<MAX; i++){
		printf("\nData ke %d : %d ", i, Data[i]);}
	printf("\n\nIterasi : %d", count );
}
