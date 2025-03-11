#include <bits/stdc++.h>

using namespace std;

stack <int> s;

int main(){
	int n, sum=0, i, a;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a;
		sum+=a;
		if(!a){
			sum-= s.top();
			s.pop();
		}
		else{
			s.push(a);
		}
	}
	cout << sum << endl;
	return(0);
}
