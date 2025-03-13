#include <bits/stdc++.h>
#define f first
#define s second
#define maxn 200010
#define maxl 27

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

vi g[maxn];

int h[maxn], pai[maxl][maxn];

void precompute(int n){
    for(int j=1;j<maxl-3;j++){
        for(int i=0;i<n;i++){
            if(pai[j-1][i]>=0) pai[j][i] = pai[j-1][pai[j-1][i]];
        }
    }
}

void dfs(int u){
    for(int i=0;i<g[u].size();i++){
        if(g[u][i] != pai[0][u]){
            h[g[u][i]] = h[u]+1;
            pai[0][g[u][i]] = u;
            dfs(g[u][i]);
        }
    }
}

ii lca(int a, int b){
    int i, resp=0;
    if(h[a]<h[b]) swap(a, b);
    for(i=maxl-4;i>=0 && h[a]>h[b];i--){
        if(h[a] - (1<<i) >=h[b]){
            a = pai[i][a];
            resp += 1<<i;
        }
    }
    if(a==b) return make_pair(a, resp);
    for(i=maxl-4;i>=0;i--){
        if(pai[i][a]!=pai[i][b]){
            a = pai[i][a];
            b = pai[i][b];
            resp += 2*(1<<i);
        }
    }
    resp+=2;
    return make_pair(pai[0][a], resp);
}

int minimo(int a, int b){
    if(h[a]>h[b]) return a;
    return b;
}

int main(){
    ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);
    int n, q, i, a[2], b[2], j, k, jmin, kmin, u;
    cin >> n >> q;
    for(i=0;i<n-1;i++){
        cin >> a[0] >> b[0];a[0]--;b[0]--;
        g[a[0]].push_back(b[0]);
        g[b[0]].push_back(a[0]);
    }
    dfs(0);
    precompute(n);
    for(i=0;i<q;i++){
        cin >> a[0] >> a[1] >> b[0] >> b[1];a[0]--;b[0]--;a[1]--;b[1]--;
        u = lca(a[0], a[1]).f;
        k = lca(b[0], b[1]).f;
        if(h[u]<h[k]){
            swap(u, k);
            swap(a[0], b[0]);
            swap(a[1], b[1]);
        }
        if(lca(u, b[0]).f!=u && lca(u, b[1]).f!=u){
            cout << "0" << endl;
        }
        else if(lca(u, b[1]).f==u && lca(u, b[0]).f==u){
            cout << lca(minimo(lca(a[0], b[0]).f, lca(a[1], b[0]).f), minimo(lca(a[0], b[1]).f, lca(a[1], b[1]).f)).s+1 << endl;
        }
        else if(lca(u, b[1]).f!=u){
            cout << lca(lca(a[0], b[0]).f, lca(a[1], b[0]).f).s+1 << endl;
        }
        else{
            cout << lca(lca(a[0], b[1]).f, lca(a[1], b[1]).f).s+1 << endl;
        }
    }
    return (0);
}