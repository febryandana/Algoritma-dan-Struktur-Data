#include <bits/stdc++.h>

using namespace std;
struct Node{
    int data;
    Node* next = NULL;
};


struct CSLL{
    Node* head = NULL;

    Node* findTail(){
        Node* bantu = head;
        while (bantu->next != head){
            bantu = bantu->next;
        }
        return bantu;
    }

    void addFirst(int data){
        Node* baru = new Node();
        baru->data = data;
        if (head == NULL){
            head = baru;
            baru->next = head;
            return;
        } else {
            Node* tail = findTail();
            baru->next = head;
            head = baru;
            tail->next = head;

        }
    }
    void addLast(int data){
        Node* baru = new Node();
        Node* tail = findTail();
        baru->data = data;
        if (head == NULL){
            head = baru;
            baru->next = head;
        } else {
            tail->next = baru;
            tail = baru;
            tail->next = head;
        }
    }
    void cetak(){
        Node* posisi = head;
        do {
            cout<<posisi->data<<"->";
            posisi = posisi->next;
        } while (posisi != head);
        cout << endl;
    }


};

int main(){
    CSLL csll;
    // csll.addFirst(1);
    // csll.addFirst(2);
    // csll.addFirst(3);
    // csll.addFirst(4);
    // csll.addFirst(5);
    // csll.cetak();
    csll.addLast(1);
    csll.addLast(2);
    csll.addLast(3);
    csll.addLast(4);
    csll.addLast(5);
    csll.cetak();


}
