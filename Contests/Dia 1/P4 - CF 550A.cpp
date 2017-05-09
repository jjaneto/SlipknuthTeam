#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
  bool ans = false;
  string t, w;
  cin >> t; w = t;
  int pos = t.find("AB");
  if(pos == string::npos){
    ans = false;
  }else{
    t[pos] = t[pos + 1] = '#';
    int pos2 = t.find("BA");
    if(pos2 == string::npos){
      ans = false;
    }else{ printf("YES\n"); return 0; }
  }

  int c = w.find("BA");
  if(c == string::npos){
    ans = false;
  }else{
    w[c] = w[c + 1] = '#';
    int c2 = w.find("AB");
    if(c2 == string::npos){
      ans = false;
    }else{ printf("YES\n"); return 0; }
  }

  printf("NO\n");
  return 0;
}
