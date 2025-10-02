#include <iostream>

using namespace std;

int main(){
    float a, b, tambah, kurang, kali, bagi; // mendeklarasikan seluruh variabel yang digunakan
    cout<<"Masukkan bilangan pertama: ";
    cin>>a; // input bilangan pertama ke dalam variabel a
    cout<<"Masukkan bilangan kedua: ";
    cin>>b; // input bilangan kedua ke dalam variabel b

    // proses penghitungan input a dan input b. Memasukkan hasil ke dalam variabel tambah, kurang, kali, dan bagi
    tambah = a + b;
    kurang = a - b;
    kali = a * b;
    bagi = a / b;

    // output hasil keseluruhan operasi
    cout<<"Hasil penjumlahan: "<<tambah<<endl;
    cout<<"Hasil pengurangan: "<<kurang<<endl;
    cout<<"Hasil perkalian: "<<kali<<endl;
    cout<<"Hasil pembagian: "<<bagi<<endl;

    return 0;
}
