#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int, long long> il;

vi sad, in, dfs_num, v_sads, childrens;
vector<vector<il> > AdjList;
long long ans;

int dfs(int u, long long maxDist, bool cnt){
  dfs_num[u] = true;
  childrens[u] = 1;
  if(u != 1 && sad[u] < maxDist && cnt){
    v_sads.push_back(u);
    cnt = false;
  }
  
  for(int i = 0; i < (int) AdjList[u].size(); i++){
    il v = AdjList[u][i];
    if(!dfs_num[v.first]){
      childrens[u] += dfs(v.first, max(maxDist + v.second, (long long) 0), cnt);
    }
  }

  return childrens[u];
}

int main(){
  int n; cin >> n;
  sad.resize(n + 1);
  in.assign(n + 1, 0);
  dfs_num.assign(n + 1, 0);
  childrens.assign(n + 1, 0);
  AdjList.assign(n + 1, vector<il>());
  for(int i = 1; i <= n; i++) cin >> sad[i];
  for(int i = 1; i <= n - 1; i++){
    int u = i + 1;
    int v; long long w; cin >> v >> w;
    AdjList[u].push_back(il(v, w));
    AdjList[v].push_back(il(u, w));
    in[v]++;
  }

  dfs(1, 0, true);

  for(int i = 0; i < (int) v_sads.size(); i++){
    ans += childrens[v_sads[i]];
  }
  
  cout << ans << endl;
  return 0;
}
