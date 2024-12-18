#include <bits/stdc++.h>
#define maxn 100000

using namespace std;

typedef vector<long long int> vi;

vi v[maxn], coin, g[maxn];
stack <long long int> sta;
long long int component[maxn], dfslow[maxn], dfscont=0, vis[maxn], cont=0, resp[maxn], coincomp[maxn], conf[maxn];

void tarjan(int x){
	int in = dfslow[x] = dfscont++, i, next;
	vis[x] = 1;
	sta.push(x);
	for(i=0;i<v[x].size();i++){
		if(!vis[v[x][i]]) tarjan(v[x][i]);
		if(vis[v[x][i]]==1)dfslow[x] = min(dfslow[x], dfslow[v[x][i]]);
	}
	
	if(in==dfslow[x]){
		next = -1;
		while(next!=x){
			next = sta.top();
			sta.pop();
			component[next] = cont;
			coincomp[component[next]] += coin[next];
			vis[next] = 2;
		}
		cont++;
	}
}

void dfs(int u){
	long long int maxi=0;
	for(int i=0;i<g[u].size();i++){
		if(!resp[g[u][i]]) dfs(g[u][i]);
		maxi = max(maxi, resp[g[u][i]]);
	}
	resp[u] = coincomp[u] + maxi;
}

int main(){
	int n, m, i, a, b, j;
	long long int resposta=0;
	cin >> n >> m;
	for(i=0;i<n;i++){
		cin >> a;
		coin.push_back(a);
	}
	for(i=0;i<m;i++){
		cin >> a >> b;
		a--;b--;
		v[a].push_back(b);
	}
	for(i=0;i<n;i++){
		if(!vis[i]) tarjan(i);
	}
	for(i=0;i<n;i++){
		for(j=0;j<v[i].size();j++){
			if(component[i]!=component[v[i][j]]){
				g[component[i]].push_back(component[v[i][j]]);
				conf[component[v[i][j]]] = 1;
			}
		}
	}
	for(i=0;i<cont;i++){
		if(!conf[i]) dfs(i);
		resposta = max(resposta, resp[i]);
	}
	cout << resposta << endl;
	return (0);
}
