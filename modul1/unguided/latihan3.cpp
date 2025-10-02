#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Masukkan angka: "; //program meminta input untuk menentukan tinggi segitiga
    cin>>n;

    for(int i = n; i >= 1; i--){
        // spasi di depan agar berbentuk segitiga
        for(int s = 0; s < (n - i); s++){
            cout<<"  "; // 2 spasi biar rapih
        }

        // cetak angka besar ke terkecil
        for(int j = i; j >= 1; j--){
            cout<<j<<" ";
        }

        cout<<"* "; // ini sebagai pemisah antara angka besar ke kecil dan kecil ke besar

        // cetak angka kecil ke terbesar
        for(int j = 1; j <= i; j++){
            cout<<j<<" ";
        }

        cout<<endl;
    }

    // baris terakhir hanya *
    for(int s = 0; s < n; s++){
        cout<<"  ";
    }
    cout<<"*"<<endl;

    return 0;
}
