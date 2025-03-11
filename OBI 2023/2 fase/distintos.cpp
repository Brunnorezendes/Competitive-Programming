#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

int num[maxn], v[maxn];

int main(){
    int ini=0, fim, n, resp=0;
    cin >> n;
    for(fim=0;fim<n;fim++) cin >> v[fim];
    for(fim=0;fim<n;fim++){
        if(num[v[fim]]){
            while(v[ini]!=v[fim]) num[v[ini++]]=0;
            ini++;
        }
        else num[v[fim]]=1;
        resp = max(resp, fim-ini+1);
    }
    cout << resp << endl;
    return (0);
}