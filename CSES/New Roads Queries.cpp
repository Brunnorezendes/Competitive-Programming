#include <bits/stdc++.h>
#define maxn 200001
#define f first
#define s second
 
using namespace std;
 
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
 
vii upd, que;
int p[maxn], sz[maxn];
 
int find(int a){
	if(p[a]==a) return a;
	else{
		p[a] = find(p[a]);
		return p[a];
	}
}
 
void merge(ii c){
	int a = c.f, b = c.s;
	a = find(a);
	b = find(b);
	if(sz[a]>sz[b]){
		p[b]=a;
		sz[a] += sz[b];
	}
	else{
		p[a]=b;
		sz[b]+=sz[a];
	}
}
 
int main(){
	int i, n, m, q, a, b, j, mid, left[maxn], right[maxn];
	cin >> n >> m >> q;
	for(i=0;i<m;i++){
		cin >> a >> b;
		a--;b--;
		if(a>b) swap(a, b);
		upd.push_back({a, b});
	}
	for(i=0;i<q;i++){
		cin >> a >> b;
		a--;b--;
		if(a>b) swap(a, b);
		que.push_back({a, b});
		left[i]=0;
		right[i]=m-1;
	}
	for(i=1;i/2<=m;i*=2){
		vvi event(m);
		for(j=0;j<n;j++){
			sz[j]=1;
			p[j]=j;
		}
		for(j=0;j<q;j++){
			if(right[j]==left[j]) continue;
			mid = (left[j]+right[j])/2;
			event[mid].push_back(j);
		}
		for(j=0;j<m;j++){
			merge(upd[j]);
			for(auto x: event[j]){
				if(find(que[x].f)==find(que[x].s)){
					right[x] = j;
				}
				else left[x] = j+1;
			}
		}
	}
	for(j=0;j<n;j++){
		sz[j]=1;
		p[j]=j;
	}
	for(i=0;i<m;i++){
		merge(upd[i]);
	}
	for(i=0;i<q;i++){
		if(que[i].f==que[i].s){
			cout << "0\n";
			continue;
		}
		if(left[i]==m-1){
			if(find(que[i].f)==find(que[i].s)) cout << left[i]+1;
			else cout << "-1";
		}
		else cout << left[i]+1;
		cout << endl;
	}
	return (0);
}
