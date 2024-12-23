#include <bits/stdc++.h>
#define maxn 3001

using namespace std;

typedef long long int ll;

vector <ll> old_dp, new_dp;

ll pref[maxn];

ll C(int l, int r){
	if(l>r) return 0;
	if(l) return ((pref[r]-pref[l-1])*(pref[r]-pref[l-1]));
	else return (pref[r]*pref[r]);
}

void divide_conquer(int l, int r, int optl, int optr){
	int mid = (l+r)/2, opt, flag=0;
	ll v;
	if(l>r) return;
	for(int k=optl;k<=min(optr, mid);k++){
		if(!flag){
			new_dp[mid] = old_dp[k] + C(k+1, mid);
			opt=k;
			flag=1;
		}
		else{
			v = old_dp[k] + C(k+1, mid);
			if(v<new_dp[mid]){
				new_dp[mid]=v;
				opt=k;
			}
		}
	}
	divide_conquer(l, mid-1, optl, opt);
	divide_conquer(mid+1, r, opt, optr);
}

void solve(int n, int k){
	int i;
	for(i=0;i<k-1;i++){
		divide_conquer(0, n-1, 0, n-1);
		old_dp = new_dp;
	}
}

int main(){
	int n, i, k;
	cin >> n >> k;
	old_dp = vector<ll> (n);
	new_dp = vector<ll> (n);
	for(i=0;i<n;i++){
		cin >> pref[i];
		if(i) pref[i]+=pref[i-1];
	}
	for(i=0;i<n;i++) old_dp[i] = C(0, i);
	solve(n, k);
	cout << old_dp[n-1] << endl;
	return (0);
}
