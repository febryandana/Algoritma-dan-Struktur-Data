#include <iostream>
#include <cmath>
using namespace std;
struct Kompleks{
    int bil;
    char i;
};
Kompleks a,b,c,d,e;
void Inisialisasi(int w, int x, int y, int z){
    a.bil = w;
    b.bil = x;
    c.bil = y;
    d.bil = z;
    e.i = 'i';
    cout << endl << "INISIALISASI NILAI" << endl;
    cout << "Nilai a = " << a.bil << endl;
    cout << "Nilai b = " << b.bil << e.i << endl;
    cout << "Nilai c = " << c.bil << endl;
    cout << "Nilai d = " << d.bil << e.i << endl;
}
void Penambahan(){
    cout << (a.bil + c.bil) << " + " << (b.bil + d.bil) << e.i;}
void Pengurangan(){
    cout << (a.bil - c.bil) << " + " << (b.bil - d.bil) << e.i;}
void Perkalian(){
    int kali1 = (a.bil * c.bil) - (b.bil * d.bil);
    int kali2 = (a.bil * d.bil) + (b.bil * c.bil);
    cout << kali1 << " + " << kali2 << e.i;}
void Pembagian(){
    double bagi1, bagi2, bagi3, bagi4;
    bagi1 = (a.bil*c.bil) + (b.bil * d.bil);
    bagi2 = (pow(a.bil,2) + pow(b.bil,2));
    bagi3 = (b.bil * c.bil) - (a.bil * d.bil);
    bagi4 = (pow(c.bil,2) + pow(d.bil, 2));
    cout << (bagi1 / bagi2) << " + " << (bagi3 / bagi4) << e.i;}
int main(){
    int input_a,input_b,input_c,input_d;
    cout << "Masukkan nilai a = ";
    cin >> input_a;
    cout << "Masukkan nilai bi = ";
    cin >> input_b;
    cout << "Masukkan nilai c = ";
    cin >> input_c;
    cout << "Masukkan nilai di = ";
    cin >> input_d;
    Inisialisasi(input_a,input_b,input_c,input_d);
    cout << endl << endl;
    cout << "Operasi Penambahan : (a+bi)+(c+di) = (a+c)+(b+d)i" << endl;
    Penambahan();
    cout << endl << "Operasi Pengurangan : (a+bi)-(c+di) = (a-c)+(b-d)i" << endl;
    Pengurangan();
    cout << endl << "Operasi Perkalian : (a+bi)*(c+di) = (ac-bd)+(ad+bc)i" << endl;
    Perkalian();
    cout << endl << "Operasi Pembagian : (a+bi)/(c+di) = [(ac+bd)/(a2+b2)]+[(bc-ad)/(c2+d2)]i " << endl;
    Pembagian();
    cout << endl;
    return 0;
}
