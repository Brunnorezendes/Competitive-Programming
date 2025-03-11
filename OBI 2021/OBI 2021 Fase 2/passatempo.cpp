#include <bits/stdc++.h>
#define maxn 200

using namespace std;

typedef long long int ll;

string g[maxn];
vector <string> ord;
map <string, ll> mp;
map <ll, ll> qt[2*maxn];
set <ll> element[2*maxn];

ll v[maxn][maxn], val[maxn], eq[2*maxn];

int main(){
	ll i, cont=0, l, c, j, a, n;
	string s;
	cin >> l >> c;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			cin >> s;
			if(!mp[s]){
				mp[s] = ++cont;
				g[cont] = s;
				val[cont]=-1;
			}
			v[i][j] = mp[s];
			qt[i][mp[s]]++;
			element[i].insert(mp[s]);
			qt[l+j][mp[s]]++;
			element[l+j].insert(mp[s]);
		}
		cin >> eq[i];
	}
	for(i=0;i<c;i++){
		cin >> eq[l+i];
	}
	n = cont;
	while(cont){
		for(i=0;i<l+c;i++){
			if(element[i].size()==1){
				a = *element[i].begin();
				val[a] = (eq[i]/qt[i][a]);
				break;
			}
		}
		cont--;
		for(i=0;i<l+c;i++){
			if(element[i].count(a)){
				element[i].erase(a);
				eq[i] -= val[a]*qt[i][a];
			}
		}
	}
	for(i=1;i<=n;i++){
		ord.push_back(g[i]);
	}
	sort(ord.begin(), ord.end());
	for(i=0;i<n;i++){
		cout << ord[i] << " " << val[mp[ord[i]]] << endl;
	}
	return (0);
}
