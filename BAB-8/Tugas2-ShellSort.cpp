#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAX 5
bool a=true, sudah;
char nama[MAX][40], temp[40];
int nip[MAX], jarak;
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
    cin >> nip[i];
    cin.get();}
  main();
}
void namaAscending(){
	jarak = MAX;
	while(jarak > 1){
		jarak = jarak / 2;
		sudah = false;
		while(!sudah){
			sudah = true;
			for(int j=0; j<MAX-jarak; j++){
				int i = j + jarak;
				if((strcmp(nama[j], nama[i]))>0){
					strcpy(temp, nama[j]);
					strcpy(nama[j], nama[i]);
					strcpy(nama[i], temp);
					sudah = false;
				}}}}
  cout << "Setelah diurutkan secara ASCENDING" << endl;
  displayNama();
}
void namaDescending(){
	jarak = MAX;
	while(jarak > 1){
		jarak = jarak / 2;
		sudah = false;
		while(!sudah){
			sudah = true;
			for(int j=0; j<MAX-jarak; j++){
				int i = j + jarak;
				if((strcmp(nama[j], nama[i]))<0){
					strcpy(temp, nama[i]);
					strcpy(nama[i], nama[j]);
					strcpy(nama[j], temp);
					sudah = false;
				}}}}
  cout << "Setelah diurutkan secara DESCENDING" << endl;
  displayNama();
}
void nipAscending(){
	jarak = MAX;
	while(jarak > 1){
		jarak = jarak / 2;
		sudah = false;
		while(!sudah){
			sudah = true;
			for(int j=0; j<MAX-jarak; j++){
				int i = j + jarak;
				if(nip[j] > nip[i]){
          int t = nip[j];
          nip[j]=nip[i];
          nip[i]=t;
					sudah = false;
				}}}}
  cout << "Setelah diurutkan secara ASCENDING" << endl;
  displayNIP();
}
void nipDescending(){
  jarak = MAX;
  while(jarak > 1){
    jarak = jarak / 2;
    sudah = false;
    while(!sudah){
      sudah = true;
      for(int j=0; j<MAX-jarak; j++){
        int i = j + jarak;
        if(nip[j] < nip[i]){
          int t = nip[i];
          nip[i]=nip[j];
          nip[j]=t;
          sudah = false;
        }}}}
  cout << "Setelah diurutkan secara DESCENDING" << endl;
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
