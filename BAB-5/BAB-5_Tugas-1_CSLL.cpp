#include <iostream>
using namespace std;
struct NodeCSLL {
	int data;
	NodeCSLL *setelah;
};
struct CircularSingleLinkedList {
	NodeCSLL *pAwal, *pAkhir;
CircularSingleLinkedList(){
	pAwal = NULL;
	pAkhir = NULL;
}
void sisipDataDiAwal(int data){
	NodeCSLL *pBaru = new NodeCSLL();
	pBaru->data = data;
	pBaru->setelah = pBaru;
	if (pAwal == NULL){
		pAwal = pBaru;
		pAkhir = pBaru;
	} else {
		pBaru->setelah = pAwal;
		pAkhir->setelah = pBaru;
		pAwal = pBaru;
	}
}
void sisipDataDiAkhir(int data){
	// lengkapi bagian ini
}
void hapusData(int dtHapus){
    NodeCSLL *pSbl, *pHapus;
	pSbl = NULL;
    pHapus = pAwal;
    if(pAwal == NULL) {
        cout << "Tidak Ada Data" << endl;
        return;
    }
    while(pHapus->data != dtHapus){
        pSbl = pHapus;
		pHapus = pHapus->setelah;
	}
	if (pHapus->data == dtHapus){
        if(pSbl == NULL) {
			pAwal = pHapus->setelah;
			pAkhir->setelah = pAwal;
		} else if(pHapus == pAkhir){
            pAkhir = pSbl;
            pAkhir->setelah = pAwal;
        } else{
            pSbl->setelah = pHapus->setelah;
        }
        delete pHapus;
	}
}
void hapusSatuDataDiAwal(){
	// lengkapi bagian ini
}
void hapusSatuDataDiAkhir(){
	// lengkapi bagian ini
}
void cetak(string komentar){
	cout << komentar << endl;
	NodeCSLL *pCetak;
	pCetak = pAwal;
        do{
            cout << pCetak->data << "->";
            pCetak = pCetak->setelah;
        }while(pCetak != pAwal);
    	cout << endl;
}
};
int main() {
		CircularSingleLinkedList *csll = new CircularSingleLinkedList();
		csll->sisipDataDiAwal(50);
		csll->sisipDataDiAwal(60);
		csll->sisipDataDiAwal(70);
		csll->sisipDataDiAwal(8);
		csll->sisipDataDiAwal(9);
		csll->sisipDataDiAwal(90);
		csll->sisipDataDiAwal(19);
		csll->cetak("csll Asal");
		csll->hapusData(8);
		csll->cetak("csll stl 8 dihapus");
		csll->hapusData(90);
		csll->cetak("csll stl 90 dihapus");

}

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
// csll->cetak("csll hapus data 60");
