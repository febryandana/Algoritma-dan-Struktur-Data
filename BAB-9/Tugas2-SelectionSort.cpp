#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAX 5
bool a=true;
char nama[MAX][40], temp[40];
int nip[MAX];
int main();
void displayNama(){
  cout << endl;
  for(int i=0; i<MAX; i++){
    cout << i+1 << " " << nama[i] << endl;}
  cout << endl;
}
void displayNIP(){
  cout << endl;
  for(int i=0; i<MAX; i++){
    cout << i+1 << " " << nip[i] << endl;}
  cout << endl;
}
void inputNama(){
  for(int i=0; i<MAX; i++){
    cout << i+1 << ". Masukkan Nama : ";
    scanf("%[^\n]",nama[i]);
    cin.ignore();}
  main();
}
void inputNIP(){
  for(int i=0; i<MAX; i++){
    cout << i+1 << ". Masukkan NIP : ";
    cin >> nip[i];}
  main();
}
void namaAscending(){
  int i, j, k;
	for(i=0; i<MAX-1;i++){
		k = i;
		for (j=i+1; j<MAX; j++){
			if((strcmp(nama[k], nama[j]))>0){
				k = j;}}
    strcpy(temp, nama[i]);
    strcpy(nama[i], nama[k]);
    strcpy(nama[k], temp);}
  cout << "Urutan nama secara ASCENDING" << endl;
  displayNama();
}
void namaDescending(){
  int i, j, k;
	for(i=0; i<MAX-1;i++){
		k = i;
		for (j=i+1; j<MAX; j++){
			if((strcmp(nama[k], nama[j]))<0){
				k = j;}}
    strcpy(temp, nama[k]);
    strcpy(nama[k], nama[i]);
    strcpy(nama[i], temp);}
  cout << "Urutan nama secara DESCENDING" << endl;
  displayNama();
}
void nipAscending(){
  int i, j, k,tmp;
	for(i=0; i<MAX-1;i++){
		k = i;
		for (j=i+1; j<MAX; j++){
			if(nip[k] > nip[j]){
				k = j;}}
  	tmp = nip[i];
  	nip[i] = nip[k];
  	nip[k] = tmp;}
  cout << "Urutan NIP secara ASCENDING" << endl;
  displayNIP();
}
void nipDescending(){
  int i, j, k,tmp;
	for(i=0; i<MAX-1;i++){
		k = i;
		for (j=i+1; j<MAX; j++){
			if(nip[k] < nip[j]){
				k = j;}}
  	tmp = nip[k];
  	nip[k] = nip[i];
  	nip[i] = tmp;}
  cout << "Urutan NIP secara DESCENDING" << endl;
  displayNIP();
}
int main(){
  int pilih;
  do{
    cout << "\n===== MENU =====" << endl;
    cout << "1. Masukkan data Nama" << endl;
    cout << "2. Masukkan data NIP" << endl;
    cout << "3. Urutkan data secara ASCENDING berdasarkan NAMA" << endl;
    cout << "4. Urutkan data secara DESCENDING berdasarkan NAMA" << endl;
    cout << "5. Urutkan data secara ASCENDING berdasarkan NIP" << endl;
    cout << "6. Urutkan data secara DESCENDING berdasarkan NIP" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilihan : ";
    cin >> pilih;
    cin.get();
    switch (pilih) {
      case 1:inputNama();break;
      case 2:inputNIP();break;
      case 3:namaAscending();break;
      case 4:namaDescending();break;
      case 5:nipAscending();break;
      case 6:nipDescending();break;
      case 7:return 0;break;
      default: a = true;}
  }while(a=true);
}
