#include<iostream> // library untuk input dan output

using namespace std; 

int main(){
    double total_pembelian, diskon; // variabel untuk simpan total belanja dan diskon
    cout<<"Berapa Kamu Belanja? Rp."; // Menanyai user total belanja
    cin>>total_pembelian; // user memasukkan total belanja

    // program akan cek apakah total belanja lebih dari 30000
    if(total_pembelian>30000){
        diskon=0.1*total_pembelian; // jika ya maka hitung diskon 10%
        cout<<"Kamu dapat diskon sebesar "<<diskon<<" Mantap minnn"; // dan menampilkan diskon
    }else{
        cout<<"kamu belanjanya masih dikit, tambah lagi biar untung"; // Tapi kalau belanja kurang dari 30000, maka program meminta tambah belanja dan tidak dapat diskon.
    }

    return 0; 
}