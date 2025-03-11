#include <bits/stdc++.h>
#define maxn 100003

using namespace std;

typedef long long int ll;

ll pref[maxn];

int n;

ll tam(int a, int b, int flag){
	if(flag){
		return (pref[n]-pref[b]+pref[a]);
	}
	else return(pref[b]-pref[a]);
}

int main(){
	int a=0, b=1, c=2, d=3, i, resp=0;
	cin >> n;
	pref[0]=0;
	for(i=1;i<=n;i++){
		cin >> pref[i];
		pref[i]+=pref[i-1];
	}
	while((a<b)&&(b<c)&&(c<d)&&(d<n)){
		if((tam(a, b, 0)==tam(c, d, 0))&&(tam(b, c, 0)==tam(a, d, 1))){
			resp=1;
			break;
		}
		if((tam(a, d, 1)>tam(b, c, 0)) && (tam(a, b, 0)>tam(c, d, 0))) d++;
		else if((tam(a, d, 1)>tam(b, c, 0)) && (tam(a, b, 0)<tam(c, d, 0))){
			if(c==d-1) d++;
			else c++;
		}
		else if((tam(a, d, 1)<tam(b, c, 0)) && (tam(a, b, 0)>tam(c, d, 0))){
			if(a==b-1) b++;
			else a++;
		}
		else if((tam(a, d, 1)<tam(b, c, 0)) && (tam(a, b, 0)<tam(c, d, 0))){
			if(b==c-1) c++;
			else b++;
		}
		else if(tam(a, d, 1)==tam(b, c, 0)){
			if(tam(a, b, 0)>tam(c, d, 0)) a++;
			else c++;
		}
		else if(tam(a, b, 0)==tam(c, d, 0)){
			if(tam(a, d, 1)>tam(b, c, 0)) d++;
			else b++;
		}
	}
	if(resp==1) cout << "S";
	else cout << "N";
	return (0);
}
