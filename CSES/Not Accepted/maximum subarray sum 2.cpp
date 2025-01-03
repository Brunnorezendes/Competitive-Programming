#include <bits/stdc++.h>
#define maxn 200001

using namespace std;

int v[maxn], sufix[maxn];

int main(){
	int n, a, b, l=0, r=0, i, sum=0, maxi=0;
	cin >> n >> a >> b;
	for(i=0;i<n;i++) cin >> v[i];
	sufix[n-1] = v[n-1];
	for(i=n-2;i>=0;i--) sufix[i] = max(sufix[i+1] + v[i], v[i]);
	while(l<n){
		cout << l << " " << r << endl;
		if(r-l<a){
			if(r!=n) sum += v[r++];
			else sum -= v[l++];
			continue;
		}
		maxi = max(maxi, sum);
		if(r==n) sum -= v[l++];
		else if(r-l==b) sum -= v[l++];
		else if(r-l==a) sum += v[r++];
		else if(v[l]<0) sum -= v[l++];
		else if(v[r]>0) sum += v[r++];
		else if(sufix[i]-sufix[b-(r-l)+i]>0) sum += v[r++];
		else sum -= v[l++];
	}
	cout << maxi;
	return (0);
}
