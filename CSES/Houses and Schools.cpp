#include <bits/stdc++.h>
#define maxn 3001
#define inf 9000000000000001

using namespace std;

typedef long long int ll;
typedef vector <ll> vi;

ll c[maxn][maxn], pref[maxn];

vi new_dp, old_dp;

void precomp(vi t){
	int i, j, opt, n=t.size();
	ll sum;
	for(i=0;i<n;i++){
		opt=i;
		sum=0;
		for(j=i;j<n;j++){
			sum+=t[j]*(j-opt);
			while(opt<j && sum>(sum+pref[opt+1]-pref[i]+pref[opt+1]-pref[j+1])){
				sum=(sum+pref[opt+1]-pref[i]+pref[opt+1]-pref[j+1]);
				opt++;
			}
			c[i][j] = sum;
		}
	}
}

ll C(int l, int r){
	if(l>r) return 0;
	return c[l][r];
}

void divide_conquer(int l, int r, int optl, int optr){
	if(l>r) return;
	int mid = (l+r)/2;
	int opt;
	new_dp[mid] = inf;
	for(int k=optl;k<=min(mid, optr);k++){
		if(old_dp[k] + C(k+1, mid)<new_dp[mid]){
			new_dp[mid] = old_dp[k] + C(k+1, mid);
			opt = k;
		}
	}
	divide_conquer(l, mid-1, optl, opt);
	divide_conquer(mid+1, r, opt, optr);
}

void solve(int k, int n){
	for(int i=0;i<k;i++){
		divide_conquer(0, n-1, 0, n-1);
		old_dp=new_dp;
	}
}

int main(){
	int n, i, k;
	vi v;
	cin >> n >> k;
	old_dp = vi(n);
	new_dp = vi(n);
	for(i=1;i<=n;i++){
		cin >> pref[i];
		v.push_back(pref[i]);
		pref[i]+=pref[i-1];
	}
	precomp(v);
	for(i=0;i<n;i++){
		old_dp[i]=C(0, i);
	}
	solve(k-1, n);
	cout << old_dp[n-1] << endl;
	return (0);
}
