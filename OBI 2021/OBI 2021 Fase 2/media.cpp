#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	if(a<b) swap(a, b);
	cout << (2*b)-a << endl;
	return (0);
}
