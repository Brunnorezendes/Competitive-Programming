#include <bits/stdc++.h>
#define pb push_back
#define maxn 100009

using namespace std;
typedef vector<int> vi;
typedef long long int ll;

int num[maxn], pos[maxn];

int main(){
    ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int i, n, k, a, b, flag=0;
    cin >> n >> k;
    for(i=0;i<n;i++){
        cin >> a >> b; a--;
        num[a] = b;
        pos[i] = b;
    }
    for(i=0;i<n;i++)
        if(num[i]!=pos[i]) flag=1;
    if(flag) cout << "N\n";
    else cout << "Y\n";
    return (0);
}