#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
    long long int n, i, r=1;
    cin >> n;
    for(i=3;i<=n;i++){
        if(i%2) r = ((i*r)%mod)-1;
        else r = ((i*r)%mod)+1;
    }
    if(n==1) cout << "0\n";
    else cout << r << endl;
    return (0);
}

