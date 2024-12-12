#include <bits/stdc++.h>
#define maxn 100001
#define s second
#define f first

using namespace std;

vector <int> v[maxn];
vector <pair<int, int> > p;

int resp, tim, var[maxn], q[maxn], pai[maxn];

void tarjan(int u){
	var[u] = ++tim;
	q[u] = tim;
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]!=pai[u]){
			if(!q[v[u][i]]){
				pai[v[u][i]]=u;
				tarjan(v[u][i]);
				if(q[u]<var[v[u][i]]){
					resp++;
					p.push_back({u+1, v[u][i]+1});
				}
			}
			var[u] = min(var[u], var[v[u][i]]);
		}
	}
}

int main(){
	int n, m, a, b, i;
	cin >> n >> m;
	for(i=0;i<m;i++){
		cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	pai[0]=-1;
	tarjan(0);
	cout << resp << "\n";
	for(i=0;i<p.size();i++){
		cout << p[i].f << " " << p[i].s << endl;
	}
	return (0);
}
