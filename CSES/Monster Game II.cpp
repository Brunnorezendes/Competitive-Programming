#include <bits/stdc++.h>
#define maxn 200003
#define maxa 1000000
#define f first
#define s second
#define inf 0x3f3f3f3f

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

ll n, p, s[maxn], f[maxn], dp[maxn];

ii line[4*maxa];

ll C(ii r, ll x){
	return ((r.f*x)+r.s);
}

void addLine(int id, int l, int r, ii nl){
	int m = (l + r)/2;
	bool f1 = C(nl, l) < C(line[id], l);
	bool f2 = C(nl, m) < C(line[id], m);
	if(f2) swap(line[id], nl);
	if(l + 1 == r)return;
	if(f1 != f2)addLine(id * 2, l, m, nl);
	else addLine(id * 2 + 1, m, r, nl);
}

ll getY(int id, int l, int r, int x){
	if(l + 1 == r)return C(line[id], x);
	int m = (l + r)/2;
	if(x < m) return min(C(line[id], x), getY(id * 2, l, m, x));
	return min(C(line[id], x), getY((id * 2)+1, m, r, x));
}

int main(){
	int i;
	cin >> n >> p;
	for(i=0;i<n;i++){
		cin >> s[i];
	}
	for(i=0;i<n;i++){
		cin >> f[i];
	}
	for(i=0;i<=4*maxa;i++) line[i] = {p, 0};
	for(i=0;i<n;i++){
		dp[i] = getY(1, 0, maxa, s[i]);
		addLine(1, 0, maxa, {f[i], dp[i]});
	}
	cout << dp[n-1] << endl;
	return (0);
}
