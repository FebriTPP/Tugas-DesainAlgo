#include <iostream>
using namespace std;

class contoh {//Baris ini merupakan deklarasi kelas (class) dengan nama 'contoh'. Class ini memiliki satu variabel anggota bernama 'nilai' yang bertipe data 'int', dan dua fungsi anggota yaitu konstruktor dan getNum()//

//Kata kunci private dan public digunakan untuk menentukan aksesibilitas dari variabel anggota dan fungsi anggota dalam kelas//

private: //Variabel dan fungsi anggota yang dideklarasikan setelah kata kunci private hanya dapat diakses oleh fungsi anggota dalam kelas//
    int nilai;
public: //sedangkan yang dideklarasikan setelah kata kunci public dapat diakses oleh fungsi-fungsi di luar kelas//
    contoh(int n) { //parameter int n yang digunakan untuk menginisialisasi variabel anggota nilai//
        nilai = n; //berfungsi untuk menginisialisasi nilai variabel anggota nilai dengan nilai yang diberikan melalui parameter 'n'//
    }
    int getNum() { //berfungsi untuk mengembalikan nilai variabel anggota 'nilai'//
        return nilai; 
    }
};

int main() { //Baris ini merupakan fungsi main() yang merupakan titik awal program untuk dieksekusi oleh komputer//
    contoh obj(10); //sebuah objek (obj) dibuat dari kelas 'contoh' dengan nilai parameter konstruktor sebesar 10//
    cout << "nilai yang diinput: " << obj.getNum() << endl; //nilai dari objek tersebut dicetak ke layar menggunakan fungsi getNum() dan fungsi cout//
    return 0; //program mengembalikan nilai 0 melalui perintah return 0;//
}

//Dari program di atas, dapat disimpulkan bahwa fungsi contoh(int n) merupakan konstruktor, karena memiliki nama yang sama dengan nama kelas dan tidak memiliki nilai kembalian//