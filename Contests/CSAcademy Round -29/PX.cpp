#include <bits/stdc++.h>
using namespace std;

/*
    Author: Adam Lucas
    Since: 24 de Maio de 2017
    Positive Xor - CSAcademy Round #29 
*/
int main() {
    int n; scanf("%d", &n);
    int a[n];
    int ans=0;
   
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
         
    }
    
    int menorzero=0, maiorzero=n-1;
    while(a[menorzero] == 0) menorzero++;
    while(a[maiorzero] == 0) maiorzero--;
    
    maiorzero = n-maiorzero-1;
    
    for(int i = menorzero; i<n-maiorzero; i++){
    	ans ^= a[i];
    }
    
    if(ans) ans=n;
    else
    	ans = (n-menorzero-maiorzero-1)+(max(maiorzero, menorzero));
    
    printf("%d\n", ans);
}
