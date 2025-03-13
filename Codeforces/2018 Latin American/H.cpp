#include <bits/stdc++.h>
#define pb push_back
#define maxn 10009
#define f first
#define s second
#define inf 1000000000000000003

using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;

map <ii, int> mp;
viii g[maxn];
vi lista[maxn];
ll vis[maxn], dist[maxn], custo[maxn];
priority_queue <iii> q;

void djk(int u){
    iii p;
    ll d_now, len, cost;
    int nex, viz;
    q.push({{0, 0}, u});
    dist[u] = 0;
    while(!q.empty()){
        p = q.top();
        q.pop();
        nex = p.s;
        d_now = -p.f.f; 
        cost = p.f.s;
        if(d_now>dist[nex]) continue;
        custo[nex] = min(custo[nex], cost);
        if(vis[nex]) continue;
        vis[nex] = 1;
        for(int i=0;i<g[nex].size();i++){
            viz = g[nex][i].s;
            len = g[nex][i].f.f;
            if(dist[viz]>=dist[nex]+len){
                dist[viz] = dist[nex]+len;
                q.push({{-dist[viz], g[nex][i].f.s}, viz});
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int i, n, m, a, b, j;
    ll c, d;
    ll sum=0, mini;
    cin >> n >> m;
    for(i=0;i<n;i++){
        dist[i] = inf;
        custo[i] = inf;
    }
    for(i=0;i<m;i++){
        cin >> a >> b >> c >> d;a--;b--;
        g[a].pb({{c, d}, b});
        g[b].pb({{c, d}, a});
        mp[{a, b}] = g[a].size()-1;
        mp[{b, a}] = g[b].size()-1;
    }
    djk(0);
    for(i=1;i<n;i++){
        sum += custo[i];
    }
    cout << sum << endl;
    return (0); 
}