#include <iostream> 
using namespace std; 
   
struct Node { 
    int harga; 
    Node* left; 
    Node* right; 
    Node(int h): harga(h), left(nullptr), right(nullptr) {} 
}; 

Node* insertNode(Node* root, int harga) { 
    if (!root) return new Node(harga); 
    if (harga < root->harga) root->left = insertNode(root->left, harga); 
    else if (harga > root->harga) root->right = insertNode(root->right, harga); 
    return root; 
} 

bool searchNode(Node* root, int harga) { 
    if (!root) return false; 
    if (root->harga == harga) return true; 
    if (harga < root->harga) return searchNode(root->left, harga); 
    return searchNode(root->right, harga); 
} 

int findMin(Node* root) { 
    if (!root) return -1; 
    while (root->left) root = root->left; 
    return root->harga; 
} 
   
int findMax(Node* root) { 
    if (!root) return -1; 
    while (root->right) root = root->right; 
    return root->harga; 
} 

int countNodes(Node* root) { 
    if (!root) return 0; 
    return 1 + countNodes(root->left) + countNodes(root->right); 
}

int main() { 
    Node* root = nullptr; 
    int pilih, x; 

do { 
        cout << "\n=== SISTEM DATA HARGA BARANG (BST) ===\n"; 
        cout << "1. Tambah Harga Barang\n2. Cari Harga Barang\n3. Tampilkan Harga Termurah\n";
        cout << "4. Tampilkan Harga Termahal\n5. Hitung Jumlah Data Harga\n6. Keluar\n"; 
        cout << "Pilih: "; 
        cin >> pilih;

        if (pilih == 1) { 
            cout << "Masukkan harga barang: "; cin >> x; 
            root = insertNode(root, x); 
            cout << "Harga berhasil disimpan!\n";
        } else if (pilih == 2) { 
            cout << "Masukkan harga yang ingin dicari: "; cin >> x; 
            cout << (searchNode(root, x) ? "Harga ditemukan di daftar!\n" : "Harga tidak ditemukan.\n"); 
        } else if (pilih == 3) { 
            cout << "Harga termurah: " << findMin(root) << "\n"; 
        } else if (pilih == 4) { 
            cout << "Harga termahal: " << findMax(root) << "\n"; 
        } else if (pilih == 5) { 
            cout << "Jumlah data harga: " << countNodes(root) << "\n"; 
        } 
    } while (pilih != 6); 
    return 0; 
}