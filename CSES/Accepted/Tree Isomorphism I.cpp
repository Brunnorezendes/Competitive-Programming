#include <bits/stdc++.h>
#define maxn 100004

using namespace std;

typedef vector<int> vi;

map <vi, int> mp;

vi v[maxn], c[2];

int cont=1;

void dfs(int u, int k, int p){
	vi resp;
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]!=p){
			dfs(v[u][i], k, u);
			resp.push_back(c[k][v[u][i]]);
		}
	}
	sort(resp.begin(), resp.end());
	if(!mp[resp]) mp[resp] = cont++;
	c[k][u] = mp[resp];
}

int main(){
	int t, i, n, a, b;
	cin >> t;
	while(t--){
		cin >> n;
		for(i=0;i<n-1;i++){
			cin >> a >> b;
			a--;b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		c[0] = vi(n);
		dfs(0, 0, 0);
		for(i=0;i<n;i++) v[i].clear();
		for(i=0;i<n-1;i++){
			cin >> a >> b;
			a--;b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		c[1] = vi(n);
		dfs(0, 1, 0);
		if(c[1][0]==c[0][0]) cout << "YES\n";
		else cout << "NO\n";
		for(i=0;i<n;i++) v[i].clear();
		c[0].clear();
		c[1].clear();
	}
	return (0);
}
