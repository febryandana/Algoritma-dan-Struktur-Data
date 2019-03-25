#include <iostream>
using namespace std;
struct Polinom{
    int bil, pow;
};
Polinom p1[5], p2[6], p3[2];
Polinom tambah[8], kurang[8], kali[10], turun[5];
int i=0, j=0, k=0;
void Fungsi_Pol1(){
    int bil_pol1[5] = {6,8,5,1,15};
    int pow_pol1[4] = {8,7,5,3};
    for(int a=0; a < 5; a++){
        for(int b=0; b<4; b++){
            p1[a].bil = bil_pol1[a];
            p1[b].pow = pow_pol1[b];}}
}
void Fungsi_Pol2(){
    int bil_pol2[6] = {3,4,3,2,2,10};
    int pow_pol2[5] = {9,7,4,3,2};
    for(int a=0; a < 6; a++){
        for(int b=0; b<5; b++){
            p2[a].bil = bil_pol2[a];
            p2[b].pow = pow_pol2[b];}}
}
void Fungsi_Pol3(){
    int bil_pol3[2] = {1,5};
    int pow_pol3[1] = {2};
    for(int a=0; a < 2; a++){
        for(int b=0; b<1; b++){
            p3[a].bil = bil_pol3[a];
            p3[b].pow = pow_pol3[b];}}
}
void penjumlahan(){
    for(int a=0; a<5; a++){
        for(int b=0; b<6; b++){
            if(p1[a].pow == p2[b].pow){
                tambah[i].bil = p1[a].bil + p2[b].bil;
                tambah[i].pow = p1[a].pow;
                i++;}}}
    for(int a=0; a<5; a++){
        if(p1[a].pow != tambah[0].pow){
            if(p1[a].pow != tambah[1].pow){
                if(p1[a].pow != tambah[2].pow){
                    tambah[i].bil = p1[a].bil;
                    tambah[i].pow = p1[a].pow;
                    i++;}}}}
    for(int a=0; a<6; a++){
        if(p2[a].pow != tambah[0].pow){
            if(p2[a].pow != tambah[1].pow){
                if(p2[a].pow != tambah[2].pow){
                    tambah[i].bil = p2[a].bil;
                    tambah[i].pow = p2[a].pow;
                    i++;}}}}
    for(i=0; i < 8; i++){
        cout << tambah[i].bil << "x" << tambah[i].pow << " + ";}
}
void pengurangan(){
    for(int a=0; a<5; a++){
        for(int b=0; b<6; b++){
            if(p1[a].pow == p2[b].pow){
                kurang[j].bil = p1[a].bil - p2[b].bil;
                kurang[j].pow = p1[a].pow;
                j++;}}}
    for(int a=0; a<5; a++){
        if(p1[a].pow != kurang[0].pow){
            if(p1[a].pow != kurang[1].pow){
                if(p1[a].pow != kurang[2].pow){
                    kurang[j].bil = p1[a].bil;
                    kurang[j].pow = p1[a].pow;
                    j++;}}}}
    for(int a=0; a<6; a++){
        if(p2[a].pow != kurang[0].pow){
            if(p2[a].pow != kurang[1].pow){
                if(p2[a].pow != kurang[2].pow){
                    kurang[j].bil = p2[a].bil;
                    kurang[j].pow = p2[a].pow;
                    j++;}}}}
    for(j=0; j<8; j++){
        cout << kurang[j].bil << "x" << kurang[j].pow << " + ";}
}
void perkalian(){
    for(int a=0; a<5; a++){
        for(int b=0; b<2; b++){
            kali[k].bil = p1[a].bil * p3[b].bil;
            kali[k].pow = p1[a].pow + p3[b].pow;
            k++;}}
    for(k=0; k < 10; k++){
        cout << kali[k].bil << "x" << kali[k].pow << " + ";}
}
void turunan(){
    for(int a=0; a<5; a++){
        if(p2[a].pow == 0){
            break;}
        else{
            turun[a].bil = p2[a].pow * p2[a].bil;
            turun[a].pow = p2[a].pow - 1;}}
    for(int a=0; a<5; a++){
        cout << turun[a].bil << "x" << turun[a].pow << " + ";}
}
int main(){
    Fungsi_Pol1();
    Fungsi_Pol2();
    Fungsi_Pol3();
    cout << "Aritmatika Polinom" << endl;
    cout << "P1 = 6x8 + 8x7 + 5x5+ x3 + 15" << endl;
    cout << "P2 = 3x9 + 4x7 + 3x4 + 2x3 + 2x2 + 10" << endl;
    cout << "P3 = x2 + 5" << endl;
    cout << "========================================" << endl << endl;
    cout << "Penambahan (P1 + P2)" << endl;
    penjumlahan();
    cout << endl;
    cout << "Pengurangan (P1 - P2)" << endl;
    pengurangan();
    cout << endl;
    cout << "Perkalian (P1 * P3)" << endl;
    perkalian();
    cout << endl;
    cout << "Turunan (P2')" << endl;
    turunan();
    cout << endl;
    return 0;
}








