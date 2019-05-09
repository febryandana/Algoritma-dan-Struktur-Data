#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int a, i=5, c, d, j, b[5], k, m;
char nm[5][20], temp[40];

void UrutNip(){
	for(a = 0; a < i; a++){
        cout << "Masukkan Nip Anda " << "[" << a+1 << "] : ";
		cin >> b[a];
    }
    for(a = 0; a < i - 1; a++){
        for(d = a+1; d < i; d++){
        	c=a;
            if(b[c] < b[d]){
                c=d;
            }
        j = b[c];
        b[c] = b[a];
        b[a] = j;
    	}
	}
}

void UrutNama(){
    for (i = 1; i <= 5; i++){
		cout << "Masukkan Nama Anda " << "[" << i << "]" << " : ";
		gets(nm[i]);
    if (i > 1){
			for(j = 1; j <= (i - 1); j++){
				a = (strcmp(nm[i], nm[j]));
				if (a <= 0){
					strcpy (temp, nm[i]);
          for(k = (i - 1); k >= j; k--){
						m = (k + 1);
            strcpy(nm[m], nm[k]);
          }
          strcpy (nm[j], temp);
        }
			}
		}
	}
}
void display(){
	cout<<"Nama yang sudah terurut : " << endl;
    for(i = 5; i >= 1; i--){
		cout << endl << nm[i];
	}
	cout << endl;
	cout << "Nip yang sudah terurut : " << endl;
    for(a = 0; a < i; a++){
        cout << b[a] << endl;
    }
}
int main(){
	cout << "========PENGURUTAN DESCENDING========" << endl;
	UrutNama();
	//UrutNip();
	display();
}
