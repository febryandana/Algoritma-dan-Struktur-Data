#include <iostream>
#include <string>
using namespace std;
struct Mahasiswa{
    string nama, nim;
    double ipk;
    int data;
    Mahasiswa *next, *prev;};
Mahasiswa *head, *tail;
void AddFirst(int count){
    string nama2, nim2; double ipk2;
    Mahasiswa *newMhs = (Mahasiswa *)malloc(sizeof(Mahasiswa));
        cout << "----------------------------" << endl;
        cout << "Mahasiswa ke-" << count << endl;
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
        newMhs->data = count;
        if (head == NULL){
            cout << "List masih kosong" << endl;
            head = newMhs;
            tail = newMhs;}
        else{
            newMhs->next = head;
            head->prev = newMhs;}
        head = newMhs;
}
void Ascending() {
    Mahasiswa *temp = head;
    Mahasiswa *currNode = head->next;
    Mahasiswa *prevNode = head;
    if (temp == NULL || temp->next == NULL) {
        return;}
    while (currNode != NULL) {
        if(prevNode->ipk <= currNode->ipk){
            currNode = currNode->next;
            prevNode = prevNode->next;}
        else{
                if(head->ipk > currNode->ipk){
                    prevNode->next = currNode->next;
                    currNode->next = head;
                    head = currNode;
                }else{
                    while(temp->next != NULL && temp->next->ipk < currNode->ipk){
                            temp = temp->next;}
                    prevNode->next = currNode->next;
                    currNode->next = temp->next;
                    temp->next = currNode;}}
        currNode = prevNode->next;}
}
void Descending() {
    Mahasiswa *temp = head;
    Mahasiswa *currNode = head->next;
    Mahasiswa *prevNode = head;
    if (temp == NULL || temp->next == NULL) {
        return;}
    while (currNode != NULL) {
        if(prevNode->ipk >= currNode->ipk){
            currNode = currNode->next;
            prevNode = prevNode->next;}
        else{
                if(head->ipk < currNode->ipk){
                    prevNode->next = currNode->next;
                    currNode->next = head;
                    head = currNode;
                }else{
                    while(temp->next != NULL && temp->next->ipk > currNode->ipk){
                            temp = temp->next;}
                    prevNode->next = currNode->next;
                    currNode->next = temp->next;
                    temp->next = currNode;}}
        currNode = prevNode->next;}
}
void hapusData(){
    double indeks;
    Mahasiswa *hapus, *bantu, *bantu2;
    hapus = head;
    cout << "Masukkan nilai IPK yang ingin dihapus : ";
    cin >> indeks;
    while(hapus->ipk != indeks){
        hapus = hapus->next;}
    if(hapus->ipk == indeks){
        bantu2 = hapus->next;
        bantu = hapus->prev;
        bantu->next = bantu2;
        bantu2->prev = bantu;
        cout << "Data terhapus" << endl;
        free(hapus);}
}
void ShowList(){
    Mahasiswa *bantu;
    bantu = head;
    cout<<endl;
    if(head==NULL){
        cout<<"List kosong";
    } else {
        while(bantu!=NULL){
            cout << "Nama  : " << bantu->nama << endl;
            cout << "NIM   : " << bantu->nim << endl;
            cout << "IPK   : " << bantu->ipk << endl << endl;
            bantu = bantu->next;}}
}
int main(void){
    int pilih, jmlh, i, a=1;
    do{
        cout << "===== PROGRAM PENDATAAN MAHASISWA =====" << endl;
        cout << "1. Masukkan data mahasiswa" << endl;
        cout << "2. Lihat pengurutan data ascending" << endl;
        cout << "3. Lihat pengurutan data descending" << endl;
        cout << "4. Hapus data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan : ";cin >> pilih;
        switch (pilih){
        case 1:
            cout << "Banyak mahasiswa yang akan didata : ";
            cin >> jmlh;
            for(i=1; i<=jmlh; i++){
                AddFirst(i);}
            cout << "----------------------------------------" << endl;
            cout << "Tampilan data" << endl;
            ShowList(); break;
        case 2:
            Ascending();
            cout << "----------------------------------------" << endl;
            cout << "Tampilan data setelah diurutkan secara Ascending" << endl;
            ShowList(); break;
        case 3:
            Descending();
            cout << "----------------------------------------" << endl;
            cout << "Tampilan data setelah diurutkan secara Descending" << endl;
            ShowList(); break;
        case 4:
            hapusData(); break;
        case 5:
            return 0; break;
        default:
            a=1;}
    }while(a==1);
}
