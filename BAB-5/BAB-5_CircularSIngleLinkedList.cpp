#include <iostream>
using namespace std;

struct NodeCSLL {
	int data;
	NodeCSLL *setelah;
};
struct CircularSingleLinkedList {
	NodeCSLL *pAwal, *pAkhir;
	int jumlah;
CircularSingleLinkedList(){
	pAwal = NULL;
	pAkhir = NULL;
	jumlah = -1;
}
void sisipDataDiAwal(int data){
	NodeCSLL *pBaru = new NodeCSLL();
	pBaru->data = data;
	pBaru->setelah = pBaru;
	if (pAwal == NULL){
		pAwal = pBaru;
		pAkhir = pBaru;
		jumlah = 0;
	} else {
		pBaru->setelah = pAwal;
		pAkhir->setelah = pBaru;
		pAwal = pBaru;
		jumlah++;
	}
}
void sisipDataDiAkhir(int data){
	// lengkapi bagian ini
	NodeCSLL *pBaru = new NodeCSLL();
	pBaru->data = data;
	if(pAwal == NULL){
		pAwal = pAkhir = pBaru;
		jumlah = 0;
	} else {
		pBaru->setelah = pAwal;
		pAkhir->setelah = pBaru;
		pAkhir = pBaru;
		jumlah++;
	}
}
void hapusData(int dtHapus){
	if(pAwal != NULL) {
		NodeCSLL *pSbl, *pHapus;
		pSbl = NULL; pHapus = pAwal;
		bool ketemu = false;
		int i = 0;
		while(!ketemu && (i <= jumlah)){
			if (pHapus->data == dtHapus) {
				ketemu = true;
			}
			else {
				pSbl = pHapus;
				pHapus = pHapus->setelah;
			}
			i++;
		}
		if (ketemu){
			if(pSbl == NULL) {
				pAwal = pHapus->setelah;
				pAkhir->setelah = pAwal;
				delete pHapus;
			} else {
				if (pAkhir == pHapus) {
					pAkhir = pSbl;
				}
				pSbl->setelah = pHapus->setelah;
				delete pHapus;
			}
			jumlah--;
		}
	}
}
void hapusSatuDataDiAwal(){
	// lengkapi bagian ini
	if(pAwal == NULL){
		cout << "Tidak ada Data" << endl;
		return;
	} else {
		pAwal = pAwal->setelah;
		delete pAkhir->setelah;
		pAkhir->setelah = pAwal;
		jumlah--;
	}
}
void hapusSatuDataDiAkhir(){
	// lengkapi bagian ini
	NodeCSLL *bantu = new NodeCSLL();
	bantu = pAwal->setelah;
	if(pAwal == NULL){
		cout << "Tidak ada Data" << endl;
		return;
	}
	if(pAwal == pAkhir){
		delete pAkhir;
		pAwal = pAkhir = NULL;
		jumlah = -1;
	}
	while(bantu != pAkhir){
		bantu = bantu->setelah;
	}
	bantu->setelah = pAwal;
	delete pAkhir;
	pAkhir = bantu;
	jumlah--;
}
void cetak(string komentar){
	cout << komentar << endl;
	NodeCSLL *pCetak;
	pCetak = pAwal;
	int i = -1;
	while((i < jumlah) ){
		cout << pCetak->data << "->";
		pCetak = pCetak->setelah;
		i++;
	}
	cout << endl;
}
};
int main() {
		CircularSingleLinkedList *csll = new CircularSingleLinkedList();
		// csll->sisipDataDiAwal(10);
		// csll->sisipDataDiAwal(20);
		// csll->sisipDataDiAwal(30);
		// csll->sisipDataDiAwal(40);
		// csll->sisipDataDiAwal(50);
		// csll->sisipDataDiAwal(60);
		// csll->sisipDataDiAwal(70);
		// csll->cetak("csll Asal");
		// csll->hapusData(40);
		// csll->cetak("csll stl 8 dihapus");
		// csll->hapusData(70);
		// csll->cetak("csll stl 90 dihapus");

		// csll->sisipDataDiAkhir(10);
		// csll->sisipDataDiAkhir(20);
		// csll->sisipDataDiAkhir(30);
		// csll->sisipDataDiAkhir(40);
		// csll->sisipDataDiAkhir(50);
		// csll->sisipDataDiAkhir(60);
		// csll->sisipDataDiAkhir(70);
		// csll->cetak("csll data awal");
		// csll->hapusSatuDataDiAwal();
		// csll->cetak("csll hapus awal");
		// csll->hapusSatuDataDiAkhir();
		// csll->cetak("csll hapus akhir");
		// csll->hapusData(60);
		// csll->cetak("csll hapus data 40");
		return 0;
}
