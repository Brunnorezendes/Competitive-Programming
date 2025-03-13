#include <bits/stdc++.h>
#define maxn 400010
#define f first
#define s second

using namespace std;
typedef pair <int,int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;
typedef long long int ll;

vii vx, vy;
vi vals;

int bit[2][maxn];

map <int,int> mp;

int query(int tipo, int x){
    int resp = 0;
    while(x<maxn){
        resp += bit[tipo][x];
        x += x&(-x);
    }
    return resp;
}

void update(int tipo, int x){
    while(x>0){
        bit[tipo][x]++;
        x -= x&(-x);
    }
}

int main(){
    ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);
    ll resp = 0;
    int x, y, n, m, i, cont=1;
    cin >> x >> y >> n >> m;
    for(i=0;i<n;i++){
        cin >> x >> y;
        vx.push_back({x, y});
        vals.push_back(x);
        vals.push_back(y);
    }
    for(i=0;i<m;i++){
        cin >> x >> y;
        vy.push_back({x, y});
        vals.push_back(x);
        vals.push_back(y);
    }
    sort(vals.begin(), vals.end());
    for(i=0;i<vals.size();i++)
        if(!mp[vals[i]]) mp[vals[i]] = cont++;
    for(i=0;i<n;i++){
        vx[i].f = mp[vx[i].f];
        vx[i].s = mp[vx[i].s];
    }
    for(i=0;i<m;i++){
        vy[i].f = mp[vy[i].f];
        vy[i].s = mp[vy[i].s];
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    resp = (ll)(m+1)*(ll)(n+1);
    for(i=0;i<n;i++){
        resp += (ll)query(0, vx[i].s);
        update(0, vx[i].s);
    }
    for(i=0;i<m;i++){
        resp += (ll)query(1, vy[i].s);
        update(1, vy[i].s);
    }
    cout << resp << endl;
    return (0);
}