#include<iostream> // library untuk input dan output

using namespace std;

int main(){
    int r=20; // inisialisasi variabel r dengan nilai awal 20
    int s;    // deklarasi variabel s yang belum ada nilai

    s=20 + ++r; // prosesnya itu r ditambah dulu jadi 21, lalu s = 20 + 21 = 41
    cout<<"Nilai r saat ini "<<r<<endl; // menampilkan nilai r (21)
    cout<<"Nilai s saat ini "<<s<<endl; // menampilkan nilai s (41)

    return 0; // program selesai
}
