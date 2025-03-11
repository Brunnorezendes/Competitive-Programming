#include <bits/stdc++.h>
#define s second
#define f first
#define maxn 100001

using namespace std;

typedef long long int ll;

vector <pair<ll, pair<int,int> > > v;

ll pref[maxn];
int n;

ll tam(int a, int b, int flag){
	if(flag){
		return (pref[n]-pref[b]+pref[a]);
	}
	else return(pref[b]-pref[a]);
}

int main(){
	int i, j, a, b, k, resp=0;
	cin >> n;
	pref[0]=0;
	for(i=1;i<=n;i++){
		cin >> pref[i];
		pref[i] += pref[i-1];
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			v.push_back({tam(i, j, 0), {i, j}});
		}
	}
	sort(v.begin(), v.end());
	a = b = 0;
	for(i=0;i<v.size();i++){
		if(v[i].f!=v[b].f){
			for(j=a;j<b;j++){
				for(k=j+1;k<=b;k++){
					if(v[j].s.s<v[k].s.f){
						if(tam(v[j].s.s, v[k].s.f, 0)==tam(v[j].s.f, v[k].s.s, 1)){
							resp = 1;
							break;
						}
					}
				}
				if(resp) break;
			}
			a = i;
		}
		b = i;
		if(resp) break;
	}
	if(resp) cout << "S";
	else cout << "N";
}
