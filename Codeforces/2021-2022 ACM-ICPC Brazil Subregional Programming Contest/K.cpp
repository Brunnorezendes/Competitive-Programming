#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef vector<int> vi;
typedef long long int ll;

int main(){
    ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int i, t, m, d, ant=0, a, flag=0;
    cin >> t >> d >> m;
    for(i=0;i<m;i++){
        cin >> a;
        if(a-ant>=t) flag=1;
        ant = a;
    }
    if(d-ant>=t) flag=1;
    if(flag) cout << "Y\n";
    else cout << "N\n";
    return (0);
}