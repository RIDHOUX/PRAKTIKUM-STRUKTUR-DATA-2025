#include <iostream>
using namespace std;

void menu() {
    cout << "\n=== MENU SUPERMARKET ===\n";
    cout << "1. Masukkan Nama Barang\n";
    cout << "2. Masukkan Harga Normal Barang\n";
    cout << "3. Masukkan Harga Promo Barang\n";
    cout << "4. Tampilkan Daftar Harga\n";
    cout << "5. Keluar\n";
    cout << "Pilihan: ";
}

int main() {
    int harga[2][2] = {0};
    string produk[2] = {"", ""};
    int choice;
    bool running = true;

    while (running) {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < 2; i++) {
                    cout << "Masukkan nama barang ke-" << i+1 << ": ";
                    cin >> produk[i];
                }
                break;

            case 2:
                for (int i = 0; i < 2; i++) {
                    cout << "Masukkan harga normal untuk " << produk[i] << ": ";
                    cin >> harga[i][0];
                }
                break;

            case 3:
                for (int i = 0; i < 2; i++) {
                    cout << "Masukkan harga promo untuk " << produk[i] << ": ";
                    cin >> harga[i][1];
                }
                break;

            case 4:
                cout << "\nDaftar Harga Produk Supermarket:\n";
                cout << "Produk\t\tNormal\tPromo\n";
                cout << "----------------------------------\n";
                for (int i = 0; i < 2; i++) {
                    cout << produk[i] << "\t\t" 
                         << harga[i][0] << "\t" 
                         << harga[i][1] << endl;
                }
                break;

            case 5:
                running = false;
                cout << "Program selesai. Terima kasih!\n";
                break;
        }
    }

    return 0;
}