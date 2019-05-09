#include <bits/stdc++.h>

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
        if (head == NULL){
            head = tail = baru;
            tail->next = head;
        } else {
            baru->next = head;
            head = baru;
            tail->next = head;
        }
    }
    void addLast(int data){
        Node* baru = new Node();
        baru->data = data;
        if (head == NULL){
            head = tail = baru;
            tail->next = head;
        } else {
            tail->next = baru;
            tail = baru;
            tail->next = head;
        }
    }
    void removeFirst(){
        if (head==NULL){
            return;
        }
        if (head == tail){
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        head = head->next;
        delete tail->next;
        tail->next = head;
    }
    void removeLast(){
        if (head==NULL){
            return;
        }
        if (head == tail){
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node* bantu = head;
        while (bantu->next != tail){
            bantu = bantu->next;
        }
        bantu->next = head;
        delete tail;
        tail = bantu;

    }
    void cetak(){
        Node* posisi = head;
        do {
            cout<<posisi->data<<"->";
            posisi = posisi->next;
        } while (posisi != head);
    }

};

int main(){
    CSLL csll;
    csll.addFirst(4);
    csll.addFirst(5);
    csll.addFirst(1);
    csll.addFirst(0);
    csll.addLast(7);
    csll.removeLast();
    csll.removeLast();
    csll.cetak();


}
