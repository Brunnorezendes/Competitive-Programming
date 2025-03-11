#include <bits/stdc++.h>
#define maxn 50002
#define maxl 16

using namespace std;

vector <int> v[maxn], leaf;

int p[maxn][maxl], d[maxn];

void dfs(int u, int pai){
	int flag=0;
	p[u][0]=pai;
	if(pai>=0) d[u] = d[pai]+1;
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]!=pai){
			dfs(v[u][i], u);
			flag=1;
		}
	}
	if(!flag) leaf.push_back(u);
}

void precompute(int n){
	int i, j;
	for(i=1;i<n;i++){
		for(j=1;j<maxl;j++){
			p[i][j] = p[p[i][j-1]][j-1];
		}
	}
}

int lca(int a, int b){
	if(!a || !b) return 0;
	if(d[b]>d[a]) swap(a, b);
	for(int i=maxl-1;i>=0;i--){
		if(d[p[a][i]]>=d[b]){
			a = p[a][i];
		}
	}
	for(int i=maxl-1;i>=0;i--){
		if(p[a][i]!=p[b][i]){
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

int main(){
	int n, i, a, b, j, x, best=0, qtd=0;
	cin >> n;
	for(i=0;i<n-1;i++){
		cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	d[0]=0;
	leaf.push_back(0);
	dfs(0, -1);
	precompute(n);
	for(i=0;i<leaf.size()-1;i++){
		for(j=i+1;j<leaf.size();j++){
			a = leaf[i];
			b = leaf[j];
			x = lca(a, b);
			if((d[a]+d[b]+1-d[x]-d[x])==best) qtd++;
			else if((d[a]+d[b]+1-d[x]-d[x])>best){
				best = d[a]+d[b]+1-d[x]-d[x];
				qtd = 1;
			}
		}
	}
	cout << best << "\n" << qtd;
	return (0);
}
