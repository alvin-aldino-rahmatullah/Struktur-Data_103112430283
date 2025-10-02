#include<iostream> // Library standar untuk input dan output

using namespace std;

int main(){
    float celcius, fahreinheit; // deklarasi variabel untuk menyimpan suhu celcius dan fahrenheit

    cout<<"Tulis sedingin apa gebetan lu"; // program menanyakan suhu dalam celcius dan user akan menjawab
    cin>>celcius; // user memasukkan nilai suhu dalam celcius

    fahreinheit=(9.0/5.0)*celcius+32; // rumus konversi celcius ke fahrenheit

    cout<<"Kalau di fahreinheit itu "<<fahreinheit<<" derajar"<<endl; // tampilkan hasil konversi 
    cout<<"itu dingin banget sih, saran gua jauhin aja"; // teks untuk suruh menjauh dari gebetan wkwk

    return 0;
}
