#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Node {
    int key;          // 4 digit terakhir nomor telepon
    string value;     // Nama kontak
    Node* next;
};

void initTable(Node* table[]) {
    for (int i = 0; i < SIZE; i++) {
        table[i] = nullptr;
    }
}

int hashFunction(int key) {
    return (key % SIZE + SIZE) % SIZE;
}

void insert(Node* table[], int key, string value) {
    int index = hashFunction(key);
    Node* cur = table[index];
    while (cur != nullptr) {
        if (cur->key == key) {
            cur->value = value;  // update nama jika nomor sudah ada
            return;
        }
        cur = cur->next;
    }
    Node* baru = new Node;
    baru->key = key;
    baru->value = value;
    baru->next = table[index];
    table[index] = baru;
}

Node* search(Node* table[], int key) {
    int index = hashFunction(key);
    Node* cur = table[index];
    while (cur != nullptr) {
        if (cur->key == key) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

void removeKey(Node* table[], int key) {
    int index = hashFunction(key);
    Node* cur = table[index];
    Node* prev = nullptr;
    while (cur != nullptr) {
        if (cur->key == key) {
            if (prev == nullptr) {
                table[index] = cur->next;
            } else {
                prev->next = cur->next;
            }
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void display(Node* table[]) {
    cout << "\nDaftar Kontak Telepon:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Slot " << i << ": ";
        Node* tmp = table[i];
        while (tmp != nullptr) {
            cout << "[No HP Akhir: " << tmp->key << " | Nama: " << tmp->value << "] -> ";
            tmp = tmp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    Node* table[SIZE];
    initTable(table);

    insert(table, 8121, "Ridho Azhari Putra");
    insert(table, 8131, "Rizky Novrizal");
    insert(table, 8143, "Kanaya Traylingga");
    insert(table, 8252, "Hengky Kurniawan");

    display(table);

    Node* hasil = search(table, 8131);
    if (hasil != nullptr) {
        cout << "\nKontak dengan no akhir 8131 ditemukan, nama = " << hasil->value << endl;
    } else {
        cout << "\nKontak dengan no akhir 8131 tidak ditemukan\n";
    }

    removeKey(table, 8131);
    cout << "\nSetelah kontak dengan no akhir 8131 dihapus:\n";
    display(table);

    return 0;
}