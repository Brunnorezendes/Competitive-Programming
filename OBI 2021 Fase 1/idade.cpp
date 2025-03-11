#include <bits/stdc++.h>

using namespace std;

vector <int> v;

int main(){
	int a, i;
	for(i=0;i<3;i++){
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	cout << v[1] << endl;
	return(0);
}
