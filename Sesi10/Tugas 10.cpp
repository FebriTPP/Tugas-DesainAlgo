#include <iostream>
#include <string>
using namespace std;

class Buku {
    private:
        string judul;
        string penulis;
        bool dipinjam;
    public:
        // Setter
        void setJudul(string newJudul) {
            judul = newJudul;
        }
        void setPenulis(string newPenulis) {
            penulis = newPenulis;
        }
        void setDipinjam(bool newDipinjam) {
            dipinjam = newDipinjam;
        }
        // Getter
        string getJudul() {
            return judul;
        }
        string getPenulis() {
            return penulis;
        }
        bool isDipinjam() {
            return dipinjam;
        }
};

class Perpustakaan {
    private:
        Buku* daftarBuku[100];
        int jumlahBuku;
    public:
        Perpustakaan() {
            jumlahBuku = 0;
        }
        // Getter
        int getJumlahBuku() {
            return jumlahBuku;
        }
        // Method
        void tambahBuku(Buku* buku) {
            if (jumlahBuku < 100) {
                daftarBuku[jumlahBuku] = buku;
                jumlahBuku++;
            } else {
                cout << "Daftar buku penuh, tidak bisa menambahkan buku baru." << endl;
            }
        }
        void pinjamBuku(string judul) {
            for (int i = 0; i < jumlahBuku; i++) {
                if (daftarBuku[i]->getJudul() == judul && !daftarBuku[i]->isDipinjam()) {
                    daftarBuku[i]->setDipinjam(true);
                    cout << "Buku " << judul << " berhasil dipinjam." << endl;
                    return;
                }
            }
            cout << "Buku " << judul << " tidak tersedia atau sedang dipinjam." << endl;
        }
        void kembalikanBuku(string judul) {
            for (int i = 0; i < jumlahBuku; i++) {
                if (daftarBuku[i]->getJudul() == judul && daftarBuku[i]->isDipinjam()) {
                    daftarBuku[i]->setDipinjam(false);
                    cout << "Buku " << judul << " berhasil dikembalikan." << endl;
                    return;
                }
            }
            cout << "Buku " << judul << " tidak dapat dikembalikan." << endl;
        }
};

int main() {
    // Membuat objek-objek buku
    Buku* buku1 = new Buku();
    buku1->setJudul("Harry Potter dan Batu Bertuah");
    buku1->setPenulis("J.K. Rowling");
    buku1->setDipinjam(false);

    Buku* buku2 = new Buku();
    buku2->setJudul("The Lord of the Rings");
    buku2->setPenulis("J.R.R. Tolkien");
    buku2->setDipinjam(false);

    // Membuat objek perpustakaan
    Perpustakaan* perpustakaan = new Perpustakaan();
  // Menambahkan buku ke daftar buku perpustakaan
  perpustakaan->tambahBuku(buku1);
  perpustakaan->tambahBuku(buku2);

  // Meminjam buku
  perpustakaan->pinjamBuku("Harry Potter dan Batu Bertuah");
    // Mengembalikan buku
  perpustakaan->kembalikanBuku("The Lord of the Rings");

  // Meminjam buku yang sudah dipinjam
  perpustakaan->pinjamBuku("Harry Potter dan Batu Bertuah");

  // Menampilkan jumlah buku
  cout << "Jumlah buku yang tersedia: " << perpustakaan->getJumlahBuku() << endl;

  // Menghapus objek buku dan perpustakaan
  delete buku1;
  delete buku2;
  delete perpustakaan;

  return 0;
}