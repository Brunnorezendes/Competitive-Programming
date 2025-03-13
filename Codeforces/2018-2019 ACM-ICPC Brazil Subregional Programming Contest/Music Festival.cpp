#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define vi vector<int>
#define pb push_back
#define ii pair<int,int>
#define ff first
#define ss second
using namespace std;
const int NMAX = 4e3;
unordered_map <int,int> encode, decode;
vector<pair<ii, ii>> shows_base;
vector<pair<ii,int>> shows[NMAX];
int dp [NMAX][NMAX];
int viz [NMAX][NMAX];
int n, m;
int main () {
    fastio;
    int a, b, c;

    cin >> n;
    vi to_encode;
    for (int i = 0 ; i < n; i++) {
        cin >> m;
        for (int j = 0 ; j < m; j++) {
            cin >> a >> b >> c;
            shows_base.pb({{a,b},{c,i}});
            
            to_encode.pb(a);
            to_encode.pb(b);
        }
    }

    sort(to_encode.begin(), to_encode.end());
    int cnt = 0;
    for (int i : to_encode) {
        if (!encode[i]) {
            encode[i]   = ++cnt;
            decode[cnt] = i;
        }
    }

    for (int i = 0 ; i < shows_base.size() ; i ++) {
        shows_base[i] = {{encode[shows_base[i].ff.ff], encode[shows_base[i].ff.ss]}, shows_base[i].ss};
        shows[shows_base[i].ff.ff].pb({{shows_base[i].ff.ss, shows_base[i].ss.ff}, shows_base[i].ss.ss});
    }
    sort(shows_base.begin(), shows_base.end());

    for (int i = 0 ; i < NMAX ; i ++) {
        for (int j = 0; j < NMAX; j++) {
            dp[i][j] = -1;
        }
    }
    priority_queue <pair<ii,int>> tp;
    tp.push({{-1,0},0});
    dp[1][0] = 0;
    while (!tp.empty()) {
        auto el = tp.top();   tp.pop();

        int t   = -el.ff.ff;
        int j   = -el.ff.ss;
        int val = el.ss;
        if (viz[t][j]) continue;
        viz[t][j] = 1;
        if (dp [t][j] > val || t > encode.size()) continue;

        dp[t+1][j] = max(dp[t+1][j], dp[t][j]);
        tp.push({{-(t+1),-j}, dp[t+1][j]});

        // cout << "Processing " << t << ' ' << j << ' ' << val << endl;
        for (auto sw : shows[t]) {
            int j_ = j|(1<<sw.ss);
            dp[sw.ff.ff][j_] = max(dp[sw.ff.ff][j_], val+sw.ff.ss);
            tp.push({{-sw.ff.ff, -j_}, dp[sw.ff.ff][j_]});
            // cout << "Adding " << sw.ff.ff << ' ' << j_ << ' ' << val + dp[sw.ff.ff][j_] << endl;
        }
    }

    int ans = -1;
    for (int i = 1; i <= encode.size(); i++) {
        ans = max(dp[i][((1 << n) - 1)], ans);
    }
    cout << ans << endl;
    return 0;
}