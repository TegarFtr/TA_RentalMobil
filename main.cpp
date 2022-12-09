#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <algorithm>
using namespace std;

int jumlah_avanza = 7,
    jumlah_fortuner = 3,
    jumlah_jazz = 4,
    jumlah_ayla = 5,
    jumlah_ertiga = 1;
string daftar[20][5];

int main();


void gotoxy(short x, short y) {
    COORD k = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}
bool any_space(const string& s)
{
    return std::any_of(s.begin(), s.end(), ::isspace);
}
bool is_digits(const string& str) {
    return str.find_first_not_of("0123456789") == string::npos;
}
void simpan() {
    fstream file;
    file.open("List Penyewa.txt");
    if (!file.is_open()) {
        cout << "Gagal Membuka File!!!!\n";
    }
    for (int i = 0; i <= 19; i++) {
        for (int j = 0; j < 5; j++) {
            file << daftar[i][j] << " ";
        }
    }

    file.close();
}
void simpan2() {
    fstream file;
    file.open("List Mobil.txt");
    if (!file.is_open()) {
        cout << "Gagal Membuka File!!!!\n";
    }
    file << jumlah_avanza << " " << jumlah_fortuner << " " << jumlah_jazz << " " << jumlah_ayla << " " << jumlah_ertiga;

    file.close();
}
void ambil() {
    fstream file;
    file.open("List Penyewa.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file.\n";
    }
    for (int i = 0; i <= 19; i++) {
        for (int j = 0; j < 5; j++) {
            file >> daftar[i][j];
        }
    }

    file.close();
}
void ambil2() {
    fstream file;
    file.open("List Mobil.txt");
    if (!file.is_open()) {
        cout << "Gagal Membuka File!!!!\n";
    }
    file >> jumlah_avanza;
    file >> jumlah_fortuner;
    file >> jumlah_jazz;
    file >> jumlah_ayla;
    file >> jumlah_ertiga;

    file.close();
}
void listpa() {
    gotoxy(50, 15);
    cout << "\n                                                   +-----------------------------------------------------------------------------------------+";
    cout << "\n                                                   |                                                                                         |";
    cout << "\n                                                   |   +---------------------------------------------------------------------------------+   |";
    cout << "\n                                                   |   |                                     List Penyewa                                |   |";
    cout << "\n                                                   |   +------+-----------------+---------------------------+------------------+---------+   |";
    cout << "\n                                                   |   |  No  |      Nama       |           NIK             |   Jenis Mobil    |  Durasi |   |";
    cout << "\n                                                   |   +------+-----------------+---------------------------+------------------+---------+   |";
    for (int i = 0; i < 20; i++) {
        cout << "\n                                                   |   | " << setiosflags(ios::left) << setw(3) << i + 1 << ". |  "  << setw(14) << daftar[i][1] << " |  " << setw(24) << daftar[i][2] << " | " << setw(16) << daftar[i][3] << " |  " << setw(6) << daftar[i][4] << " |   |";
    }
    cout << "\n                                                   |   +------+-----------------+---------------------------+------------------+---------+   |";
    cout << "\n                                                   |                                                                                         |";
    cout << "\n                                                   +-----------------------------------------------------------------------------------------+";
}
void listpu() {
    gotoxy(50, 17);
    cout << "\n                                                                +--------------------------------------------------------------+";
    cout << "\n                                                                |                                                              |";
    cout << "\n                                                                |   +------------------------------------------------------+   |";
    cout << "\n                                                                |   |                       List Penyewa                   |   |";
    cout << "\n                                                                |   +------+-----------------+-------------------+---------+   |";
    cout << "\n                                                                |   |  No  |      Nama       |   Jenis Mobil     |  Durasi |   |";
    cout << "\n                                                                |   +------+-----------------+-------------------+---------+   |";
    for (int i = 0; i < 20; i++) {
        cout << "\n                                                                |   | " << setiosflags(ios::left) << setw(3) << i + 1 << ". |  " << setw(14) << daftar[i][1] << " |  " << setw(16) << daftar[i][3] << " |  " << setw(6) << daftar[i][4] << " |   |";
    }
    cout << "\n                                                                |   +------+-----------------+-------------------+---------+   |";
    cout << "\n                                                                |                                                              |";
    cout << "\n                                                                +--------------------------------------------------------------+";
}
void listmobil() {
    gotoxy(50, 15);
    cout << "\n                                                  +--------------------------------------------------------------------------------------------+";
    cout << "\n                                                  |                                                                                            |";
    cout << "\n                                                  |   +------------------------------------------------------------------------------------+   |";
    cout << "\n                                                  |   |                                     List Mobil                                     |   |";
    cout << "\n                                                  |   +------+------------------------+---------------------------+------------------------+   |";
    cout << "\n                                                  |   |  No  |      Jenis Mobil       |         Tersedia          |   Biaya Sewa (/hari)   |   |";
    cout << "\n                                                  |   +------+------------------------+---------------------------+------------------------+   |";
    cout << "\n                                                  |   |  1.  | Avanza                 |             " << jumlah_avanza << "             |       Rp. 350000       |   |";
    cout << "\n                                                  |   |  2.  | Fortuner               |             " << jumlah_fortuner << "             |       Rp. 600000       |   |";
    cout << "\n                                                  |   |  3.  | Jazz                   |             " << jumlah_jazz << "             |       Rp. 450000       |   |";
    cout << "\n                                                  |   |  4.  | Ayla                   |             " << jumlah_ayla << "             |       Rp. 350000       |   |";
    cout << "\n                                                  |   |  5.  | Ertiga                 |             " << jumlah_ertiga << "             |       Rp. 400000       |   |";
    cout << "\n                                                  |   +------+------------------------+---------------------------+------------------------+   |";
    cout << "\n                                                  |                                                                                            |";
    cout << "\n                                                  +--------------------------------------------------------------------------------------------+";
}
void sewa() {
mainmenu :
    system("cls");
    string nama, nik, lama, check, yesno, temp;
    int panjang;
    for (int g = 0; g <= 19; g++) {
        if (daftar[g][0] == "1") {
            check = "Fill";
        }
        else {
            break;
        }
    }
    gotoxy(40, 1); cout << "+---------------------------------------------------------------------------------------------------------------+";
    gotoxy(40, 2); cout << "|                                                                                                               |";
    gotoxy(40, 3); cout << "|   +-------------------------------------------------------------------------------------------------------+   |";
    gotoxy(40, 4); cout << "|   |                                          Menu Penyewaan Mobil                                         |   |";
    gotoxy(40, 5); cout << "|   +-------------------------------------------------------------------------------------------------------+   |";
    gotoxy(40, 6); cout << "|   |   Masukkan Nama Anda (1 kata)  :                                                                      |   |";
    gotoxy(40, 7); cout << "|   |   Masukkan NIK Anda            :                                                                      |   |";
    gotoxy(40, 8); cout << "|   |   Masukkan Lama Sewa (/hari)   :                                                                      |   |";
    gotoxy(40, 9); cout << "|   +-------------------------------------------------------------------------------------------------------+   |";
    gotoxy(40, 10); cout << "|   |  Lanjutkan(y/n) :                                                                                     |   |";
    gotoxy(40, 11); cout << "|   +-------------------------------------------------------------------------------------------------------+   |";
    gotoxy(40, 12); cout << "|                                                                                                               |";
    gotoxy(40, 13); cout << "+---------------------------------------------------------------------------------------------------------------+";

    for (int i = 0; i <= 19; i++) {
        if (daftar[i][0] == "" || daftar[i][0] == "0" || daftar[i][0] == "N/A") {
        masuknama :
            gotoxy(40, 6); cout << "|   |   Masukkan Nama Anda (1 kata)  : ";
            cin.ignore();
            gotoxy(79, 6); getline(cin, nama);
            int tf = any_space(nama);
            if (tf == 0) {
                daftar[i][1] = nama;
            }
            else {
                gotoxy(79, 6); cout << "Format Nama hanya 1 kata" << endl;
                Sleep(1000);
                goto mainmenu;
            }
        masuknik :
            gotoxy(40, 7); cout << "|   |   Masukkan NIK Anda            :                                                                      |   |";
            gotoxy(79, 7); cin >> nik;
            panjang = nik.length();
            if (is_digits(nik) == 0) {
                gotoxy(79, 7); cout << "NIK hanya berisikan angka." << endl;
                Sleep(1000);
                goto masuknik;
            }
            else {
                daftar[i][2] = nik;
            }
        masukdurasi :
            gotoxy(40, 8); cout << "|   |   Masukkan Lama Sewa (/hari)   :                                                                      |   |";
            gotoxy(79, 8); cin >> lama;
            if (is_digits(lama) == 0) {
                gotoxy(79, 8); cout << "Waktu hanya berisikan angka." << endl;
                Sleep(1000);
                goto masukdurasi;
            }
            else {
                daftar[i][4] = lama;
            }

            gotoxy(65, 10); cin >> yesno;
            if (yesno == "y" || yesno == "Y") {
        pilihmobil :
                Sleep(500);
                listmobil();
                cout << "\n                                                  |    Masukkan Pilihan Anda :                                                                 |";
                cout << "\n                                                  +--------------------------------------------------------------------------------------------+";
                gotoxy(79, 31); cin >> temp;
                if (temp == "1" && jumlah_avanza != 0) {
                    temp = "Avanza";
                    daftar[i][3] = "Avanza";
                    jumlah_avanza--;
                }
                else if (temp == "2" && jumlah_fortuner != 0) {
                    temp = "Fortuner";
                    daftar[i][3] = "Fortuner";
                    jumlah_fortuner--;
                }
                else if (temp == "3" && jumlah_jazz != 0) {
                    temp = "Jazz";
                    daftar[i][3] = "Jazz";
                    jumlah_jazz--;
                }
                else if (temp == "4" && jumlah_ayla != 0) {
                    temp = "Ayla";
                    daftar[1][3] = "Ayla";
                    jumlah_ayla--;
                }
                else if (temp == "5" && jumlah_ertiga != 0) {
                    temp = "Ertiga";
                    daftar[i][3] = "Ertiga";
                    jumlah_ertiga--;
                }
                else {
                    gotoxy(79, 31); cout << "MAAF INPUT TIDAK TERSEDIA";
                    Sleep(1000);
                    goto pilihmobil;
                }
            }
            else {
                goto mainmenu;
            }
            Sleep(500);
            cout << "\n                                                  |                                       SEWA MOBIL SUKSES                                    |";
            cout << "\n                                                  +--------------------------------------------------------------------------------------------+";
            daftar[i][0] = "1";
            simpan();
            simpan2();
            break;
        }
    }
}
void kembali() {
    string nama, no, nik;
    int uang, X, bayar, nurut;
pengembalian:
    gotoxy(39, 1); cout << "+---------------------------------------------------------------------------------------------------------------+";
    gotoxy(39, 2); cout << "|                                                                                                               |";
    gotoxy(39, 3); cout << "|   +-------------------------------------------------------------------------------------------------------+   |";
    gotoxy(39, 4); cout << "|   |                                        Menu Pengembalian Mobil                                        |   |";
    gotoxy(39, 5); cout << "|   +-------------------------------------------------------------------------------------------------------+   |";
    gotoxy(39, 6); cout << "|   |   Masukkan Nomor Urut Anda     :                                                                      |   |";
    gotoxy(39, 7); cout << "|   |   Masukkan Nama Anda           :                                                                      |   |";
    gotoxy(39, 8); cout << "|   |   Masukkan NIK Anda            :                                                                      |   |";
    gotoxy(39, 9); cout << "|   +-------------------------------------------------------------------------------------------------------+   |";
    gotoxy(39, 10); cout << "|   |                                                                                                       |   |";
    gotoxy(39, 11); cout << "|   +-------------------------------------------------------------------------------------------------------+   |";
    gotoxy(39, 12); cout << "|                                                                                                               |";
    gotoxy(39, 13); cout << "+---------------------------------------------------------------------------------------------------------------+";
    gotoxy(78, 6); cin >> no;
    cin.ignore();
    gotoxy(78, 7); getline(cin, nama);
    gotoxy(78, 8); cin >> nik;
    nurut = atoi(no.c_str());
    X = nurut - 1;
    if (nama != daftar[nurut - 1][1] || daftar[X][0] == "0" || nik != daftar[X][2]) {
        gotoxy(68, 10); cout << "VERIFIKASI GAGAL | DATA TIDAK SESUAI" << endl;
        Sleep(1000);
        system("cls");
        goto pengembalian;
    }
    else {
        int hari = atoi(daftar[X][4].c_str());
        if (daftar[X][3] == "Avanza") {
            bayar = hari * 350000;
            jumlah_avanza++;
        }
        else if (daftar[X][3] == "Fortuner") {
            bayar = hari * 600000;
            jumlah_fortuner++;
        }
        else if (daftar[X][3] == "Jazz") {
            bayar = hari * 450000;
            jumlah_jazz++;
        }
        else if (daftar[X][3] == "Ayla") {
            bayar = hari * 350000;
            jumlah_ayla++;
        }
        else if (daftar[X][3] == "Ertiga") {
            bayar = hari * 400000;
            jumlah_ertiga++;
        }
        else {
        }
        Sleep(500);
    pembayaran :
        gotoxy(57, 15); cout << "+---------------------------------------------------------------------------+";
        gotoxy(57, 16); cout << "|                                                                           |";
        gotoxy(57, 17); cout << "|   +-------------------------------------------------------------------+   |";
        gotoxy(57, 18); cout << "|   |                             Pembayaran                            |   |";
        gotoxy(57, 19); cout << "|   +-------------------------------------------------------------------+   |";
        gotoxy(57, 20); cout << "|   |   Nama Anda      :                                                |   |";
        gotoxy(57, 21); cout << "|   |   NIK Anda       :                                                |   |";
        gotoxy(57, 22); cout << "|   |   Mobil Sewa     :                                                |   |";
        gotoxy(57, 23); cout << "|   |   Lama Sewa      :                                                |   |";
        gotoxy(57, 24); cout << "|   +-------------------------------------------------------------------+   |";
        gotoxy(57, 25); cout << "|   |                    Total Sewa Yang Perlu Dibayar : Rp.            |   |";
        gotoxy(57, 26); cout << "|   |                           Jumlah yang dibayarkan : Rp.            |   |";
        gotoxy(57, 27); cout << "|   |                                                   ----------------|   |";
        gotoxy(57, 28); cout << "|   |                                Uang anda kembali : Rp.            |   |";
        gotoxy(57, 29); cout << "|   +-------------------------------------------------------------------+   |";
        gotoxy(57, 30); cout << "|   |                                                                   |   |";
        gotoxy(57, 31); cout << "|   +-------------------------------------------------------------------+   |";
        gotoxy(57, 32); cout << "|                                                                           |";
        gotoxy(57, 33); cout << "+---------------------------------------------------------------------------+";
        gotoxy(82, 20); cout << daftar[X][1] << endl;
        gotoxy(82, 21); cout << daftar[X][2] << endl;
        gotoxy(82, 22); cout << daftar[X][3] << endl;
        gotoxy(82, 23); cout << daftar[X][4] << endl;
        gotoxy(118, 25); cout << bayar << endl;
        gotoxy(118, 26); cin >> uang;
        if (bayar > uang) {
            gotoxy(77, 30); cout << "Uang yang anda bayarkan tidak cukup." << endl;
            system("pause");
            goto pembayaran;
        }
        else {
            gotoxy(118, 28); cout << uang - bayar << endl;
        }
        Sleep(500);
        gotoxy(57, 34); cout << "|                            PEMBAYARAN BERHASIL                            |";
        gotoxy(57, 35); cout << "+---------------------------------------------------------------------------+";

        for (int i = 0; i <= 4; i++) {
            daftar[X][i] = " ";
        }
        daftar[X][0] = "0";
    }
    simpan();
    simpan2();
}



