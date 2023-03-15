#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah buku: ";
    cin >> n;

    string books[n];

    // input judul buku
    for (int i = 0; i < n; i++) {
        cout << "Masukkan judul buku ke-" << i+1 << ": ";
        cin >> books[i];
    }

    // sorting dengan Bubble Sort
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (books[j] > books[j+1]) {
                string temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }

    // output hasil pengurutan
    cout << "Judul buku setelah diurutkan secara ascending:\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << books[i] << endl;
    }

    return 0;
}
