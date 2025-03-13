#include <bits/stdc++.h>
#define maxn 51

using namespace std;

typedef long long int ll;

ll v[maxn], escolhe[maxn][maxn];
bitset <maxn> bita, bitb;

ll choose(int n, int k){
    if(k>n || k<0) return 0;
    else return escolhe[n][k];
}

void precalc(){
    for(int i=0;i<maxn;i++){
        escolhe[i][0]=1;
        escolhe[i][i]=1;
    }
    for(int i=2;i<maxn;i++){
        for(int j=1;j<i;j++){
            escolhe[i][j] = escolhe[i-1][j] + escolhe[i-1][j-1];
        }
    }
}

int main(){
    int n, k, i, j, ma=-1, mb=-1, numa=0, numb=0;
    ll a, b, val, resp=0;
    cin >> n >> k;
    precalc();
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v, v+n);
    cin >> a >> b;
    for(i=n-1;i>=0;i--){
        if(a>=v[i]){
            ma = max(ma, i);
            a -= v[i];
            bita[i] = 1;
            numa++;
        }
        if(b>=v[i]){
            mb = max(mb, i);
            b -= v[i];
            bitb[i] = 1;
            numb++;
        }
    }
    if(a && numa==n){
        cout << 0 << endl;
        return 0;
    }
    for(i=ma;i<mb;i++){
        resp += choose(i, k-1);
    }
    if(numb==k) resp++;
    if(a && numa==k) resp--;
    for(i=0;i<mb;i++){
        if(bitb[i]){
            numb--;
            resp += choose(i, k-numb);
        }
    }
    for(i=0;i<ma;i++){
        if(bita[i]){
            numa--;
            resp -= choose(i, k-numa);
        }
    }
    cout << resp << endl;
    return (0);
}