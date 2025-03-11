#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

char a[maxn], b[maxn];

int main(){
    int n, m, i;
    cin >> n;
    scanf("%s", a);
    cin >> m;
    scanf("%s", b);
    for(i=0;i<min(n,m);i++){
        if(a[i]!=b[i]) break;
    }
    cout << i << endl;;
    return (0);
}