#include <bits/stdc++.h>
#define pb push_back
#define maxn 300009
#define f first
#define s second
#define endl '\n'

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long int ll;

vector <int> v[4*maxn];
vii g;
int alt[maxn];

void update(int u, int l, int r, int pos, int val){
    int med = (l+r)/2;
    v[u].push_back(val);
    if(l==r) return;
    if(pos<=med) update(2*u, l, med, pos, val);
    else update((2*u)+1, med+1, r, pos, val);
}

int query(int u, int l, int r, int ql, int qr, int val){
    int med = (l+r)/2;
    if(ql>r || qr<l) return 0;
    if(ql<=l && qr>=r){
        int ini = 0, fim = v[u].size()-1;
        while(ini<fim){
            med = (ini+fim)/2;
            if(v[u][med]<val) ini = med+1;
            else fim = med;
        }
        if(v[u][ini]<val) ini++;
        return v[u].size()-ini;
    }
    return (query(2*u, l, med, ql, qr, val)+query((2*u)+1, med+1, r, ql, qr, val));
}

int main(){
    ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int y, n, i, a, qr, ql, val;
    cin >> y >> n;
    for(i=0;i<y;i++){
        cin >> alt[i];
        g.push_back({alt[i], i});
    }
    sort(g.begin(), g.end());
    for(i=0;i<y;i++){
        update(1, 0, y-1, g[i].s, g[i].f);
    }
    for(i=0;i<n;i++){
        cin >> ql >> val >> qr; ql--; qr += ql;
        if(qr==ql || val<=alt[ql]) cout << "0\n";
        else cout << query(1, 0, y-1, ql+1, qr, val) << endl;
    } 
    return (0);
}