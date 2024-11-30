#include <bits/stdc++.h>
#define maxn 100000

using namespace std;

vector <int> g[2*maxn], h[2*maxn];
stack <int> s;

int vis[2*maxn], var[2*maxn], tim=1, entry[2*maxn], cont=0, comp[2*maxn], chose[2*maxn];

void tarjan(int u){
	int ne, v;
	entry[u]=tim;
	var[u]=tim++;
	vis[u]=1;
	s.push(u);
	for(int i=0;i<g[u].size();i++){
		v = g[u][i];
		if(!vis[v]) tarjan(v);
		if(vis[v]==1) var[u] = min(var[v], var[u]);
	}
	if(var[u]>=entry[u]){
		ne=-1;
		while(ne!=u){
			ne = s.top();
			s.pop();
			comp[ne]=cont;
			vis[ne]=2;
		}
		cont++;
	}
}


int main(){
	int n, m, i, a, b, in1, nin1, in2, nin2, j, flag=0;
	char c, d;
	cin >> n >> m;
	for(i=0;i<n;i++){
		cin >> c >> a >> d >> b;
		a--;b--;
		in1 = a;
		nin1 = m+a;
		if(c=='-') swap(in1, nin1);
		in2 = b;
		nin2 = m+b;
		if(d=='-') swap(in2, nin2);
		g[nin1].push_back(in2);
		g[nin2].push_back(in1);
	}
	for(i=0;i<2*m;i++){
		if(!vis[i]) tarjan(i);
	}
	for(i=0;i<m;i++){
		if(comp[i]==comp[m+i]){
			flag = 1; break;
		}
	}
	if(flag) cout << "IMPOSSIBLE";
	else{
		for(i=0;i<m;i++){
			if(chose[comp[i]]) chose[comp[i+m]] = -chose[comp[i]];
			else if(chose[comp[i+m]]) chose[comp[i]] = -chose[comp[i+m]];
			else{
				if(comp[i]<comp[i+m]){
					chose[comp[i]]=1;
					chose[comp[i+m]]=-1;
				}
				else{
					chose[comp[i]]=-1;
					chose[comp[i+m]]=1;
				}
			}
		}
		for(i=0;i<m;i++){
			if(chose[comp[i]]==1) cout << "+";
			else cout << "-";
		}
	}
	return (0);
}
