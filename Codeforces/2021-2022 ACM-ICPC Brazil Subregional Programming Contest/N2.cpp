#include <bits/stdc++.h>
#define pb push_back
#define maxn 300009
#define maxa 100003
#define raiz 550

using namespace std;
typedef vector<int> vi;
typedef long long int ll;

int alt[maxn], resp[maxn], seg[4*maxa];

struct query{
    int l, r, ind, val;
    bool operator<(query q){
        if((l/raiz)!=(q.l/raiz)) return l<q.l;
        if(r!=q.r) return r<q.r;
        return l<q.l;
    }
};

typedef struct query sq;

typedef vector <sq> vq;
vq g;

void update(int u, int l, int r, int pos, int val){
    seg[u] += val;
    if(l==r) return;
    int med = (l+r)/2;
    if(pos<=med) update(2*u, l, med, pos, val);
    else update((2*u)+1, med+1, r, pos, val);
}

int busca(int u, int l, int r, int pos){
    if(l==r) return seg[u];
    int med = (l+r)/2;
    if(pos<=med) return (seg[(2*u)+1]+busca(2*u, l, med, pos));
    else return busca((2*u)+1, med+1, r, pos);
}

int main(){
    ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int y, n, i, a, p, f, ini, fim;
    sq u;
    cin >> y >> n;
    for(i=0;i<y;i++)
        cin >> alt[i];
    for(i=0;i<n;i++){
        cin >> a >> p >> f; a--;
        if(!f || p<=alt[a]) resp[i] = 0;
        else{
            u.l = a+1;
            u.r = a+f;
            u.ind = i;
            u.val = p;
            g.push_back(u);
        }
    }
    sort(g.begin(), g.end());
    ini = 0;
    fim = -1;
    for(i=0;i<g.size();i++){
        while(fim<g[i].r) update(1, 0, maxa, alt[++fim], 1);
        while(ini>g[i].l) update(1, 0, maxa, alt[--ini], 1);
        while(fim>g[i].r) update(1, 0, maxa, alt[fim--], -1);
        while(ini<g[i].l) update(1, 0, maxa, alt[ini++], -1);
        resp[g[i].ind] = busca(1, 0, maxa, g[i].val);
    }
    for(i=0;i<n;i++){
        cout << resp[i] << endl;
    }
    return (0);
}