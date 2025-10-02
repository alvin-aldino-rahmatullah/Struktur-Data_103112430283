#include<iostream>

using namespace std;

int main(){
    double total_pembelian, diskon;
    cout<<"Berapa Kamu Belanja? Rp.";
    cin>>total_pembelian;
    if(total_pembelian>30000){
        diskon=0.1*total_pembelian;
        cout<<"Kamu dapat diskon sebesar "<<diskon<<" Mantap minnn";
    }else{
        cout<<"kamu belanjanya masih dikit, tambah lagi biar untung";
    }
    return 0;
}