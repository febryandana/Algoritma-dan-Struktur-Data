#include <iostream>
#include <string>
using namespace std;
struct Mahasiswa{
    string nama, nim;
    double ipk;
    Mahasiswa *next;
};
Mahasiswa *head, *tail = NULL;
void AddLast(){
    string nama2, nim2; double ipk2;
    Mahasiswa *newMhs = (Mahasiswa *)malloc(sizeof(Mahasiswa));
    cin.ignore();
    cout << "Masukkan Nama  : ";
    getline(cin,nama2);
    cout << "Masukkan NIM   : ";
    cin >> nim2;
    cout << "Masukkan IPK   : ";
    cin >> ipk2;
    newMhs->nama = nama2;
    newMhs->nim = nim2;
    newMhs->ipk = ipk2;
    if(head == NULL){
        cout << "List masih kosong" << endl;
        head = newMhs;}
    else{
        tail->next = newMhs;}
    tail = newMhs;
}
void AddFirst(){
    string nama1, nim1; double ipk1;
    Mahasiswa *newMhs = (Mahasiswa *)malloc(sizeof(Mahasiswa));
    cin.ignore();
    cout << "Masukkan Nama  : ";
    getline(cin,nama1);
    cout << "Masukkan NIM   : ";
    cin >> nim1;
    cout << "Masukkan IPK   : ";
    cin >> ipk1;
    newMhs->nama = nama1;
    newMhs->nim = nim1;
    newMhs->ipk = ipk1;
    if (head == NULL){
        cout << "List masih kosong" << endl;
        head = newMhs;
        tail = newMhs;}
    else{
        newMhs->next = head;}
    head = newMhs;
}
void ShowList(){
    Mahasiswa *tampil;
    tampil = head;
    if (head == NULL){
        cout << "List Kosong" << endl;}
    while (tampil != NULL){
        cout << "Nama   : " << tampil->nama << endl;
        cout << "NIM    : " << tampil->nim << endl;
        cout << "IPK    : " << tampil->ipk << endl;
        tampil = tampil->next;
        cout << endl;}
}
void InsertionSort() {
    Mahasiswa *temp = head;
    Mahasiswa *currNode = head->next;
    Mahasiswa *prevNode = head;
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    while (currNode != NULL) {
        if(prevNode->ipk <= currNode->ipk){
            currNode = currNode->next;
            prevNode = prevNode->next;
        }
        else{
                if(head->ipk > currNode->ipk){
                    prevNode->next = currNode->next;
                    currNode->next = head;
                    head = currNode;
                }else{
                    while(temp->next != NULL && temp->next->ipk < currNode->ipk){
                            temp = temp->next;
                    }
                    prevNode->next = currNode->next;
                    currNode->next = temp->next;
                    temp->next = currNode;
                }
        }
        currNode = prevNode->next;
    }
}

//void InsertionSort() {
//    Mahasiswa * p = head;
//    Mahasiswa * currentNode = head->next;
//    Mahasiswa * previousNode = head;
//    if (p == nullptr || p->next == nullptr) {
//        return;
//    }
//
//    while (currentNode != nullptr) {
//        if(previousNode->ipk<=currentNode->ipk){
//            currentNode = currentNode->next;
//            previousNode = previousNode->next;
//        }
//        else{
//            if (head->ipk > currentNode->ipk) {
//                previousNode->next = currentNode->next;
//                currentNode->next = head;
//                head = currentNode;
//            }else {
//                p = head;
//                while (p->next != NULL && p->next->ipk < currentNode->ipk) {
//                        p = p->next;
//                }
//                previousNode->next = currentNode->next;
//                currentNode->next = p->next;
//                p->next = currentNode;
//            }
//        }
//        currentNode = previousNode->next;
//    }
//}

int main(){
    int pilih, jmlh, i;
	do{
    cout << "===== PROGRAM PENDATAAN MAHASISWA =====" << endl;
    cout << "1. Masukkan data di awal" << endl;
    cout << "2. Masukkan data di akhir" << endl;
    cout << "Pilihan : ";
    cin >> pilih;
    switch(pilih){
    case 1:
        cout << "Banyak mahasiswa yang akan didata : ";
        cin >> jmlh;
        for(i=0; i<jmlh; i++){
            cout << "---------------------------------" << endl;
            cout << "Mahasiswa ke-" << i+1 << endl;
            AddFirst();}
        cout << endl << "Urutan data langsung : " << endl;
        ShowList();
        cout << "Data yang telah diurutkan sesuai IPK : " << endl;
        InsertionSort();
        ShowList();
        break;
    case 2:
        cout << "Banyak mahasiswa yang akan didata : ";
        cin >> jmlh;
        for(i=0; i<jmlh; i++){
            cout << "---------------------------------" << endl;
            cout << "Mahasiswa ke-" << i+1 << endl;
            AddLast();}
        cout << endl << "Urutan data langsung : " << endl;
        ShowList();
        cout << "Data yang telah diurutkan sesuai IPK : " << endl;
        InsertionSort();
        ShowList();
        break;
    default:
        system("clear||cls");
        cout << "Pilihan tidak ada, mohon ulangi" << endl;
    }
	}while(pilih >2);
    return 0;
}
