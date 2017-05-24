#include <bits/stdc++.h>
using namespace std;

int it[100001];

/*
    Author: Adam Lucas
    Since: 24 de Maio de 2017
    Equality - CSAcademy Round #29 
*/
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int mi = 1000000, mx = -1;
    
    for(int i=0; i<n; i++){
        int x; scanf("%d", &x);
        it[x]++;
        mx = x>mx?x:mx;
        mi = mi<x?mi:x;
    }
    
    int ans = 0;
    while(mx-mi > k){
    	int menor = min(it[mi], it[mx]);
        it[mx] -= menor;
        it[mx-1] += menor;
        it[mi] -= menor;
        it[mi+1] += menor;
        
        if(it[mx] == 0) mx--;
        if(it[mi] == 0) mi++;
        
        ans+=menor;
    }
    
    printf("%d\n", ans);
}
