#include <iostream>
using namespace std;

int main() {
  int input[] = {0, 6, 12, 18, 24};
  int n = sizeof(input) / sizeof(input[0]);

  int cari;
  cout << "Masukkan bilangan yang ingin dicari: ";
  cin >> cari;

  int tm = 0, R = n-1, L = 0;
  while (R >= L) {
    int mid = L + (R - L) / 2;

    if (input[mid] == cari) {
      cout << "Bilangan Ditemukan" << endl;
      return 0;
    } else if (input[mid] < cari) {
      L = mid + 1;
    } else {
      R = mid - 1;
    }
  }

  cout << "Bilangan Tidak Ditemukan" << endl;
  return 0;
}