#include <iostream>
#include <string>
using namespace std;

const int MAX = 100; 
string st[MAX]; 
int topIdx = -1; 

bool isEmpty(); 
bool isFull(); 
void push(string x); 
void pop(); 
void peek(); 
void display(); 

int main() { 
    int pilih; 
    string val; 
    do { 
        cout << "\n=== STACK (Array): Tumpukan Pakaian Berdasarkan Warna ===\n"; 
        cout << "1. Tambah Pakaian (Push)\n";
        cout << "2. Ambil Pakaian (Pop)\n";
        cout << "3. Lihat Pakaian Teratas (Peek)\n";
        cout << "4. Lihat Semua Pakaian (Display)\n";
        cout << "5. Keluar\n";
        cout << "Pilih: "; 
        cin >> pilih; 

        if (pilih == 1) { 
            cout << "Masukkan warna pakaian: "; 
            cin >> val;
            push(val); 
        } 
        else if (pilih == 2) pop(); 
        else if (pilih == 3) peek(); 
        else if (pilih == 4) display(); 
    } while (pilih != 5); 
    return 0; 
} 

bool isEmpty() {  
    return topIdx == -1;  
} 

bool isFull()  {  
    return topIdx == MAX - 1;  
} 

void push(string x) { 
    if (isFull()) {  
        cout << "Lemari penuh! Tidak bisa menambah pakaian lagi.\n";  
        return;  
    } 
    st[++topIdx] = x; 
    cout << "Pakaian berwarna \"" << x << "\" berhasil ditumpuk di lemari.\n"; 
} 

void pop() { 
    if (isEmpty()) {  
        cout << "Tumpukan kosong! Tidak ada pakaian untuk diambil.\n";  
        return;  
    } 
    cout << "Pakaian berwarna \"" << st[topIdx--] << "\" diambil dari tumpukan.\n"; 
} 

void peek() { 
    if (isEmpty()) {  
        cout << "Tumpukan kosong!\n";  
        return;  
    } 
    cout << "Pakaian teratas saat ini berwarna: \"" << st[topIdx] << "\"\n"; 
} 

void display() { 
    if (isEmpty()) {  
        cout << "Tumpukan kosong!\n";  
        return;  
    } 
    cout << "Isi tumpukan pakaian (atas ke bawah): "; 
    for (int i = topIdx; i >= 0; --i) 
        cout << st[i] << " "; 
    cout << '\n'; 
}