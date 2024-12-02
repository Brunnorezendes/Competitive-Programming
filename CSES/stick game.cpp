#include <bits/stdc++.h>
#define maxn 1000002

using namespace std;

typedef vector <int> vi;

vi moves;

int n, k, dp[maxn];

int main(){
	int i, a, flag, j;
	cin >> n >> k;
	for(i=0;i<k;i++){
		cin >> a;
		moves.push_back(a);
	}
	sort(moves.begin(), moves.end());
	for(i=1;i<=n;i++){
		flag=0;
		for(j=0;j<k && moves[j]<=i;j++){
			if(!dp[i-moves[j]]) flag=1;
		}
		if(flag) dp[i] = 1;
		if(dp[i]) cout << "W";
		else cout << "L";
	}
	return (0);
}
