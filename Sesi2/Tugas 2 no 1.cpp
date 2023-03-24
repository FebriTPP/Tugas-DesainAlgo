//Kode ini adalah implementasi quickshort secara Acending//

#include<iostream> //Ini adalah direktif preprosesor untuk memasukkan pustaka iostream ke dalam program, yang memungkinkan kita untuk menggunakan fungsi input dan output standar di C++//
using namespace std; //Ini adalah perintah untuk menggunakan ruang nama std, yang berisi semua fungsi dan kelas standar di C++//
void swap(int arr[] , int pos1, int pos2){ //Fungsi swap() mengambil tiga argumen: array arr, dan dua posisi elemen yang ingin ditukar. Yang ditukar adalah nilai elemen pada posisi pos1 dan pos2//
  int temp; //Mendeklarasikan variabel temp dengan tipe data int, yang akan digunakan untuk menyimpan nilai sementara selama pertukaran//
  temp = arr[pos1]; //Menyimpan nilai elemen pada posisi pos1 ke dalam variabel temp//
  arr[pos1] = arr[pos2]; //Menyalin nilai elemen pada posisi pos2 ke posisi pos1//
  arr[pos2] = temp; //Menyalin nilai elemen yang disimpan di variabel temp ke posisi pos2//
}
int partition(int arr[], int low, int high, int pivot){ //Fungsi partition() membagi array menjadi dua bagian, yang satu memiliki nilai elemen yang lebih kecil dari pivot dan yang lain memiliki nilai elemen yang lebih besar dari pivot. Argumen fungsi ini adalah array arr, dua indeks low dan high, dan pivot//
  int i = low; //Mendeklarasikan nilai i dengan nilai Low untuk cek apakah nilai array lebih besar dari pada pivot//
  int j = low; //Mendeklarasikan j dengan nilai Low untuk cek apakah nilai array lebih kecil dari pada pivot//
  while(i <= high){ //Perulangan while buat ngecek elemen array dari Low sampai High, apakah i lebih kecil sama dengan High?//
    if(arr[i] > pivot){ //Jika nilai array pada posisi i lebih besar dari pada pivot, maka...//
      i++; //i nya ditambah 1 dan terus berulang hingga syarat pada if tidak memenuhi//
    }else{ //Kalo tidak lebih besar, maka...//
      swap(arr,i,j); //Fungsi ini untuk memanggil pertukaran elemen pada posisi i ke j//
      i++; //indeks i ditambah 1//
      j++; //Begitu juga dengan j diambah 1, dan akan terus bruang apabila tidak memenuhi syarat//
    }
  }
  return j-1; //Ngembaliin nilai j-1 yang adalah indeks terakhir array yang lebih kecil dari pivot//
}
void quickSort(int arr[], int low, int high){ //Fungsi quickSort () adalah fungsi utama algoritma QuickSort. Fungsi ini mengambil tiga argumen: array arr, dan indeks low dan high//
  if(low < high){ //Dicek dulu, apakah di dalam indeks array yang lebih kecil ini memiliki nilai yang lebih rendah dari pada nilai didalam indeks array yang lebih besar//
    int pivot = arr[high]; //Mendeklarasikan variabel pivot dengan nilai elemen array pada indeks high, yang akan digunakan sebagai nilai acuan untuk membagi array//
    int pos = partition(arr, low, high, pivot); //Mendeklarasikan variabel pos dengan hasil pemanggilan fungsi partition pada array arr, indeks terendah low, indeks tertinggi high, dan nilai pivot sebagai parameter. Hasil yang dikembalikan oleh fungsi partition akan menjadi batas pembagian array menjadi dua bagian//
    quickSort(arr, low, pos-1); //Manggil fungsi quicksort untuk memproses array sebelum di Pos//
    quickSort(arr, pos+1, high); //Manggil fungsi quicksort untuk memproses array setelah di Pos//
  }
}
int main() //ini adalah fungsi utama//
{
  int n ; //Deklarasiin variabel n buat masukin panjang yang di input kita atau pengguna//
  cout << "Tentukan panjang array : "; //Membuat output dengan pesan agar kita masukin nilai si n ini//
  cin>>n; //Maka dari itu, untuk menandai apa jawaban kita, n adalah penandanya//
  int arr[n]; //Mendeklarasikan arr dengan ukuran n yang telah kita input//
  for( int i = 0 ; i < n; i++){ //ini adalah perulangan untuk segala inputan yang telah kita masukkan hingga batas n yang kita pinta/
    cin>> arr[i]; //membaca inputan kita buat setiap elemen arr yang akan dilakukan perulangan//
  }
  quickSort(arr, 0 , n-1); //Manggil fungsi quicksort untuk ngurutin arr secara rekursif//
  cout<<"Berikut adalah array yang telah di sortir: "; //Output untuk pesan yg menunjukan array yang sudah disortir//
  for( int i = 0 ; i < n; i++){ //Perulangan yang nantinya akan menampilkan array yang sudah di urutkan//
    cout<< arr[i]<<"\t"; //Menampilkan elemen array yang sebelum nya sudah kita input sebelumnya, tidak lupa dengan tanpa pemisah Tab//
  }
}