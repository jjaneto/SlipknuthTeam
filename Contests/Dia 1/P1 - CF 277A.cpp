#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;

vector<vi> vertex;
vector<vi> AdjList;
vi dfs_num;

void dfs(int u){
  dfs_num[u] = true;
  for(int i = 0; i < (int) AdjList[u].size(); i++){
    int v = AdjList[u][i];
    if(!dfs_num[v]){
      dfs(v);
    }
  }
}

int main(){
  int n, m; cin >> n >> m;
  int aux = 0;
  vertex.assign(m + 1, vi());
  dfs_num.assign(n + 1, 0);
  for(int i = 0; i < n; i++){
    int j; cin >> j;
    if(j == 0){
      aux++;
    }
    for(int k = 0; k < j; k++){
      int lg; cin >> lg;
      vertex[lg].push_back(i);
    }
  }

  if(aux == n){ printf("%d\n", n); return 0; }
   
  //make graph
  AdjList.assign(n + 1, vi());
  vi grau(n + 1, 0);
  for(int q = 1; q <= m; q++){
    vi pairs = vertex[q];

    for(int i = 0; i < (int) pairs.size(); i++){
      int u = pairs[i];
      for(int j = i + 1; j < (int) pairs.size(); j++){
        int v = pairs[j];
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
        grau[u]++, grau[v]++;
      }
    }

  }

  //bool all = true;
  /*int aux = 0;
  for(int i = 0; i < n; i++){
    if(grau[i] == 0){
      aux++;
    }
  }*/
  
  int comp = 0;
  for(int i = 0; i < n; i++){
    if(!dfs_num[i]){
      dfs(i);
      comp++;
    }
  }
  
  printf(comp == 0 ? "0\n" : "%d\n", comp - 1);
  return 0;
}
