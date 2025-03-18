#include <bits/stdc++.h>
#define vi vector<ll>
#define pb push_back
#define ii pair<int,int>
#define f first
#define s second
typedef long long ll;
using namespace std;
const ll mx = 1e15+100;
vi fb;
void precalc() {
    fb.pb(1), fb.pb(1);
    for (int i = 2; fb[i-1] < mx; i++) {
        fb.pb(fb[i-1] + fb[i-2]);
    }
}

string calc(ll n, int at){
    int i;
    string s, tp;
    if(n==1) return "";
    for (i = at; i >= 2; i--) {
        if (n%fb[i]) continue;
        s = calc(n/fb[i], i);
        if(s[0] == 'I') continue;
        for (int j = 1; j < i; j++)
            // cout << 'A' << endl;
            tp.pb('A');
        tp.pb('B');
        // cout << 'B' << endl;
        break;
    }
    if(!tp.size()) return "IMPOSSIBLE";
    else return tp+s;
}

void solve () {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 'B' << endl;
        return;
    }
    cout << calc(n, fb.size()-1) << endl;
}

int main () {
    int nt = 1;
    precalc();
    while (nt--)
        solve();
    return 0;
}