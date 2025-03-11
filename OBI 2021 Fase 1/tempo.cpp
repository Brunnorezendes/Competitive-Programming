#include <bits/stdc++.h>
#define maxn 101

using namespace std;

typedef vector<int> vi;

vi resp, init, lista;

int main(){
	int n, i, a, time=0;
	char c;
	resp = vi(maxn, 0);
	init = vi(maxn, -1);
	cin >> n;
	for(i=0;i<n;i++, time++){
		cin >> c >> a;
		if(c=='R'){
			init[a]=time;
			if(!resp[a]) lista.push_back(a);
		}
		else if(c=='T'){
			time+= a-2;
		}
		else{
			resp[a] += time-init[a];
			init[a]=-1;
		}
	}
	sort(lista.begin(), lista.end());
	for(i=0;i<lista.size();i++){
		a = lista[i];
		cout << a << " ";
		if(init[a]>=0) cout << "-1\n";
		else cout << resp[a] << endl;
	}
	return(0);
}
