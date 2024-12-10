#include <bits/stdc++.h>
#define maxn 5000
#define INF 5e13+1

using namespace std;

typedef long long int ll;

ll pre[maxn], dp[maxn][maxn], po[maxn][maxn];

ll C(ll a, ll b){
	if(a) return (pre[b]-pre[a-1]);
	else return pre[b];
}

int main(){
	ll i, n, j, k, w, sum;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> pre[i];
		if(i) pre[i]+=pre[i-1];
		dp[i][i]=0;
		po[i][i]=i;
	}
	for(k=1;k<n;k++){
		for(i=0;i<n-k;i++){
			j = i+k;
			dp[i][j] = INF;
			for(w=po[i][j-1];w<=po[i+1][j];w++){
				sum = 0;
				if(w>i) sum += dp[i][w-1];
				if(w<j) sum += dp[w][j];
				sum += C(i, j);
				if(sum < dp[i][j]){
					dp[i][j] = sum;
					po[i][j] = w;
				}
			}
		}
	}
	cout << dp[0][n-1] << endl;
	return (0);
}
