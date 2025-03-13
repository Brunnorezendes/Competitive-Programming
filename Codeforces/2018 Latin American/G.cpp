#include <bits/stdc++.h>
#define f first
#define s second
#define mod 1000000007
#define maxn 1003

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long int ll;

ll fat[maxn];
vii g;
ii v[maxn];
int grau[maxn], num[maxn];

int main(){
    int i, n, j;
    ll resp = 1;
    cin >> n;
    fat[0] = 1;
    for(i=1;i<=n;i++){
        fat[i] = (fat[i-1]*i)%mod;
    }
    for(i=0;i<n;i++)
        cin >> v[i].f >> v[i].s;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)continue;
            if((v[i].f<=v[j].f && v[i].s<v[j].s) || (v[i].f<v[j].f && v[i].s<=v[j].s)) grau[i]++;
        }
        num[grau[i]]++;
    }
    for(i=0;i<n;i++){
        resp = (resp*fat[num[i]])%mod;
    }
    cout << resp << endl;
    return (0);
}