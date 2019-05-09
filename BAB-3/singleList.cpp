/*
 * File: singleList.cpp
 * File Created: Thursday, 21st February 2019 15:05:51 pm
 * Author: jenrinaldo (jenrinaldo@gmail.com)
 */

#include <iostream>
using namespace std;

struct singleList
{
    int data;
    singleList *next;
};

singleList *head, *tail = NULL;

void tambahAwal(int item)
{
    singleList *newNode = (singleList *)malloc(sizeof(singleList));
    newNode->data = item;
    if (head == NULL)
    {
        cout << "List masih kosong" << endl;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
    }
    head = newNode;
}

void tambahAkhir(int item)
{
    singleList *newNode = (singleList *)malloc(sizeof(singleList));
    newNode->data = item;
    if (head == NULL)
    {
        cout << "List masih kosong" << endl;
        head = newNode;
    }
    else
    {
        tail->next = newNode;
    }
    tail = newNode;
}
void tambahSetelah(int item, int indeks)
{
    singleList *newNode = (singleList *)malloc(sizeof(singleList));
    singleList *bantu;
    newNode->data = item;
    bantu = head;
    if (head == NULL)
    {
        cout << "List masih kosong" << endl;
        head = newNode;
    }
    else
    {
        while (bantu != NULL)
        {
            if (bantu->data == indeks)
            {
                newNode->next = bantu->next;
                bantu->next = newNode;
                break;
            }
            else
            {
                bantu = bantu->next;
            }
        }
    }
}

void tambahSebelum(int item, int indeks)
{
    singleList *newNode = (singleList *)malloc(sizeof(singleList));
    singleList *bantu, *sebelum;
    newNode->data = item;
    bantu = head->next;
    sebelum = head;
    if (head == NULL)
    {
        cout << "List masih kosong" << endl;
        head = newNode;
    }
    else
    {
        while (bantu != NULL)
        {
            if (bantu->data == indeks)
            {
                newNode->next = bantu;
                sebelum->next = newNode;
                break;
            }
            else
            {
                bantu = bantu->next;
                sebelum = sebelum->next;
            }
        }
    }
}

void cari(int item)
{
    singleList *bantu, *lokasi;
    bantu = head;
    while (bantu != NULL)
    {
        if (bantu->data == item)
        {
            lokasi = bantu;
            break;
        }
        else
        {
            bantu = bantu->next;
        }
    }
    if (lokasi != NULL)
    {
        cout << lokasi<<endl;
    }
    else
    {
        cout << "Data tidak ditemukan"<<endl;
    }
}

void tampil()
{
    singleList *bantu;
    bantu = head;
    if (head == NULL)
    {
        cout << "List Kosong" << endl;
    }
    while (bantu != NULL)
    {
        cout << bantu->data << "->";
        bantu = bantu->next;
    }
    cout << endl;
}
void hapusAwal()
{
    singleList *bantu;
    bantu = head;
    if (head == NULL)
    {
        cout << "List Kosong" << endl;
    }
    else
    {
        head = bantu->next;
    }
    free(bantu);
}
void hapusAkhir()
{
    singleList *bantu, *ptrBantu;
    bantu = head;
    ptrBantu = head->next;
    if (head == NULL)
    {
        cout << "List Kosong" << endl;
    }
    else
    {
        while (ptrBantu->next != NULL)
        {
            bantu = ptrBantu;
            ptrBantu = ptrBantu->next;
        }
        bantu->next = NULL;
        tail = bantu;
    }
    free(ptrBantu);
}

void hapusPada(int item)
{
    singleList *bantu, *sblmHapus;
    bantu = head;
    if (bantu->data == item)
    {
        head = bantu->next;
        free(bantu);
    }
    else
    {
        while (bantu != NULL)
        {
            if (bantu->data == item)
            {
                sblmHapus->next = bantu->next;
                free(bantu);
                break;
            }
            else
            {
                sblmHapus = bantu;
                bantu = bantu->next;
            }
        }
    }
}


int main()
{
    cout<<"List Awal"<<endl;
    tambahAwal(1);
    tambahAwal(2);
    tampil();
    cout<<"Tambah data diakhir"<<endl;
    tambahAkhir(3);
    tampil();
    cout<<"Tambah data diawal"<<endl;
    tambahAwal(4);
    tampil();
    cout<<"Alamat data 2 pada list"<<endl;
    cari(2);
    tampil();
    cout<<"Tambah data 5 sebelum data 3"<<endl;
    tambahSebelum(5, 3);
    tampil();
    cout<<"Tambah data 10 setelah data 3"<<endl;
    tambahSetelah(10, 3);
    tampil();
    cout<<"Hapus data 1"<<endl;
    hapusPada(1);
    tampil();
    cout<<"Hapus data diAwal"<<endl;
    hapusAwal();
    tampil();
    cout<<"Hapus data diAkhir"<<endl;
    hapusAkhir();
    tampil();
}
