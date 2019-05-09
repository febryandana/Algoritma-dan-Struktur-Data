#include <iostream>
using namespace std;

struct stack
{
    int data;
    stack *next;
};

stack *top;
int count = 0;

void push(int item){
    stack *temp = new stack;
    temp->data = item;
    temp->next = NULL;
    if(top==NULL){
        cout<<"Stack kosong"<<endl;
        top = temp;
        temp = NULL;
    } else {
        temp->next = top;
        top = temp;
    }
    cout<<"Data "<<item<<" telah ditambahkan"<<endl;
    count++;
}

void pop(){
    stack *temp = new stack;
    int item = top->data;
    temp = top;
    if(top==NULL){
        cout<<"Stack kosong"<<endl;
    } else {
        temp = top->next;
        top = temp;
    }
    cout<<"Data "<<item<<" telah dikeluarkan"<<endl;
    count--;
}

void printAll(){
    stack *temp = new stack;
    temp = top;
    while(temp!=NULL){
        cout<<"Data ke-"<<count<<" : "<<temp->data<<endl;
        temp = temp->next;
        count--;
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    pop();
    printAll();
}