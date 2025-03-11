#include <bits/stdc++.h>
#define s second
#define f first
#define maxn 501

using namespace std;

typedef pair <int,int> ii;

int d[maxn][maxn];

int main(){
    int n, m, i, j, p, a, b, resp;
    cin >> n >> m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> d[i][j];
        }
    }
    cin >> p;
    resp = p;
    for(i=0;i<p;i++){
        cin >> a >> b;
        a--;b--;
        if(d[a][b]) d[a][b]--;
        else resp--;
    }
    cout << resp << endl;
    return (0);
}