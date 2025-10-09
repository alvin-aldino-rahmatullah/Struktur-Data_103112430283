#include <iostream> // Library standar untuk input dan output
using namespace std; 

int main() {
    float hargaProduk = 50000.0; // Inisialisasi harga awal produk
    float *ptrharga; // Deklarasi pointer untuk menyimpan alamat variabel hargaProduk
    ptrharga = &hargaProduk; // Pointer diarahkan ke alamat memori hargaProduk

    cout << "harga awal produk: " << hargaProduk << endl; // Menampilkan harga sebelum diskon
    cout << "alamat memori harga: " << ptrharga << endl; // Menampilkan alamat memori tempat harga disimpan

    cout << "\n.. memberikan diskon 10% melalui pointer.." << endl; // Informasi proses diskon
    *ptrharga = *ptrharga * 0.9; // Mengakses dan mengubah nilai harga melalui pointer (diskon 10%)
    cout << "Harga setelah diskon: " << hargaProduk << endl; // Menampilkan harga setelah perubahan melalui pointer

    return 0;
}