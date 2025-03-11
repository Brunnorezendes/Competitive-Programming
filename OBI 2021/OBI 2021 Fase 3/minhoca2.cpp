#include <bits/stdc++.h>
#define maxn 50002
#define f first
#define s second

using namespace std;

vector <int> v[maxn];
pair<int,int> a;

int d[maxn], best=0, qtd=0;

pair<int, int> dfs(int u, int pai){
	vector <pair<int, int> > g;
	int ini, fim, sum=0, tot=0, ini2, fim2;
	if(pai>=0) d[u] = d[pai]+1;
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]!=pai){
			g.push_back(dfs(v[u][i], u));
		}
	}
	if(g.empty()){
		a.f = d[u];
		a.s = 1;
		return (a);
	}
	sort(g.begin(), g.end());
	fim = g.size()-1;
	for(ini=fim;(ini>0)&&(g[ini-1].f==g[ini].f);ini--){}
	if(ini==fim){
		if(fim>0){
			for(ini2=fim-1, fim2=fim-1;(ini2>0)&&(g[ini2-1].f==g[ini2].f);ini2--){}
			for(int i=ini2;i<=fim2;i++){
				sum+=g[i].s;
			}
			if((g[fim-1].f+g[fim].f+1-d[u]-d[u])==best) qtd+=(sum*g[fim].s);
			else if((g[fim-1].f+g[fim].f+1-d[u]-d[u])>best){
				best = g[fim-1].f+g[fim].f+1-d[u]-d[u];
				qtd = (sum*g[fim].s);
			}
		}
		if((g[fim].f+1-d[u])==best) qtd+=g[fim].s;
		else if((g[fim].f+1-d[u])>best){
			best = g[fim].f+1-d[u];
			qtd = g[fim].s;
		}
		return g[fim];
	}
	else{
		for(int i=ini;i<=fim;i++){
			sum+=g[i].s;
		}
		for(int i=ini;i<=fim;i++){
			tot += (sum-g[i].s)*g[i].s;
		}
		tot/=2;
		if((g[fim].f+g[fim].f+1-d[u]-d[u])==best) qtd+=tot;
		else if((g[fim].f+g[fim].f+1-d[u]-d[u])>best){
			best = g[fim].f+g[fim].f+1-d[u]-d[u];
			qtd = tot;
		}
		if((g[fim].f+1-d[u])==best) qtd+=sum;
		else if((g[fim].f+1-d[u])>best){
			best = g[fim].f+1-d[u];
			qtd = sum;
		}
		a.f = g[fim].f;
		a.s = sum;
		return (a);
	}
}

int main(){
	int n, i, a, b, j, x;
	cin >> n;
	for(i=0;i<n-1;i++){
		cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	d[0]=0;
	dfs(0, -1);
	cout << best << "\n" << qtd;
	return (0);
}
