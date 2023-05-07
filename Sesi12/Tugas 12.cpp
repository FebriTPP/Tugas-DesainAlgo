#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
    protected:
        string statusMahasiswa;
        string nama;
        int umur;
        string jurusan;
        string fakultas;
    public:
        Mahasiswa(string sm, string n, int u, string j, string f) {
            statusMahasiswa = sm;
            nama = n;
            umur = u;
            jurusan = j;
            fakultas = f;
        }
        virtual void display() {
            cout << "Status Mahasiswa: " << statusMahasiswa << endl;
            cout << "Nama: " << nama << endl;
            cout << "Umur: " << umur << endl;
            cout << "Jurusan: " << jurusan << endl;
            cout << "Fakultas: " << fakultas << endl;
        }
};

class Alumni : public Mahasiswa {
    private:
        int tahunLulus;
        string pekerjaan;
    public:
        Alumni(string sm, string n, int u, string j, string f, int tl, string p) : Mahasiswa(sm, n, u, j, f) {
            tahunLulus = tl;
            pekerjaan = p;
        }
        void display() {
            cout << "Status Mahasiswa: " << statusMahasiswa << endl;
            cout << "Nama: " << nama << endl;
            cout << "Umur: " << umur << endl;
            cout << "Jurusan: " << jurusan << endl;
            cout << "Fakultas: " << fakultas << endl;
            cout << "Tahun Lulus: " << tahunLulus << endl;
            cout << "Pekerjaan: " << pekerjaan << endl;
        }
};

int main() {
    Mahasiswa *m[2];
    m[0] = new Mahasiswa("Mahasiswa Aktif", "Febri", 20, "Teknologi Informasi", "Informatika dan Pariwisata");
    m[1] = new Alumni("Alumni", "Sugih", 25, "Manajemen", "Bisnis", 2020, "Pengusaha");

    cout << "Data Mahasiswa" << endl;
    for (int i = 0; i < 2; i++) {
        m[i]->display();
        cout << endl;
    }

    return 0;
}
