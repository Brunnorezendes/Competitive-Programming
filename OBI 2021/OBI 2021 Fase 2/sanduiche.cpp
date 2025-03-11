#include <bits/stdc++.h>
#define maxn 1048577

using namespace std;

int v[maxn];

int main(){
	int i, n, a, b, m, j, flag;
	long long int resp=0;
	cin >> n >> m;
	for(i=0;i<m;i++){
		cin >> a >> b;
		a = 1<<(a-1);
		b = 1<<(b-1);
		v[i] = a+b;
	}
	for(i=1;i<(1<<(n));i++){
		flag=0;
		for(j=0;j<m;j++){
			if((i&v[j])==v[j]) flag=1;
		}
		if(!flag) resp++;
	}
	cout << resp << endl;
	return (0);
}
