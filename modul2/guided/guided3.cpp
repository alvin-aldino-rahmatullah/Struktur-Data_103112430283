#include <iostream> // Library untuk input dan output
using namespace std;

// Fungsi untuk menghitung rata-rata nilai tugas dan UTS
float hitungRataRata (int nilaiTugas, int nilaiUTS){
    return (nilaiTugas + nilaiUTS) / 2.0f; // Mengembalikan hasil rata-rata dalam bentuk float
}

// Fungsi untuk mencetak profil siswa nama dan nilai
void cetakProfil(string nama, float nilai){
    cout << "Nama: " << nama << endl; // Menampilkan nama siswa
    cout << "nilai: " << nilai << endl; // Menampilkan nilai siswa
}

// Fungsi untuk menambahkan nilai bonus pakai & 
void beriNilaiBonus(float &nilai){
    nilai += 5.0f; // Menambahkan 5 poin ke nilai asli
}

int main() {
    string namaSiswa = "Budi"; // Variabel untuk menyimpan nama siswa yan bertipe string
    int tugas = 80, uts = 90;  // Nilai tugas dan UTS siswa

    float nilaiAkhir = hitungRataRata(tugas, uts); // Memanggil fungsi untuk menghitung rata-rata

    cout << "PROFIL SISWA" << endl;
    cetakProfil(namaSiswa, nilaiAkhir); // Menampilkan profil siswa

    cout << "\nMemberikan nilai bonus" << endl;
    beriNilaiBonus(nilaiAkhir); // Memberikan bonus nilai

    cout << "\nProfil setelah bonus" << endl;
    cetakProfil(namaSiswa, nilaiAkhir); // Menampilkan profil siswa setelah mendapat bonus nilai

    return 0;
}