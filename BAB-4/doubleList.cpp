#include <iostream>
using namespace std;

struct doubleList
{
    int data;

    doubleList *next;
    doubleList *prev;
};

struct doubleList *head,*tail;

void addAfter(int item){
    doubleList *newNode = (doubleList*) malloc(sizeof(doubleList));
    newNode->data = item;
    if(head==NULL){
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head->next;
        head->next = newNode;
        newNode->prev = head;
    }
    tail = newNode;
}

void addFirst(int item){
    doubleList *newNode = (doubleList*) malloc(sizeof(doubleList));
    newNode->data = item;
    if(head==NULL){
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}
void sisipSetelah(int item, int key){
    doubleList *newNode = (doubleList*) malloc(sizeof(doubleList));
    doubleList *bantu;
    newNode->data = item;
    bantu = head;
    if(head==NULL){
        cout<<"List kosong";
    } else {
        while(bantu!=NULL){
            if(bantu->data == key){
                newNode->next = bantu->next;
                bantu->next = newNode;
                newNode->prev = bantu;
                break;
            } else {
                bantu = bantu->next;
            }
        }
    }
}

void sisipSebelum(int item, int key){
    doubleList *newNode = (doubleList*) malloc(sizeof(doubleList));
    doubleList *bantu;
    newNode->data = item;
    bantu = head;
    if(head==NULL){
        cout<<"List kosong";
    } else if(bantu->data = key){
        newNode->next = bantu;
        bantu->prev = newNode;
        head = newNode;
    } else {
        while(bantu!=NULL){
            if(bantu->data == key){
                newNode->next = bantu;
                bantu->prev->next = newNode;
                break;
            } else {
                bantu = bantu->next;
            }
        }
    }
}

void palingAkhir(int item){
    doubleList *newNode = (doubleList*) malloc(sizeof(doubleList));
    doubleList *bantu;
    bantu = head;
    newNode->data = item;
    if(head==NULL){
        head = newNode;
        tail = newNode;
    } else {
        while(bantu->next!=NULL){
            bantu = bantu->next;
        }
        bantu->next = newNode;
        newNode->prev = bantu;
    }
    tail = bantu;
}
void hapusDiawal(){
    doubleList *bantu;
    bantu = head;
    if(head==NULL){
        cout<<"List kosong";
    } else {
        head = bantu->next;
        head->prev = NULL;
    }
    free(bantu);
}
void tampil(){
    doubleList *bantu;
    bantu = head;
    cout<<endl;
    if(head==NULL){
        cout<<"List kosong";
    } else {
        while(bantu!=NULL){
            cout<<bantu->data<<"->";
            bantu = bantu->next;
        }
    cout<<"NULL";
    }
}
int main(){
    head = tail = NULL;
    addFirst(4);
    addFirst(3);
    addAfter(2);
    addAfter(1);
    tampil();
    sisipSetelah(5,1);
    tampil();
    sisipSebelum(6,1);
    tampil();
    palingAkhir(7);
    tampil();
    hapusDiawal();
    tampil();
}
