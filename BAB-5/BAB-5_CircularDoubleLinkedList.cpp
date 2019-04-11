#include <iostream>
using namespace std;
struct NodeCDLL {
	int data;
	NodeCDLL *sebelum;
	NodeCDLL *setelah;
};
struct CircularDoubleLinkedList {
	NodeCDLL *pAwal, *pAkhir;
	int jumlah;
	CircularDoubleLinkedList(){
		pAwal = NULL;
		pAkhir = NULL;
		jumlah = -1;
	}
	void sisipDataDiAwal(int data){
		NodeCDLL *pBaru = new NodeCDLL();
		pBaru->data = data;
		pBaru->sebelum = pBaru;
		pBaru->setelah = pBaru;
		if (pAwal == NULL){
			pAwal = pBaru;
			pAkhir = pBaru;
			jumlah = 0;
		} else {
			pBaru->sebelum = pAkhir;
			pBaru->setelah = pAwal;
			pAwal->sebelum = pBaru;
			pAkhir->setelah = pBaru;
			pAwal = pBaru;
			jumlah++;
		}
	}
	void sisipDataDiAkhir(int data){
		// lengkapi bagian ini
        NodeCDLL *pBaru = new NodeCDLL();
        pBaru->data = data;
        if(pAwal == NULL){
            pAwal = pAkhir = pBaru;
            jumlah = 0;
        } else {
            pBaru->setelah = pAwal;
            pBaru->sebelum = pAkhir;
            pAkhir->setelah = pBaru;
            pAwal->sebelum = pBaru;
            pAkhir = pBaru;
            jumlah++;
        }
	}
	void hapusData(int dtHapus){
		// lengkapi bagian ini
		if(pAwal != NULL) {
			NodeCDLL *pSbl, *pStlh, *pHapus;
			pHapus = pAwal;
			pSbl = pHapus->sebelum;
			pStlh = pHapus->setelah;
			bool ketemu = false;
			int i = 0;
			while(!ketemu && (i <= jumlah)){
				if (pHapus->data == dtHapus) {
					ketemu = true;
				}
				else {
					pSbl = pHapus;
					pHapus = pStlh;
					pStlh = pStlh->setelah;
				}
				i++;
			}
			if(ketemu){
				if(pHapus == pAwal) {
					pAwal = pStlh;
					pAkhir->setelah = pAwal;
					pAwal->sebelum = pAkhir;
					delete pHapus;
				} else {
					if (pAkhir == pHapus) {
						pAkhir = pSbl;
					}
					pSbl->setelah = pStlh;
					pStlh->sebelum = pSbl;
					delete pHapus;
				}
				jumlah--;
			}
		}
	}
	void cetak(string komentar){
		cout << komentar << endl;
		NodeCDLL *pCetak;
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
    CircularDoubleLinkedList *cdll = new CircularDoubleLinkedList();
    // cdll->sisipDataDiAwal(70);
    // cdll->sisipDataDiAwal(60);
    // cdll->sisipDataDiAwal(50);
    // cdll->sisipDataDiAwal(8);
    // cdll->sisipDataDiAwal(9);
    // cdll->sisipDataDiAwal(19);
    // cdll->sisipDataDiAwal(90);
    // cdll->cetak("cdll Asal");

    cdll->sisipDataDiAwal(1);
    cdll->sisipDataDiAwal(2);
    cdll->sisipDataDiAwal(3);
    cdll->sisipDataDiAwal(4);
    cdll->sisipDataDiAwal(5);
    cdll->cetak("cdll Awal");
    // cdll->sisipDataDiAkhir(1);
    // cdll->sisipDataDiAkhir(2);
    // cdll->sisipDataDiAkhir(3);
    // cdll->sisipDataDiAkhir(4);
    // cdll->sisipDataDiAkhir(5);
    // cdll->cetak("cdll Akhir");
	cdll->hapusData(3);
	cdll->cetak("hapus data 3");
	cdll->hapusData(1);
	cdll->cetak("hapus data 1");
	cdll->hapusData(5);
	cdll->cetak("hapus data 5");
}
