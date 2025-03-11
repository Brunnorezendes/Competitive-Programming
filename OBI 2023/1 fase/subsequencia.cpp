#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

int v[maxn], m[maxn];

int main(){
    int a, b, i, j;
    cin >> a >> b;
    for(i=0;i<a;i++){
        cin >> v[i];
    }
    for(j=0;j<b;j++){
        cin >> m[j];
    }
    for(i=0, j=0;i<a;i++){
        if(m[j]==v[i]) j++;
    }
    if(j==b) cout << "S\n";
    else cout << "N\n";
    return (0);
}