#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define maxl 19

using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef long double ld;
typedef vector<ld> vld;
typedef pair<ii,int> iii;

ll end0[maxl], noend0[maxl];

void precompute(){
    end0[0] = 1;
    noend0[0] = 9;
    for(int i=1;i<maxl;i++){
        end0[i] = noend0[i-1];
        noend0[i] = 8*noend0[i-1] + 9*end0[i-1];
    }
}

ll find(ll x){
    int ind=0, i, last=0, digit;
    ll pot=10, resp=0;
    while(x/pot){
        ind++;
        pot*=10;
    }
    for(i=0;i<ind;i++){
        resp += noend0[i];
    }
    pot/=10;
    for(;ind>=0;ind--){
        digit = x/pot;
        //cout << x << " " << digit << endl;
        x %= pot;
        pot /= 10;
        for(i=0;i<digit;i++){
            if(i==last) continue;
            resp += end0[ind];
        }
        if(digit==last) break;
        if(!ind) break;
        last = digit;
    }
    if(digit!=last) resp++;
    return resp;
}

int main(){
    ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll a, b;
    precompute();
    cin >> a >> b;
    if(!a) cout << find(b)+1 << endl;
    else cout << find(b) - find(a-1) << endl;
    return (0);
}