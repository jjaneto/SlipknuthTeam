/*#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main(){
  int n; scanf("%d", &n);
  set<int, greater<int> > v;
  for(int i = 0; i < n; i++){
    int u; cin >> u;
    v.insert(u);
  }
  bool right = true;
  int mx = *v.begin();
  int cs = *v.begin();
  while(!v.empty() & right){
    if(cs != *v.begin()){
      right = false;
      break;
    }
    cs = *v.begin() - 1;
    v.erase(v.begin());
  }
  printf("%d\n", right ? mx+1 : cs);
  return 0;
}

*/
//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v){
        cin >> x;
    }
    sort(v.begin(), v.end());
    int cur = 1;
    for(int i = 0; i < n; i++){
        if(v[i] >= cur) cur++;
    }
    cout << cur << endl;
    return 0;
}
