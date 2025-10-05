#include <iostream>
using namespace std;

int main() {
    const int jumlahSiswa = 15;
    int nilai[jumlahSiswa] = {85, 90, 92, 88, 95, 91, 89, 94, 87, 93, 90, 86, 88, 92, 95};
    int target;
    int i = 0;
    int counter = 0;

    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> target;

    while (i < jumlahSiswa) {
        if (nilai[i] == target) {
            counter++;
        }
        i++;
    }

    if (counter > 0) {
        cout << "Nilai " << target << " diperoleh oleh " << counter << " siswa." << endl;
    } else {
        cout << "Tidak ada siswa yang memperoleh nilai " << target << "." << endl;
    }

    return 0;
}