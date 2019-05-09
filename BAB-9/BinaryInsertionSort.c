#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int Data[MAX];
// Fungsi pengurutan penyisipan biner
void BinaryInsertSort()
{
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
				l = m + 1;
		}
		for(j=i-1; j>=l; j--)
			Data[j+1] = Data[j];
		Data[l]=x;
	}
}
void main()
{
	int i;
	srand(0);

	// Membangkitkan bilangan acak
	printf("DATA SEBELUM TERURUT");
	for(i=0; i<MAX; i++)
	{
		Data[i] = (int) rand()/1000+1;
		printf("\nData ke %d : %d ", i, Data[i]);
	}

	BinaryInsertSort();
	// Data setelah terurut
	printf("\nDATA SETELAH TERURUT");
	for(i=0; i<MAX; i++)
	{
	printf("\nData ke %d : %d ", i, Data[i]);
	}
}
