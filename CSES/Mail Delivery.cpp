#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

struct edge{
	int a;
	list<edge>::iterator rev;
	edge(int a): a(a){}
};

vector <int> resp;
list <edge> v[maxn];

int grau[maxn], flag=0, tot=0;

void dfs(int u){
	if(grau[u]%2) flag=1;
	else{
		while(!v[u].empty()){
			list<edge>::iterator it = v[u].begin();
			int x = it->a;
			tot++;
			v[x].erase(it->rev);
			v[u].erase(it);
			dfs(x);
		}
		resp.push_back(u+1);
	}
}

int main(){
	int a, n, b, m, i;
	list <edge>::iterator it1, it2;
	cin >> n >> m;
	for(i=0;i<m;i++){
		cin >> a >> b;
		a--;b--;
		v[a].emplace_front(b);
		v[b].emplace_front(a);
		it1 = v[a].begin();
		it2 = v[b].begin();
		it1->rev = it2;
		it2->rev = it1;
		grau[a]++;grau[b]++;
	}
	dfs(0);
	if(flag || tot<m) cout << "IMPOSSIBLE" << endl;
	else{
		for(i=0;i<resp.size();i++){
			cout << resp[i] << " ";
		}
		cout << endl;
	}
	return (0);
}
