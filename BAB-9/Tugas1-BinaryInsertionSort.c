#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int Data[MAX];
int count=1;
void BinaryInsertSort(){
	int i, j, l, r, m, x;
	for (i=1; i<MAX; i++){
		x = Data[i];
		l = 0;
		r = i - 1;
		while(l <= r){
			m = (l + r) / 2;
			if(x < Data[m])
				r = m - 1;
			else
				l = m + 1;}
		for(j=i-1; j>=l; j--)
			Data[j+1] = Data[j];
		Data[l]=x;
		count++;
	}}
void main(){
	int i;
	srand(0);
	printf("=== DATA SEBELUM TERURUT ===");
	for(i=0; i<MAX; i++){
		Data[i] = (int) rand()/1000+1;
		printf("\nData ke %d : %d ", i, Data[i]);}
	BinaryInsertSort();
	printf("\n\n=== DATA SETELAH TERURUT ===");
	for(i=0; i<MAX; i++){
		printf("\nData ke %d : %d ", i, Data[i]);}
	printf("\n\nBanyak Iterasi : %d", count);
}
