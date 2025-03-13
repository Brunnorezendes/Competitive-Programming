#include <bits/stdc++.h>
#define fastio  ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb push_back

using namespace std;
typedef vector<int> vi;
typedef long long int ll;
const int NMAX = 1e5 + 10;
const int PMAX = 1e4;
const int T    = 320;
int lp [NMAX];
vi primes;
map <int,int> iip;

int chunck_aux [PMAX] [T];
int chunck_ans [PMAX] [T];
void precalc() {
    for (int i = 2; i < NMAX; i++) {
        if (lp[i] == 0) {
            primes.pb(i);
            iip[i] = primes.size() - 1;
            for (int j = i; j < NMAX; j+=i) {
                lp[j]= i;
            }
        }
    }

    for (int i = 2; i < NMAX; i++) {
        chunck_aux [iip[lp[i]]][i/T]++;
    }
    for (int i = 0; i < T; i++) {
        for (int j = PMAX-3; j >= 0; j--)
            chunck_ans[j][i] = chunck_ans[j+1][i] + chunck_aux[j][i];
    }

    //for (int i = 0; i < 300; i++) {
    //    cout << primes[i] << ": " <<chunck_ans[i][0] << endl;
    //}
}

void solve () {
    int n, k;
    cin >> n >> k;
    auto kl = lower_bound(primes.begin(), primes.end(), k + 1);
    if (kl == primes.end()) {
        cout << n << endl;
        return;
    }

    k = *kl;
    int indk = iip[k];
    int ans = 0;
    int i;
    for (i = 0; (i+1)*T < n; i++) {
        ans += T - chunck_ans[indk][i];
    }
    //cout << " " << k << " " << indk << " " << ans << endl;
    for (int j = 0; (i)*T + j <= n; j++) {
        ans += lp[(i)*T + j] < k;
    }
    ans-= 2;
    cout << ans << endl;
}

int main(){
    fastio;
    precalc();
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return (0);
}