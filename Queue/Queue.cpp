#include <iostream>
#include <vector>
#include <queue>

#define M 1000
using namespace std;

const int N=5;

void dijkstra(int graph[N][N], int source, int destination){
  vector<pair<int, int>>adj[N]; // Matriks adjacency list untuk menyimpan informasi tetangga dan bobot jalur
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(graph[i][j] !=M){
        adj[i].push_back(make_pair(j,graph[i][j])); // Menambahkan tetangga dengan bobot jalur ke adjacency list
      }
    }
  }
  int Q[N],R[N]; // Array untuk menyimpan beban (Q) dan rute (R) sementara
  for(int i=0;i<N;i++){
    Q[i]=M; // Inisialisasi beban dengan nilai tak terhingga
    R[i]=-1; // Inisialisasi rute dengan nilai -1 (tidak ada rute)
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // Priority queue untuk memilih node berikutnya
  pq.push(make_pair(0,source-1)); // Memasukkan pasangan (0, source-1) ke dalam priority queue
  Q[source-1]-0; // Menginisialisasi beban node awal dengan 0
  while(!pq.empty()){
    int u=pq.top().second; // Mengambil node u dengan beban terkecil
    pq.pop();

    for (int i=0;i<adj[u].size();i++){
      int v=adj[u][i].first; // Mengambil tetangga v
      int w=adj[u][i].second; // Mengambil bobot jalur u-v

      if(Q[v]>Q[u]+w){ // Jika beban v lebih besar dari beban u + w
        Q[v]=Q[u]+w; // Update beban v
        R[v]=u; // Update rute v
        pq.push(make_pair(Q[v],v)); // Masukkan pasangan (Q[v], v) ke dalam priority queue
      }
    }
  }
  cout <<"Beban = ";
  for(int i=0;i<N;i++){
    cout << Q[i] << " "; // Menampilkan beban setiap node
  }
  cout << endl;
  cout << "Rute = ";
  for(int i=0;i<N;i++){
    cout << R[i]<< " "; // Menampilkan rute setiap node
  }
  cout << endl;
}

int main(){
  int graph[N][N] = {{0,1,3,M,M},{M,0,1,M,5},{3,M,0,2,M},{M,M,M,0,1},{M,M,M,M,0}}; // Matriks adjacency untuk graf
  int source, destination;
  cout << "Masukkan node asal: ";
  cin >> source;
  cout << "Masukkan node tujuan: ";
  cin >> destination;

  dijkstra(graph, source, destination); // Memanggil fungsi dijkstra
  return 0;
}
