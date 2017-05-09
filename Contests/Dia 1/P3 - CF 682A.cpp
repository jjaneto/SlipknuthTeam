#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

/*int main(){
  int n, m; cin >> n >> m;
  vi v_n(n); for(int i = 1; i <= n; i++) v_n[i-1] = i;
  vi v_m(m); for(int i = 1; i <= m; i++) v_m[i-1] = i;

  int ans = 0;
  for(int i = 0; i < n; i++){
    int s = v_n[i];
    printf("s == %d -> ", s);
    for(int j = 5; ; j += 5){
      if(j < s) continue;
      int look = j - s;
      //printf("%d ", look);
      if(look == 0) look = 5;
      if(look <= 0 || look > m){
        //printf("entrei %d %d\n", j, look);
        break;
      }      
      printf("%d ", look);
      if(binary_search(v_m.begin(), v_m.end(), look)) ans++;
    }
    puts("");
  }
  printf("%d\n", ans);
  return 0;
}*/

//The formula for number of numbers less or equal to n and divisible by 5 with reminder i is (n+(5-i))/5

int main(){
  long long n, m; cin >> n >> m;
  long long ans = 0;

  ans += (n/5)*(m/5);
  ans += ((n+4)/5)*((m+1)/5);
  ans += ((n+3)/5)*((m+2)/5);
  ans += ((n+2)/5)*((m+3)/5);
  ans += ((n+1)/5)*((m+4)/5);

  cout << ans << endl;
  return 0;
}
