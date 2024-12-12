#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define maxn 

using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef long double ld;
typedef vector<ld> vld;
typedef pair<ii,int> iii;

const int MAX = 200010, UPD = 200001, LOG = 18;
const int MAXS = 4*MAX + UPD*LOG;

int val[MAX];

struct segTree{
    ll seg[MAXS];
    int L[MAXS], R[MAXS], cnt = 0;
    int n;
    segTree(int n_){
        n = n_;
        build(cnt++, 0, n-1);
    }
    ll build(int r, int ss, int se) {
        if (ss == se) return seg[r] = val[ss];
        L[r] = cnt++, R[r] = cnt++;
        int m = (ss+se)/2;
        return seg[r] = build(L[r], ss, m) + build(R[r], m+1, se);
    }
    ll query(int r, int ss, int se, int qs, int qe) {
        if (qe < ss || se < qs) return 0;
        if (qs <= ss && se <= qe) return seg[r];
        int m = (ss+se)/2;
        return query(L[r], ss, m, qs, qe) + query(R[r], m + 1, se, qs, qe);
    }
    ll query(int r, int qs, int qe) {
        return query(r, 0, n-1, qs, qe);
    }
    void update(int nr, int r, int ss, int se, int pos, ll v) {
        if(ss == se){
            seg[nr] = v;
            return;
        }
        int m = (ss+se)/2;
        L[nr] = L[r];
        R[nr] = R[r];
        if(pos <= m)
            update(L[nr] = cnt++, L[r], ss, m, pos, v);
        else
            update(R[nr] = cnt++, R[r], m+1, se, pos, v);
        seg[nr] = seg[L[nr]] + seg[R[nr]];
    }
    int update(int r, int pos, ll v){
        int idx = cnt++;
        update(idx, r, 0, n-1, pos, v);
        return idx;
    }
};

int lista[MAX];

int main(){
    ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q, k=1, i, a, b, c, d;
    ll x;
    cin >> n >> q;
    for(i=0;i<n;i++) cin >> val[i];
    struct segTree poq(n);
    for(i=0;i<q;i++){
        cin >> a >> b;b--;
        if(a==3)
            lista[k++] = lista[b];
        else if(a==2){
            cin >> c >> d;c--;d--;
            cout << poq.query(lista[b], c, d) << endl;
        }
        else if(a==1){
            cin >> c >> x;c--;
            lista[b] = poq.update(lista[b], c, x);
        }
    }
    return (0);
}
