#include "hpegawai.h"

#define WINDOWS 1

void clrscr(){
#ifdef WINDOWS
    system("cls");
#endif // WINDOWS
#ifdef LINUX
    system("clear");
#endif // LINUX
}
/*    pegawai N;
    Anak A;
    ListP S;
    ListR R;
    ListC C;
    infotypeP y;
    infotypeC x;*/

void createListP(ListP &L){
    firstP(L) = NULL;
}
void createListR(ListR &L) {
    firstR(L) = NULL;
}
void createListC(ListC &L) {
    firstC(L) = NULL;
}

adrP alokasiP(string nama, int Id, string jabatan, double gaji, int jumAnak) {

    adrP P;
    P = new elmP;
    infoP(P).nama = nama;
    infoP(P).ID = Id;
    infoP(P).jml_anak = jumAnak;
    infoP(P).gaji = gaji;
    infoP(P).jabatan = jabatan;
    nextP(P) = NULL;
    return P;
}

adrR alokasiR() {

    adrR R = new elmR;
    ayah(R) = NULL;
    nextR(R) = NULL;
    return R;
}
adrC alokasiC(string nama, int umur, int ttl) {

    adrC P;
    P = new elmC;
    infoC(P).nama = nama;
    infoC(P).umur = umur;
    infoC(P).ttl = ttl;
    nextC(P) = NULL;
    nextCR(P) = NULL;
    return P;

}


void inFirstP(ListP &L, adrP P){
    if (firstP(L)==NULL) {
        firstP(L) = P;
    } else {
        nextP(P) = firstP(L);
        firstP(L) = P;
    }
}

void inFirstR(ListR &L, adrR P){
    if (firstR(L)==NULL) {
        firstR(L) = P;
    } else {
        nextR(P) = firstR(L);
        firstR(L) = P;
    }
}

void inFirstC(ListC &L, adrC P){

    if (firstC(L)==NULL) {
        firstC(L) = P;
    } else {
        nextC(P) = firstC(L);
        firstC(L) = P;
    }

}

void inputAll(ListP &N, ListC &A, ListR &R){
    adrP P;
    adrC C;
    string Nm,J;
    int I,JA;
    double G;
    string nama;
    int umur, ttl;

    clrscr();
    cout<<"-----------------------------------------------"<<endl;
    cout<<"               INPUT Pegawai                   "<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<endl;
    cout << "Nama Pegawai             : " ;
    cin >> Nm;
    cout << "ID Pegawai               : " ;
    cin >> I;
    cout << "jabatan                  : " ;
    cin >> J;
    cout << "gaji                     : " ;
    cin >> G;
    cout<<"jumlah anak pegawai        : " ;
    cin >> JA;
    P = alokasiP(Nm,I,J,G,JA);
    inFirstP(N,P);
           int i = 1;
           while ( i <= infoP(P).jml_anak){
               cout<<"-----------------------------------------------"<<endl;
               cout<<"               INPUT ANAK                      "<<endl;
               cout<<"-----------------------------------------------"<<endl;
               cout<<endl;
               cout << "Nama Anak                : " ;
               cin  >> nama;
               cout << "umur Anak                : " ;
               cin  >> umur;
               cout << "tanggal lahir            : " ;
               cin  >> ttl;
               C = alokasiC(nama,umur,ttl);
               inFirstC(A,C);
            i++;
           }
    adrC a = firstC(A);
    while(a != NULL){
        adrR RS = alokasiR();
        if(firstR(R) == NULL){
            firstR(R) = RS;
        }else{
            nextR(RS) = firstR(R);
            firstR(R) = RS;
        }
        nextCR(C) = RS;
        ayah(RS) = P;
        a = nextC(a);
       // cout<<nextCR(C)<<" | "<<RS<<endl;
       // cout<<ayah(RS)<<" | "<<P<<endl;
    }
}

void printAll(ListP S, ListR R, ListC C){

    clrscr();
    cout<<"-----------------------------------------------"<<endl;
    cout<<"              VIEW ALL RELATIONSHIP            "<<endl;
    cout<<"-----------------------------------------------"<<endl;
    if(firstP(S) == NULL && firstR(R) == NULL && firstC(C) == NULL){
        cout<<"Satu atau lebih List ada yang kosong!\n";
    }
    if(firstP(S) != NULL){
        adrP p = firstP(S);
        while (p != NULL){
            adrC c = firstC(C);
            adrR r = firstR(R);
            cout<<"**=========================================**\n";
            cout<<"Nama Pegawai\t\t: "<<infoP(p).nama<<endl;
             cout<<"ID  Pegawai\t\t: "<<infoP(p).ID<<endl;
            while(c != NULL && r != NULL){
                if(nextCR(c)==r || ayah(r)==p){
                        cout<<"Nama Anak\t\t: "<<infoC(c).nama<<endl;
                        cout<<"Umur Anak\t\t: "<<infoC(c).umur<<endl;
                }
                r = nextR(r);
                c = nextC(c);
            }
            p = nextP(p);
        }
        cout<<"**=========================================**\n";
    }
}

