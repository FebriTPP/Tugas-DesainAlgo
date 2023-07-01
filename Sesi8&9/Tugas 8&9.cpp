#include <iostream>
#define SIZE 10

using namespace std;

// Struktur Data
struct Data {
    int key;
    int value;
};

// Class Hash Table
class HashTable {
private:
    Data* hashArray[SIZE]; // Array untuk menyimpan elemen
    int hashFunction1(int key) {
        return key % SIZE; // Hash function pertama
    }
    int hashFunction2(int key) {
        return 7 - (key % 7); // Hash function kedua
    }

public:
    HashTable() {
        // Inisialisasi semua elemen dengan NULL
        for (int i = 0; i < SIZE; i++) {
            hashArray[i] = NULL;
        }
    }

    // Fungsi untuk memasukkan elemen ke dalam hash table
    void insert(int key, int value) {
        Data* newData = new Data;
        newData->key = key;
        newData->value = value;

        int index = hashFunction1(key); // Menentukan indeks awal dengan hash function pertama
        int step = hashFunction2(key); // Menentukan langkah pergeseran dengan hash function kedua

        // Double Hashing
        while (hashArray[index] != NULL) {
            index = (index + step) % SIZE;
        }

        hashArray[index] = newData;
    }

    // Fungsi untuk mencari elemen berdasarkan kunci
    int search(int key) {
        int index = hashFunction1(key); // Menentukan indeks awal dengan hash function pertama
        int step = hashFunction2(key); // Menentukan langkah pergeseran dengan hash function kedua

        // Double Hashing
        while (hashArray[index] != NULL) {
            if (hashArray[index]->key == key)
                return hashArray[index]->value;
            index = (index + step) % SIZE;
        }

        return -1; // Jika elemen tidak ditemukan
    }

    // Fungsi untuk menghapus elemen berdasarkan kunci
    void remove(int key) {
        int index = hashFunction1(key); // Menentukan indeks awal dengan hash function pertama
        int step = hashFunction2(key); // Menentukan langkah pergeseran dengan hash function kedua

        // Double Hashing
        while (hashArray[index] != NULL) {
            if (hashArray[index]->key == key) {
                delete hashArray[index];
                hashArray[index] = NULL;
                return;
            }
            index = (index + step) % SIZE;
        }
    }
};

int main() {
    HashTable hashTable;

    // Memasukkan elemen ke dalam hash table
    hashTable.insert(12, 55);
    hashTable.insert(23, 78);
    hashTable.insert(42, 39);
    hashTable.insert(7, 89);

    // Mencari dan mencetak elemen berdasarkan kunci
    cout << "Value dengan key 23: " << hashTable.search(23) << endl;
    cout << "Value dengan key 7: " << hashTable.search(7) << endl;
    cout << "Value dengan key 99: " << hashTable.search(99) << endl;

    // Menghapus elemen berdasarkan kunci
    hashTable.remove(23);

    // Mencoba mencari elemen yang telah dihapus
    cout << "Value dengan key 23 setelah dihapus: " << hashTable.search(23) << endl;

    return 0;
}
