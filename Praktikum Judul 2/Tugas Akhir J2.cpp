#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}

int main() {
    int n;
    int arr[1005];

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    cout << "Masukkan tinggi badan mahasiswa (dalam cm): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tukar(&arr[j], &arr[j + 1]);
            }
        }
    }

    cout << "Tinggi badan setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}