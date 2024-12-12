#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define maxn 200009

using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef long double ld;
typedef vector<ld> vld;
typedef pair<ii,int> iii;

ll seg[4*maxn], v[maxn], lazy[2][4*maxn];

void build(int u, int l, int r){
    if(l==r) seg[u] = v[l];
    else{
        int med = (l+r)/2;
        build(2*u, l, med);
        build((2*u)+1, med+1, r);
        seg[u] = seg[2*u]+seg[(2*u)+1];
    }
}

void unlazy(int u, int l, int r){
    ll tam = r-l+1;
    seg[u] += tam*lazy[0][u] + lazy[1][u]*(tam*(tam-1))/2;
    if(l<r){
        int med = (l+r)/2;
        lazy[0][2*u] += lazy[0][u];
        lazy[1][2*u] += lazy[1][u];
        lazy[0][(2*u)+1] += lazy[0][u] + (med+1-l)*lazy[1][u];
        lazy[1][(2*u)+1] += lazy[1][u];
    }
    lazy[0][u] = lazy[1][u] = 0;
}

ll query(int u, int l, int r, int ql, int qr){
    unlazy(u, l, r);
    if(ql>r || qr<l) return 0;
    if(ql<=l && qr>=r) return seg[u];
    int med = (l+r)/2;
    return (query(2*u, l, med, ql, qr)+query((2*u)+1, med+1, r, ql, qr));
}

void update(int u, int l, int r, int ql, int qr, int val){
    unlazy(u, l, r);
    if(ql>r || qr<l) return;
    if(ql<=l && qr>=r){
        lazy[0][u] += val;
        lazy[1][u] ++;
        unlazy(u, l, r);
        return;
    }
    int med = (l+r)/2;
    update(2*u, l, med, max(ql, l), qr, val+max(l-ql, 0));
    update((2*u)+1, med+1, r, max(ql, med+1), qr, val+max(med+1-ql, 0));
    seg[u] = seg[2*u]+seg[(2*u)+1];
}

int main(){
    ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q, i, a, b, c;
    cin >> n >> q;
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    build(1, 0, n-1);
    for(i=0;i<q;i++){
        cin >> c >> a >> b; a--;b--;
        if(c==1) update(1, 0, n-1, a, b, 1);
        else cout << query(1, 0, n-1, a, b) << endl;
    }
    return (0);
}
