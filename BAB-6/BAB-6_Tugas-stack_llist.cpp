#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
  char data;
  struct node *next;
};
typedef struct node node;
node *top, *last=NULL;
int choice;
char item;
int count = 0;
int keluar = 0;
void push(char item){
    node *temp = new node;
    temp->data = item;
    if (top == NULL){
        top = last = temp;
    }else{
        last->next = temp;}
    last = temp;
    last->next = NULL;
    cout << "\n# PUSH : No urut/index : " << count << ", Push :" << item;
    count++;
}
void pop(){
    if (top==NULL)
    cout << "\n## Stack kosong";
    else{
        item = last->data;
        node *bantu1 = top;
        node *bantu2 = top->next;
        if(top==NULL){
            cout << "/nstack kosong" << endl;
        }else{
            while(bantu2->next != NULL){
                bantu1 = bantu2;
                bantu2 = bantu2->next;
            }
            bantu1->next = NULL;
            last = bantu1;
            delete bantu2;}
        --count;
        cout << "\n##POP hasil:" << item;
        cout << "\n##jumlah item dalam stack : " << count ;}
}
void printAll(){
    cout << "\n## Stack Size : " << count;
    node *temp=new node;
    temp=top;
    int i=count;
    while(temp != NULL){
        cout << "\n## No Urut/index : " << i << ", Value :" << temp->data;
        temp=temp->next;
        i--;}
}
void menu(){
    cout << "\nMasukkan operasi yang akan dilakukan (1:push, 2:pop, 3:print) : ";
    cin >> choice;
    switch (choice){
    case 1:{
        cout << "\nMasukkan huruf yang akan dipush : ";
        cin >> item;
        push(item);
        break;}
    case 2:pop();
    break;
    case 3:printAll();
    break;
    default:
        cout << "\n1:push, 2:pop, 3:print\n";
        keluar = 1;
        break;
    }
}
int main(){
    do{
        menu();
    }while (keluar == 0);
}

