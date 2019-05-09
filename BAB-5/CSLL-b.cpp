#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
};

struct CSLL{
    Node* head = NULL;
    Node* tail = NULL;
    void addFirst(int data){
        Node* baru = new Node();
        baru->data = data;
        if(head == NULL){
            head = tail = baru;
            tail->next = head;
        }else{
            baru->next = head;
            head = baru;
            tail->next = head;
        }
    }

    void addLast(int data){
        Node* baru = new Node();
        baru->data = data;
        if(head == NULL){
            head = tail = baru;
            tail->next = head;
        }else{
            tail->next = baru;
            tail = baru;
            tail->next = head;
        }
    }

    void cetak(){
        Node* posisi = head;
        do{
            cout << posisi->data << " -> " ;
            posisi = posisi->next;
        }while(posisi != head);
    }

};


int main(){
    CSLL csll;
        csll.addFirst(1);
        csll.addFirst(2);
        csll.addFirst(3);
        csll.addFirst(4);
        csll.cetak();
        cout << endl;
        // csll.addLast(1);
        // csll.addLast(2);
        // csll.addLast(3);
        // csll.addLast(4);
        // csll.cetak();
        return 0;
}
