#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define maxn 
#define inf 200000

using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef long double ld;
typedef vector<ld> vld;
typedef pair<ii,int> iii;


#define MAXN 100100
#define MAXLOG 21

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k] && s[i+k]!='$')
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}


int main(){
    ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m, i, resp=inf;
    vi p, lcp, rank;
    string s, a;
    cin >> n >> m;
    cin >> s;
    s += s;
    s += "$";
    for(i=0;i<m;i++){
        cin >> a;
        s += a;
        s += "$";
    }
    cout << s << endl;
    p = sort_cyclic_shifts(s);
    lcp = lcp_construction(s, p);
    rank.resize(p.size());
    for(i=0;i<p.size();i++){
        rank[p[i]] = i;
        cout << p[i] << " " << lcp[i] << endl;
    }
    for(i=p.size()-3;i>=0;i--){
        if(p[i]<(2*n) && p[i+1]<(2*n)) lcp[i] = min(lcp[i], lcp[i+1]);
    }
    for(i=0;i<n;i++){
        resp = min(resp, max(lcp[rank[i]], lcp[rank[i]-1]));
    }
    cout << resp << endl;
    return (0);
}