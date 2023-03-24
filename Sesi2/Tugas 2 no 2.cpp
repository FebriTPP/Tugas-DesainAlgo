#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int>& array, int start, int end){
  if (start >= end) return;
  int pivot = array[end];
  int partition_index = start;
  
  for(int i = start; i < end; i++){
    if(array[i] <= pivot){
      swap(array[i], array[partition_index]);
      partition_index++;
    }
  }
  swap(array[partition_index], array[end]);
  
  quick_sort(array, start, partition_index - 1);
  quick_sort(array, partition_index + 1, end);
}

int main(){
  cout << "Masukkan angka-angka dalam array, pisahkan dengan spasi: " << endl;
  vector<int> array;
  int input;
  while (cin >> input){
    array.push_back(input);
    cout << "Proses pengurutan Array: " << endl; 
    for (int i = 0; i < array.size(); i++){
      cout << array[i] << " ";
    }
    int batch_size = 1;
    if (array.size() > batch_size) {
      quick_sort(array, 0, array.size() - 1);
    }
    cout << "\nArray setelah diurutkan: " << endl;
    for (int i = 0; i < array.size(); i++){
      cout << array[i] << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}