#include<iostream>
#include <stdlib.h>
using namespace std;
class BinarySearchTree{
public:
    int size;
    int *array;
    BinarySearchTree(int size) {
        this->size = extendSize(size);
        //this->size=size;
        this->array = new int[this->size];
        for(int x = 0; x < this->size; x++){
            array[x] = NULL;}
    }
    int extendSize(int x) {
        int value = 0;
        for(int y = 0; y < x + 1; y++) {
            value = (2 * value) + 2;}
        return value;
    }
    void insertElement(int x){
        int index = 0;
        cout << x << ", ";
        while(true) {
            if(array[index] == NULL){
                array[index] = x;
                break;
            }else if(array[index] <= x) {
                if(array[index] == x){
                    cout << "ERROR!-- Repeating element" << endl;
                    break;
                }else
                index = (2 * index + 2);
            }else if(array[index] >= x) {
                 if(array[index] == x){
                    cout << "ERROR!-- Repeating element" << endl;
                    break;
                }else
                index = (2 * index + 1);
    }}}
    void inOrder(int index){
        if(array[index] != NULL) {
            inOrder(2 * index + 1);
            cout << array[index] << ", ";
            inOrder(2 * index + 2);
    }}
    void preOrder(int index){
        if(array[index] != NULL) {
            cout << array[index] << ", ";
            preOrder(2 * index + 1);
            preOrder(2 * index + 2);
    }}
    void postOrder(int index){
        if(array[index] != NULL){
            postOrder(2 * index + 1);
            postOrder(2 * index + 2);
            cout << array[index] << ", ";
    }}
};
int main(){
  srand(10);
  BinarySearchTree bst(10);
  cout << "Tree : " << endl;
  for(int i=0; i<10; i++){
    int x = rand() % 100;
    bst.insertElement(x);}
  cout << endl << endl << "Traversal/Kunjungan InOrder : " << endl;
  bst.inOrder(0);
  cout << endl << endl << "Traversal/Kunjungan PreOrder : " << endl;
  bst.preOrder(0);
  cout << endl << endl << "Traversal/Kunjungan PostOrder : " << endl;
  bst.postOrder(0);
}
