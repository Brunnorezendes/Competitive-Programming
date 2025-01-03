#include <bits/stdc++.h>
#define f first
#define s second
#define maxn 200005

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> iii;

int bit1[maxn], bit2[maxn], resp1[maxn], resp2[maxn], cont=1;

vector <int> g;

map <int,int> mp;

vector <iii> s;

ii v[maxn];

void add1(int x, int v){
	while(x<cont){
		bit1[x]+=v;
		x += x&(-x);
	}
}

void add2(int x, int v){
	while(x<cont){
		bit2[x]+=v;
		x += x&(-x);
	}
}

int query1(int x){
	int resp=0;
	while(x>0){
		resp += bit1[x];
		x -= x&(-x);
	}
	return resp;
}

int query2(int x){
	int resp=0;
	while(x>0){
		resp += bit2[x];
		x -= x&(-x);
	}
	return resp;
}

int main(){
	ios::sync_with_stdio(0);
	pair<int, int> t[maxn];
	int i, n;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> t[i].f >> t[i].s;
		g.push_back(t[i].f);
		g.push_back(t[i].s);
	}
	sort(g.begin(), g.end());
	for(i=0;i<g.size();i++){
		if(!mp[g[i]]) mp[g[i]] = cont++;
	}
	for(i=0;i<n;i++){
		v[i].f = mp[t[i].f];
		v[i].s = mp[t[i].s];
		s.push_back({{v[i].f, 0}, {v[i].s, i}});
		s.push_back({{v[i].s, 1}, {-v[i].f, i}});
	}
	sort(s.begin(), s.end());
	for(auto a: s){
		if(!a.f.s){
			add1(a.f.f, 1);
		}
		else{
			add1(v[a.s.s].f, -1);
			resp1[a.s.s] = query1(v[a.s.s].f);
			resp2[a.s.s] += query2(a.f.f);
			resp2[a.s.s] -= query2(v[a.s.s].f-1);
			add2(v[a.s.s].f, 1);
		}
	}
	for(i=0;i<n;i++){
		cout << resp2[i] << " ";
	}
	cout << endl;
	for(i=0;i<n;i++){
		cout << resp1[i] << " ";
	}
	return (0);
}
