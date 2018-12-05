#include <iostream>
#include"hpegawai.h"
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <stddef.h>

using namespace std;

int main(){

    pegawai N;
    Anak A;
    ListP S;
    ListR R;
    ListC C;
    createListP(S);
    createListR(R);
    createListC(C);
    string namaanak;
    int idpeg;
    string nama;
    int umur;
    int tggallahir;


    int choose;
    do
    {
        clrscr();
        cout<<"------------------ Main Menu ------------------"<<endl;
        cout<<endl;
        cout<<"1. Input Pegawai"<<endl;
        cout<<"2. View all"<<endl;
        cout<<"3. Daftar anak yang mendapat tunjangan"<<endl;
        cout<<"4. Daftar Pegawai NON KB"<<endl;
        cout<<"5. Searching Orang Tua Anak"<<endl;
        cout<<"6. Add Anak"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<endl;
        cout<<"Masukkan pilihan : ";
        cin>>choose;

        if(choose == 1){
            inputAll(S,C,R);
            getch();
        } else if(choose == 2){
            printAll(S,R,C);
            getch();
        } else if ( choose == 3 ) {
            tunjanganAnak(C,S,R);
            getch();
        }else if ( choose == 4 ) {
            pegNonKB(S);
            getch();
        }else if ( choose == 5 ) {
            clrscr();
            cout<<"Cari Nama anak :" ;
            cin>>namaanak;
            findAnak(S,C,R,namaanak);
            getch();
        }else if ( choose == 6 ) {
            cout<<"ID pegawai :" ;
            cin>>idpeg;
            addAnak(S,C,R,idpeg,nama,umur,tggallahir);
            getch();
    }
    }
   while(choose != 0);
}


    //INPUT//
 //   inputAll(N,A);

    //VIEW ALL//
 //   printAll(S,R,C);

    //TUNJANGAN//
//    tunjanganAnak(C);

    //KB//
 //   pegNonKB(S);

    //FIND//
  //  findAnak(S,C,nama_anak);

    //ADD//
 //   addAnak(S,C,idpeg,x);*/






