#include <iostream> // Library untuk input dan output
using namespace std;

int main() {
    int bukuPerHari[7]={2,1,3,2,4,5,1}; // Inisialisasi array dengan jumlah buku yang dibaca setiap hari selama seminggu 
    int totalBuku=0; // Variabel untuk menyimpan total buku yang dibaca selama seminggu

    cout<<"Laporan Membaca Buku Selama Seminggu"<<endl; // output judul laporan
    for (int i=0; i<7; i++) { // Perulangan untuk menampilkan jumlah buku per hari dari hari ke 1 sampai ke 7
        
        cout<<"Hari ke-"<<i+1<<": "<<bukuPerHari[i] <<" buku."<<endl; // Menampilkan jumlah buku yang dibaca pada hari ke i yang ditambah satu persatu da meanmpilkan buku yang dibaca pada hari tersebut   
        totalBuku += bukuPerHari[i]; // Menambahkan jumlah buku hari ini ke total keseluruhan
    }
}