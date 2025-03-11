#include <bits/stdc++.h>
#define f first
#define s second
#define maxn 100001
#define maxl 18

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

vector <ii> v[maxn], vp[maxn];
int vis[maxn], pai[maxn][maxl], are[maxn][maxl], prof[maxn], visi[maxn];

void dfs(int u){
    vis[u]=1;
    for(int i=0;i<v[u].size();i++){
        if(!vis[v[u][i].f]){
            prof[v[u][i].f] = prof[u]+1;
            pai[v[u][i].f][0] = u;
            are[v[u][i].f][0] = -v[u][i].s;
            dfs(v[u][i].f);
        }
    }
}

void precompute(int r){
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxl;j++){
            pai[i][j]=-1;
            are[i][j]=maxn;
        }
    }
    prof[r] = 0;
    dfs(r);
    for(int j=1;j<maxl;j++){
        for(int i=0;i<maxn;i++){
            if(pai[i][j-1]!=-1)pai[i][j] = pai[pai[i][j-1]][j-1];
            are[i][j] = min(are[i][j-1], are[pai[i][j-1]][j-1]);
        }
    }
}

int lca(int x, int y){
    int i, resp = maxn;
    if(prof[y]>prof[x]) swap(x, y);
    for(i=maxl-1;i>=0;i--){
        if(pai[x][i]!=-1 && prof[pai[x][i]]>=prof[y]){
            resp = min(resp, are[x][i]);
            x = pai[x][i];
        }
        
    }
    if(x==y) return resp;
    for(i=maxl-1;i>=0;i--){
        if(pai[x][i]!=pai[y][i]){
            resp = min(resp, are[x][i]);
            resp = min(resp, are[y][i]);
            x = pai[x][i];
            y = pai[y][i];
        }
    }
    resp = min(resp, are[x][0]);
    resp = min(resp, are[y][0]);
    return resp;
}

void bfs(int r){
    priority_queue <iii> q;
    q.push({0,{-1, r}});
    int u, h, l, i;
    while(!q.empty()){
        u = q.top().s.s;
        h = q.top().s.f;
        l = -q.top().f;
        q.pop();
        if(visi[u]) continue;
        visi[u] = 1;
        if(h!=-1){
            v[u].push_back({h, l});
            v[h].push_back({u, l});
        }
        sort(vp[u].begin(), vp[u].end());
        for(i=0;i<vp[u].size();i++){
            if(!visi[vp[u][i].f]){
                q.push({vp[u][i].s, {u, vp[u][i].f}});
            }
        }
    }
}

int main(){
    int n, b, i, x, y, z, q;
    cin >> n >> b;
    for(i=0;i<b;i++){
        cin >> x >> y >> z;
        x--;y--;
        vp[x].push_back({y, z});
        vp[y].push_back({x, z});
    }
    bfs(0);
    precompute(0);
    cin >> q;
    for(i=0;i<q;i++){
        cin >> x >> y;
        x--;y--;
        cout << lca(x, y) << endl;
    }
    return (0);
}