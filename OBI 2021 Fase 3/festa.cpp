#include <bits/stdc++.h>
#define maxn 10001
#define maxm 5000

using namespace std;

typedef long long int ll;

int v[maxn], i, n, m, g[maxm], a, j, ma;



int main(){
	cin >> n >> m;
	for(i=0;i<m;i++){
		cin >> a;
		g[i]=a;
	}
	a = 10000;
	ma = min(n, a);
	for(i=0;i<ma;i++){
		v[i] = i+1;
	}
	for(i=m-1;i>=0;i--){
		for(j=0;j<ma;j++){
			v[j]+= (v[j]-1)/(g[i]-1);
			if(v[j]>n) ma=j;
		}
	}
	for(i=0;i<ma;i++){
		cout << v[i] << endl;
	}
	return (0);
}
