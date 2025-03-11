#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
	ll a, b, i, x, resp=0, j;
	cin >> a >> b;
	i = cbrt(sqrt(a));
	j = cbrt(sqrt(b));
	cout << j-i;
	return (0);
}
