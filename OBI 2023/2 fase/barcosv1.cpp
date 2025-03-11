#include <bits/stdc++.h>
#define f first
#define s second
#define maxn 100001
#define maxl 18

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

vector <iii> edge;
vector <ii> v[maxn];
int vis[maxn], pai[maxn][maxl], are[maxn][maxl], prof[maxn], p[maxn], sz[maxn], n;

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
    for(int i=0;i<n;i++){
        for(int j=0;j<maxl;j++){
            pai[i][j]=-1;
            are[i][j]=maxn;
        }
    }
    prof[r] = 0;
    dfs(r);
    for(int j=1;j<maxl;j++){
        for(int i=0;i<n;i++){
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

int find(int x){
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}

void unir(int x, int y){
    x = find(x);
    y = find(y);
    if(sz[x]<sz[y]) swap(x, y);
    p[y] = x;
    sz[x] += sz[y];
}

int main(){
    int b, i, x, y, z, q;
    scanf("%d %d", &n, &b);
    for(i=0;i<n;i++){
        p[i] = i;
        sz[i] = 1; 
    }
    for(i=0;i<b;i++){
        scanf("%d %d %d", &x, &y, &z);
        x--;y--;
        edge.push_back({-z, {x, y}});
    }
    sort(edge.begin(), edge.end());
    for(i=0;i<b;i++){
        x = edge[i].s.f;
        y = edge[i].s.s;
        if(find(x)!=find(y)){
            unir(y, x);
            v[x].push_back({y, edge[i].f});
            v[y].push_back({x, edge[i].f});
        }
    }
    precompute(0);
    scanf("%d", &q);
    for(i=0;i<q;i++){
        scanf("%d %d", &x, &y);
        x--;y--;
        printf("%d\n", lca(x, y));
    }
    return (0);
}