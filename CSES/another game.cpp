#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, t, a, flag;
	cin >> t;
	while(t--){
		cin >> n;
		flag=0;
		for(int i=0;i<n;i++){
			cin >> a;
			if(a&1) flag=1;
		}
		if(flag) cout << "first\n";
		else cout << "second\n";
	}
	return (0);
}