// Extra method
void tunjanganAnak(ListC C, ListP P, ListR R){
    // Print anak yang umurnya < 18 thn

    clrscr();
    cout<<"-----------------------------------------------"<<endl;
    cout<<"      DAFTAR ANAK YANG MENDAPAT TUNJANGAN      "<<endl;
    cout<<"-----------------------------------------------"<<endl;
    if(firstP(P) == NULL && firstR(R) == NULL && firstC(C) == NULL){
        cout<<"Satu atau lebih List ada yang kosong!\n";
    }
    //cout<<firstP(P)<<endl;
    if(firstP(P) != NULL && firstR(R) != NULL && firstC(C) != NULL){
        adrP p = firstP(P);
        while (p != NULL){
            adrC c = firstC(C);
            adrR r = firstR(R);
            while(c != NULL && r != NULL){
                if(nextCR(c)==r || ayah(r)==p){
                    if (infoC(c).umur < 18 ){
                        cout<<"**=========================================**\n";
                        cout<<"Nama Pegawai\t\t: "<<infoP(p).nama<<endl;
                        cout<<"ID   Pegawai\t\t: "<<infoP(p).ID<<endl;
                        cout<<"Nama Anak\t\t: "<<infoC(c).nama<<endl;
                        cout<<"Anak dari pegawai "<<infoP(p).nama<<" bernama "<<infoC(c).nama<<" mendapat tunjangan "<<endl;
                    } else {
                        cout<<"tidak ada anak dari pegawai yang mendapat tunjangan"<<endl;
                    }
                }
                r = nextR(r);
                c = nextC(c);
            }
            p = nextP(p);
        }
        cout<<"**=========================================**\n";
    } else {
        cout<<"pegawai tidak memiliki anak"<<endl;
    }

}

void pegNonKB(ListP S){
    // Print pegawai yang anaknya > 3

    clrscr();
    cout<<"-----------------------------------------------"<<endl;
    cout<<"             DAFTAR PEGAWAI NON KB             "<<endl;
    cout<<"-----------------------------------------------"<<endl;
    if ( firstP(S) == NULL ){
        cout<<"list pegawai Kosong"<<endl;
    }else {
        adrP Q = firstP(S);
        while(Q!=NULL) {
            if ( infoP(Q).jml_anak > 3) {
                cout<<"Nama Anak : "<<infoP(Q).nama<<endl;;
                cout<<"ID Pegawai : "<<infoP(Q).ID<<endl;
                cout<<"Jumlah Anak : "<<infoP(Q).jml_anak<<endl;
            }
            Q = nextP(Q);
        }
    }


}
void findAnak(ListP S, ListC C, ListR R, string nama_anak){
    // Print pegawai berdasarkan nama anak
    cout<<"-----------------------------------------------"<<endl;
    cout<<"                  CARI ANAK                    "<<endl;
    cout<<"-----------------------------------------------"<<endl;

    if(firstP(S) == NULL && firstR(R) == NULL && firstC(C) == NULL){
        cout<<"Satu atau lebih List ada yang kosong!\n";
    }
    //cout<<firstP(S)<<endl;
    if(firstP(S) != NULL && firstR(R) != NULL && firstC(C) != NULL){
        adrP p = firstP(S);
        while (p != NULL){
            adrC c = firstC(C);
            adrR r = firstR(R);
            while(c != NULL && r != NULL){
                if(nextCR(c)==r && ayah(r)==p){
                    if (infoC(c).nama == nama_anak)
                        cout<<"Nama Anak\t\t: "<<infoC(c).nama<<endl;
                        cout<<infoC(c).nama<<" adalah Anak dari pegawai "<<infoP(p).nama<<endl;
                }
                r = nextR(r);
                c = nextC(c);
            }
            p = nextP(p);
        }
        cout<<"**=========================================**\n";
    }


}

void addAnak(ListP &S, ListC &B, ListR &R, int idpeg, string nama, int umur, int tggllahir){

    // pegawai manambahkan anak
    adrP P = firstP(S);
    while (P!= NULL && infoP(P).ID != idpeg) {
        P = nextP(P);
    }
    if (infoP(P).ID == idpeg) {
             cout<<"-----------------------------------------------"<<endl;
             cout<<"               INPUT ANAK                      "<<endl;
             cout<<"-----------------------------------------------"<<endl;
             cout<<endl;
             cout << "Nama Anak                : " ;
             cin  >> nama;
             cout << "umur Anak                : " ;
             cin  >> umur;
             cout << "tanggal lahir            : " ;
             cin  >> tggllahir;
             adrC c = firstC(B);
             c = alokasiC(nama,umur,tggllahir);
             inFirstC(B,c);
    }
    adrC a = firstC(B);
    while(a != NULL){
        adrR RS = alokasiR();
        if(firstR(R) == NULL){
            firstR(R) = RS;
        }else{
            nextR(RS) = firstR(R);
            firstR(R) = RS;
        }
        nextCR(a) = RS;
        ayah(RS) = P;
        a = nextC(a);
}
}
