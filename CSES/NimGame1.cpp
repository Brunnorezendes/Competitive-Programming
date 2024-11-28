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

int main(){
    ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t, i, n, a, resp;
    cin >> t;
    while(t--){
        cin >> n;
        resp = 0;
        for(i=0;i<n;i++){
            cin >> a;
            resp ^= a;
        }
        if(!resp) cout << "second\n";
        else cout << "first\n";
    }
    return (0);
}