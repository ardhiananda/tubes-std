#ifndef HPEGAWAI_H_INCLUDED
#define HPEGAWAI_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stddef.h>
#include <stdio.h>
#include "cstdlib"
#include <conio.h>

// Ini buat Parent
#define firstP(X) X.firstP
#define infoP(X) X->infoP
#define nextP(X) X->nextP
#define child(X) X->child

// Ini buat Relasi
#define firstR(X) X.firstR
#define nextR(X) X->nextR
#define ayah(X) X->ayah
#define anak(X) X->anak

// Ini buat Child
#define firstC(X) X.firstC
#define infoC(X) X->infoC
#define nextC(X) X->nextC
#define nextCR(X) X->nextCR


using namespace std;


// Ini struct Pegawai
struct pegawai {
    int ID;
    string nama;
    string jabatan;
    double gaji;
    int jml_anak;
};

// Ini struct Anak
struct Anak {
    string nama;
    int umur;
    string ttl;
};

typedef pegawai infotypeP;
typedef Anak infotypeC;

typedef struct elmP *adrP;
typedef struct elmR *adrR;
typedef struct elmC *adrC;

struct elmP{
    infotypeP infoP;
    adrP nextP;
    adrC child;
};

struct elmR{
    adrP ayah;
    adrR nextR;
};

struct elmC{
    infotypeC infoC;
    adrC nextC;
    adrR nextCR;
};

struct ListP{
    adrP firstP;
};

struct ListR{
    adrR firstR;
};

struct ListC{
    adrC firstC;
};


void clrscr();
void createListP(ListP &L);
void createListR(ListR &L);
void createListC(ListC &L);

adrP alokasiP(string nama, int Id, string jabatan, double gaji, int jumAnak);
adrR alokasiR(adrP P, adrC C);
adrC alokasiC(string nama, int umur, int ttl);


void inFirstP(ListP &L, adrP P);
void inFirstR(ListR &L, adrR P);
void inFirstC(ListC &L, adrC P);

void inputAll(ListP &N,ListC &A, ListR &R);
void printAll(ListP S, ListR R, ListC C);
void tunjanganAnak(ListC C, ListP P, ListR R); // Print anak yang umurnya < 18 thn
void pegNonKB(ListP S);

// Extra method

void pegNonKB(ListP S); // Print pegawai yang anaknya > 3
void findAnak(ListP S, ListC C, ListR R, string nama_anak); // Print pegawai berdasarkan nama anak
void addAnak(ListP &S, ListC &C, ListR &R, int idpeg,string nama,int umur,int tggllahir); // Bapa buat anak

//void printP(ListP P);
//void printC(ListC P);


#endif // HPEGAWAI_H_INCLUDED
