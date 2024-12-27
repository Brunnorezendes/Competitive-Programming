#include <bits/stdc++.h>
#define f first
#define s second
#define maxn 1000001
#define mod 1000000007
 
using namespace std;
 
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<ii> sii;
typedef vector<int> vi;
typedef long long int ll;
 
int dsu[maxn], flag=0, opo[maxn], vis[maxn], p[maxn], sz[maxn];

vi seg[8*maxn];
vi v;
 
int find(int x){
	if(x == -1) return -1;
	if(dsu[x]==x) return x;
	else{
		dsu[x] = find(dsu[x]);
		return dsu[x];
	}
}
 
void merge(int a, int b){
	a = find(a);
	b = find(b);
	opo[b] = find(opo[b]);
	opo[a] = find(opo[a]);
	if(a == b) flag=1;
	else{
		if(opo[a]==-1 && opo[b]==-1){
			opo[a] = b;
			opo[b] = a;
		}
		else if(opo[a]==-1){
			if(sz[a]>sz[opo[b]]) swap(opo[b], a);
			dsu[a] = opo[b];
			sz[opo[b]] += sz[a];
		}
		else if(opo[b]==-1){
			if(sz[b]>sz[opo[a]]) swap(opo[a], b);
			dsu[b] = opo[a];
			sz[opo[a]] += sz[b];
		}
		else if(opo[a]!=b && opo[b]!=a){
			if(sz[opo[a]]>sz[b] && sz[a]>sz[opo[b]]){
				opo[opo[a]] = opo[b];
				swap(opo[a], b);
				opo[opo[a]] = a;
			}
			else if(sz[opo[a]]>sz[b] && sz[a]<sz[opo[b]]){
				swap(a, opo[b]);
				swap(b, opo[opo[b]]);
			}
			else if(sz[opo[a]]<sz[b] && sz[a]<sz[opo[b]]){
				opo[opo[b]] = opo[a];
				swap(opo[b], a);
				opo[opo[b]] = b;
			}
			dsu[opo[a]] = b;
			dsu[opo[b]] = a;
			sz[a] += sz[opo[b]];
			sz[b] += sz[opo[a]];
			opo[a] = b;
			opo[b] = a;
		}
	}
}

void update(int id, int l, int r, int val, int x){
	int mid = (l+r)/2;
	seg[id].push_back(x);
	if(l<r){
		if(val<=mid) update(2*id, l, mid, val, x);
		else update((2*id)+1, mid+1, r, val, x);
	}
}

void query(int id, int l, int r, int ql, int qr, int u){
	int mid = (l+r)/2;
	if(l>=ql && r<=qr){
		for(int i=0;i<seg[id].size();i++){
			if(flag) break;
			merge(u, seg[id][i]);
		}
	}
	else if((ql>=l && ql<=r) || (qr<=r && qr>=l)){
		query(2*id, l, mid, ql, qr, u);
		query((2*id)+1, mid+1, r, ql, qr, u);
	}
}
 
int main(){
	int n, i, a, mini;
	cin >> n;
	for(i=0;i<n;i++){
		scanf("%d", &a);
		v.push_back(a);
		dsu[i] = i;
		opo[i] = -1;
		sz[i] = 1;
	}
	mini = v[n-1];
	for(i=n-1;i>=0;i--){
		mini = min(mini, v[i]);
		p[i] = mini;
	}
	for(i=0;i<n;i++){
		query(1, 1, n, p[i], v[i], i);
		if(flag) break;
		update(1, 1, n, v[i], i);
	}
	if(flag) cout << "IMPOSSIBLE";
	else{
		for(i=0;i<n;i++){
			a = find(i);
			if(!vis[a]){
				vis[a] = 1;
				if(opo[a]!=-1) vis[opo[a]] = 2;
			}
			printf("%d ", vis[a]);
		}
	}
	return (0);
}