int main() {
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    //system("color F0");
    system("color 0F");
loginuser :
    system("cls");
    ambil();
    ambil2();
    string user, pass;
    char pilihan;
    gotoxy(68, 17); cout << "+--------------------------------------------------+";
    gotoxy(68, 18); cout << "|                                                  |";
    gotoxy(68, 19); cout << "|   +------------------------------------------+   |";
    gotoxy(68, 20); cout << "|   |                                          |   |";
    gotoxy(68, 21); cout << "|   +------------------------------------------+   |";
    gotoxy(68, 22); cout << "|   |   Username :                             |   |";
    gotoxy(68, 23); cout << "|   |   Password :                             |   |";
    gotoxy(68, 24); cout << "|   +------------------------------------------+   |";
    gotoxy(68, 25); cout << "|   |                                          |   |";
    gotoxy(68, 26); cout << "|   +------------------------------------------+   |";
    gotoxy(68, 27); cout << "|                                                  |";
    gotoxy(68, 28); cout << "+--------------------------------------------------+";
    gotoxy(87, 22); cin >> user;
    gotoxy(87, 23); cin >> pass;
    if (user == "admin" && pass == "admin") {
        gotoxy(78, 29); cout << "Akses Diberikan!! Welcome Admin" << endl;
        gotoxy(83, 30); cout << "Sedang Memuat Data";
        Sleep(1000);
        system("cls");
    menuadmin :
        gotoxy(50, 1); cout << "+-------------------------------------------------------------------------------------------+";
        gotoxy(50, 2); cout << "|                                                                                           |";
        gotoxy(50, 3); cout << "|   +-----------------------------------------------------------------------------------+   |";
        gotoxy(50, 4); cout << "|   |                                    Menu Admin                                     |   |";
        gotoxy(50, 5); cout << "|   +-----------------------------------------------------------------------------------+   |";
        gotoxy(50, 6); cout << "|   |   1. List Mobil                                                                   |   |";
        gotoxy(50, 7); cout << "|   |   2. List Penyewa                                                                 |   |";
        gotoxy(50, 8); cout << "|   |   3. Logout                                                                       |   |";
        gotoxy(50, 9); cout << "|   |   4. Exit                                                                         |   |";
        gotoxy(50, 10); cout << "|   +-----------------------------------------------------------------------------------+   |";
        gotoxy(50, 11); cout << "|   |  Pilih :                                                                          |   |";
        gotoxy(50, 12); cout << "|   +-----------------------------------------------------------------------------------+   |";
        gotoxy(50, 13); cout << "|                                                                                           |";
        gotoxy(50, 14); cout << "+-------------------------------------------------------------------------------------------+";
        gotoxy(65, 11); cin >> pilihan;
        switch (pilihan){
            case '1' :
                listmobil();
                cout << "\n\n";
                system("pause");
                system("cls");
                goto menuadmin;
                break;
            case '2' :
                listpa();
                cout << "\n\n";
                system("pause");
                system("cls");
                goto menuadmin;
            case '3' :
                goto loginuser;
                break;
            case '4' :
                exit(1);
                break;
            default :
                gotoxy(50, 11); cout << "|   |                           MAAF INPUT TIDAK TERSEDIA                               |   |";
                Sleep(1000);
                goto menuadmin;
                break;

        }
    }
    else {
        gotoxy(78, 29); cout << "Akses Diberikan!! Welcome " << user << endl;
        gotoxy(83, 30); cout << "Sedang Memuat Data";
        gotoxy(84, 31);
        Sleep(1000);
    menubiasa:
        system("cls");
        gotoxy(50, 1); cout << "+-------------------------------------------------------------------------------------------+";
        gotoxy(50, 2); cout << "|                                                                                           |";
        gotoxy(50, 3); cout << "|   +-----------------------------------------------------------------------------------+   |";
        gotoxy(50, 4); cout << "|   |                                   Menu Penyewa                                    |   |";
        gotoxy(50, 5); cout << "|   +-----------------------------------------------------------------------------------+   |";
        gotoxy(50, 6); cout << "|   |   1. Penyewaan Mobil                                                              |   |";
        gotoxy(50, 7); cout << "|   |   2. Pengembalian Mobil                                                           |   |";
        gotoxy(50, 8); cout << "|   |   3. List Penyewa                                                                 |   |";
        gotoxy(50, 9); cout << "|   |   4. Logout                                                                       |   |";
        gotoxy(50, 10); cout << "|   |   5. Exit                                                                         |   |";
        gotoxy(50, 11); cout << "|   +-----------------------------------------------------------------------------------+   |";
        gotoxy(50, 12); cout << "|   |  Pilih :                                                                          |   |";
        gotoxy(50, 13); cout << "|   +-----------------------------------------------------------------------------------+   |";
        gotoxy(50, 14); cout << "|                                                                                           |";
        gotoxy(50, 15); cout << "+-------------------------------------------------------------------------------------------+";
        gotoxy(65, 12); cin >> pilihan;
        switch (pilihan){
            case '1' :
                system("cls");
                sewa();
                cout << "\n\n";
                system("pause");
                goto menubiasa;
                break;
            case '2' :
                system("cls");
                Sleep(100);
                kembali();
                cout << "\n\n";
                system("pause");
                goto menubiasa;
                break;
            case '3' :
                listpu();
                cout << "\n\n";
                system("pause");
                system("cls");
                goto menubiasa;
                break;
            case '4' :
                goto loginuser;
                break;
            case '5' :
                exit(1);
                break;
            default :
                gotoxy(50, 12); cout << "|   |                           MAAF INPUT TIDAK TERSEDIA                               |   |";
                Sleep(1000);
                goto menubiasa;
                break;
        }
    }

}
