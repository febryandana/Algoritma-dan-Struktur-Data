#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
    char data;
    struct node *next, *prev;
};
typedef struct node node;
node *head=NULL;
node *tail=NULL;
int choice;
char item;
int count = 0;
int keluar = 0;
void enqueue(char item){
    node *temp = new node;
    temp->data = item;
    if (head == NULL && tail == NULL){
        head = tail = temp;
    }else{
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        head = temp;}
    cout << "\n# Queue : No urut/index : " << count << ",   Value :" << item;
    count++;
}
void dequeue(){
    if (head == NULL)
        cout << "\n## Queue kosong";
    else{
        --count;
        char item = tail->data;
        node *temp = tail->prev;
        tail = temp;
        tail->next = NULL;
        delete tail->next;
        cout << "\n##Dequeue result:" << item;
        cout << "\n##jumlah item dalam queue : " << count ;}
}
void printAll(){
    cout << "\n## Queue Size : " << count;
    node *temp = head;
    int i = 0;
    while(temp != NULL){
        cout << "\n## No Urut/index : " << i++ << ", Value :" << temp->data;
        temp = temp->next;}
}
void menu(){
    cout << "\nMasukkan operasi yang akan dilakukan (1:enqueue, 2:dequeue, 3:print) : ";
    cin >> choice;
    switch (choice){
    case 1:{
        cout << "\nMasukkan huruf yang akan dimasukkan dalam queue : ";
        cin >> item;
        enqueue(item);
        break;}
    case 2:dequeue();
        break;
    case 3:printAll();
        break;
    default:
        cout << "\n1:enqueue, 2:dequeue, 3:print\n";
        keluar = 1;
        break;}
}
int main(){
    do{
        menu();
    }while (keluar == 0);
}
