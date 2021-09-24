#include <iostream>
#include <time.h>
#include <fstream> 
#include <string>

using namespace std;

void ambilWaktu(){
    struct tm * SysWaktu;
    time_t Waktu;
    Waktu = time(NULL);
    SysWaktu = localtime(&Waktu);

    cout << "Tanggal dan Waktu hari ini adalah: " <<  asctime (SysWaktu);
}

void pasangAlarm(){
    int jam, menit; 
    string musik; 
    
    cout << endl << endl;
    cout << "                     MENGATUR ALARM                      " << endl;
    cout << "************************WARNING!*************************" << endl;
    cout << "Alarm HANYA dapat mengatur waktu pada tanggal yang sama!!!" << endl << endl;
    ambilWaktu();
    cout << endl;
    cout << "Langkah 1. Inisiasi Waktu" << endl;
    cout << "Masukkan jam: ";
    cin >> jam; 
    cout << "Masukkan menit: ";
    cin >> menit; 
    
    cout << endl;
    cout << "Langkah 2. Inisiasi File Alarm" << endl;
    cout << "Inisiasi Lokasi File Alarm" << endl;
    cout << "contoh = C:\\HighHopes.mp3" << endl;
    cout << "File HARUS terletak di lokasi  C:\\" << endl;
    cout << "Silakan ketikkan lokasi file Anda: ";
    cin >> musik;
    
    cout << endl << endl;
    cout << "Mengatur Alarm...." << endl;
    cout << "Alarm BERHASIL diatur, siap membangunkan Anda pada: " << jam << ":" << menit << endl;

    loop: 

    struct tm *SysWaktu;
    time_t Waktu;
    Waktu = time(NULL);
    SysWaktu = localtime(&Waktu);
        
    if (jam != SysWaktu->tm_hour){
        goto loop;
    }

    if (menit != SysWaktu->tm_min){
        goto loop;
    }
    
    cout << endl << endl;
    cout << "Alarm Berbunyi!!!" << endl;
    cout << "Terima Kasih telah menggunakan alarm ini" << endl << endl;
    
	system(musik.c_str()); 
}

int main(){
    int n;

    cout << endl;
    cout << "                       SELAMAT DATANG                        " << endl;
    cout << "Program ini dapat memasang alarm dengan file di komputer Anda" << endl;
    cout << "                      Author @aufarhmn                       " << endl << endl;
    cout << "Pilih Menu berikut: "<< endl;
    cout << "1) Melihat Tanggal dan Waktu" << endl; 
    cout << "2) Mengatur Alarm" << endl;
    cout << "Silakan masukkan angka: ";
    cin >> n;

    switch (n)
    {
        case 1:
        cout << endl;
        ambilWaktu();
        cout << endl << endl;
        break;
           
        case 2:
        pasangAlarm();
        break;

        default:
        cout << endl;
        cout << "Angka yang Anda input BUKAN angka 1 atau 2" << endl << endl;
        break;
    }
}