#include <iostream>
using namespace std;
struct NodeCDLL {
	int data;
	NodeCDLL *sebelum;
	NodeCDLL *setelah;
};
struct CircularDoubleLinkedList {
	NodeCDLL *pAwal;
	CircularDoubleLinkedList(){
		pAwal = NULL;
	}
	void sisipDataDiAwal(int data){
		NodeCDLL *pBaru = new NodeCDLL();
		pBaru->data = data;
		pBaru->sebelum = pBaru;
		pBaru->setelah = pBaru;
		if (pAwal == NULL){
			pAwal = pBaru;
		} else {
			NodeCDLL *last = pAwal->sebelum;
			pBaru->setelah = pAwal;
			pBaru->sebelum = last;
			pAwal->sebelum = pBaru;
			last->setelah = pBaru;
			pAwal = pBaru;
		}
	}
	void sisipDataDiAkhir(int data){
        // lengkapi bagian ini
	}
	void hapusData(int dtHapus){
        // lengkapi bagian ini
	}
	void cetak(string komentar){
		cout << komentar << endl;
		NodeCDLL *pCetak;
		pCetak = pAwal;
        do{
            cout << pCetak->data << "->";
            pCetak = pCetak->setelah;
        }while(pCetak != pAwal);
    	cout << endl;
	}
};
int main() {
    CircularDoubleLinkedList *cdll = new CircularDoubleLinkedList();
    cdll->sisipDataDiAwal(70);
    cdll->sisipDataDiAwal(60);
    cdll->sisipDataDiAwal(50);
    cdll->sisipDataDiAwal(8);
    cdll->sisipDataDiAwal(9);
    cdll->sisipDataDiAwal(19);
    cdll->sisipDataDiAwal(90);
    cdll->cetak("cdll Asal");
}

    // cdll->sisipDataDiAwal(1);
    // cdll->sisipDataDiAwal(2);
    // cdll->sisipDataDiAwal(3);
    // cdll->sisipDataDiAwal(4);
    // cdll->sisipDataDiAwal(5);
    // cdll->cetak("cdll Awal");
    // // cdll->sisipDataDiAkhir(1);
    // // cdll->sisipDataDiAkhir(2);
    // // cdll->sisipDataDiAkhir(3);
    // // cdll->sisipDataDiAkhir(4);
    // // cdll->sisipDataDiAkhir(5);
    // // cdll->cetak("cdll Akhir");
	// cdll->hapusData(3);
	// cdll->cetak("hapus data 3");
	// cdll->hapusData(1);
	// cdll->cetak("hapus data 1");
	// cdll->hapusData(5);
	// cdll->cetak("hapus data 5");
