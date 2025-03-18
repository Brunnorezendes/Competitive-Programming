#include <bits/stdc++.h>
#define pb push_back
#define maxn 100009

using namespace std;
typedef vector<int> vi;
typedef long long int ll;

vi g[maxn];
int dead[maxn], nex[maxn], pai[maxn];

int dfs(int u){
    int k;
    if(!dead[u]) return u;
    for(;nex[u]<g[u].size();nex[u]++){
        k = dfs(g[u][nex[u]]);
        if(k) return k;
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int i, q, cont = 2, t, x, king = 1;
    cin >> q;
    for(i=0;i<q;i++){
        cin >> t >> x;
        if(t==1){
            g[x].push_back(cont);
            pai[cont++] = x;
        }
        else{
            dead[x] = 1;
            if(x==king)
                while(!(king = dfs(x))) x = pai[x];
            cout << king << endl;
        }
    }
    return (0);
}