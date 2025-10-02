#include <iostream>
#include <string>

using namespace std;

int main(){
    int angka;  // variabel untuk menyimpan input angka dari user
    
    cout << "Masukkan angka (0-100): ";  // prompt untuk userc agar input
    cin >> angka;  // menerima input angka dari user
    
    // validasi input harus antara 0 sampai 100
    if(angka < 0 || angka > 100){
        cout << "Angka harus antara 0 sampai 100!" << endl;
        return 0;  // keluar program jika input tidak valid
    }
    
    // array untuk menyimpan nama angka 0-9
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", 
                      "enam", "tujuh", "delapan", "sembilan"};
    
    string hasil;  // variabel untuk menyimpan hasil konversi
    
    // penanganan untuk angka 0
    if(angka == 0){
        hasil = satuan[0];
    }
    // penanganan untuk angka 100 (khusus)
    else if(angka == 100){
        hasil = "seratus";
    }
    // penanganan untuk angka 1-9
    else if(angka >= 1 && angka <= 9){
        hasil = satuan[angka];
    }
    // penanganan untuk angka 10 (khusus)
    else if(angka == 10){
        hasil = "sepuluh";
    }
    // penanganan untuk angka 11 (khusus)
    else if(angka == 11){
        hasil = "sebelas";
    }
    // penanganan untuk angka 12-19 (angka belasan)
    else if(angka >= 12 && angka <= 19){
        hasil = satuan[angka % 10] + " belas";  // ambil satuan + "belas"
    }
    // penanganan untuk angka 20-99 (angka puluhan)
    else if(angka >= 20 && angka <= 99){
        int puluhan = angka / 10;  // mendapatkan digit puluhan
        int sisa = angka % 10;     // mendapatkan digit satuan
        
        // konversi digit puluhan ke tulisan
        if(puluhan == 2) hasil = "dua puluh";
        else if(puluhan == 3) hasil = "tiga puluh";
        else if(puluhan == 4) hasil = "empat puluh";
        else if(puluhan == 5) hasil = "lima puluh";
        else if(puluhan == 6) hasil = "enam puluh";
        else if(puluhan == 7) hasil = "tujuh puluh";
        else if(puluhan == 8) hasil = "delapan puluh";
        else if(puluhan == 9) hasil = "sembilan puluh";
        
        // tambahkan satuan jika ada (tidak 0)
        if(sisa != 0){
            hasil += " " + satuan[sisa];  // gabungkan puluhan dan satuan
        }
    }
    
    // tampilkan hasil konversi
    cout << "Angka " << angka << " dalam tulisan: " << hasil << endl;
    cout << "Cieee! sekarang bisa baca angka, rajin rajin yak " << endl;  // pesan dari mimin ganteng
    
    return 0;
}