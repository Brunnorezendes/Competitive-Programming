#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, i, x, y, respa=0, respb=0, pa=1, pb=1, flaga=0, flagb=0;
	cin >> a >> b;
	for(i=1;((a/i)>0)||((b/i)>0);i*=10){
		x = (a/i)%10;
		y = (b/i)%10;
		if(x==y){
			respa+=pa*x;
			pa*=10;
			respb+=pb*y;
			pb*=10;
			flaga = flagb = 1;
		}
		else if(x>y){
			respa+=pa*x;
			pa*=10;
			flaga = 1;
		}
		else{
			respb+=pb*y;
			pb*=10;
			flagb = 1;
		}
	}
	if(!flaga) respa=-1;
	if(!flagb) respb=-1;
	if(respa>respb) swap(respa, respb);
	cout << respa << " " << respb;
	return (0);
}
