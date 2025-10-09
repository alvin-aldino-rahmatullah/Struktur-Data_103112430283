#include <iostream> // Library untuk input dan output
using namespace std; 

void cetakStok(int arr[], int size) { // Fungsi untuk mencetak isi array stok
    cout << "[";
    for (int i = 0; i < size; i++) { // Perulangan untuk menampilkan setiap elemen array
        if (i > 0) cout << ", "; // Menambahkan koma di antara elemen
        cout << arr[i]; // Mencetak nilai stok
    }
    cout << "]" << endl; 
}

int hitungTotalStok(int arr[], int size) { // Fungsi untuk menghitung total semua stok
    int total = 0; // Variabel untuk menyimpan jumlah total
    for (int i = 0; i < size; i++) { // Menjumlahkan setiap elemen array
        total += arr[i];
    }
    return total; // Mengembalikan nilai total stok
}

int* cariStokSedikit(int arr[], int size) { // Fungsi untuk mencari stok paling sedikit (mengembalikan pointer)
    int* stokTerkecil = &arr[0]; // Menunjuk ke elemen pertama sebagai nilai awal terkecil
    for (int i = 1; i < size; i++) { // Mengecek elemen lainnya
        if (arr[i] < *stokTerkecil) { // Jika ditemukan stok yang lebih kecil
            stokTerkecil = &arr[i]; // Ganti pointer ke elemen tersebut
        }
    }
    return stokTerkecil; // Mengembalikan alamat dari stok terkecil
}

void tambahStokBonus(int* stok) { // Fungsi untuk menambah stok sebesar 10
    *stok += 10; // Mengakses nilai yang ditunjuk oleh pointer dan menambah 10
}

int main() { // Fungsi utama
    int stokBuku[] = {12, 8, 25, 5, 18}; // Array berisi stok masing-masing jenis buku
    int jumlahJenisBuku = 5;

    cout << "Stok Buku Awal:\n"; // Menampilkan teks pembuka
    cetakStok(stokBuku, jumlahJenisBuku); // Memanggil fungsi untuk mencetak stok awal

    int total = hitungTotalStok(stokBuku, jumlahJenisBuku); // Menghitung total stok semua buku
    cout << "Total semua stok buku: " << total << endl; // Menampilkan hasil total

    int* stokTerkecil = cariStokSedikit(stokBuku, jumlahJenisBuku); // Mencari buku dengan stok paling sedikit
    tambahStokBonus(stokTerkecil); // Menambah 10 pada stok yang paling sedikit

    cout << "\nStok Buku Setelah Penambahan Bonus:\n"; // Menampilkan teks pembuka hasil akhir
    cetakStok(stokBuku, jumlahJenisBuku); // Menampilkan stok setelah ditambah bonus

    return 0;
}