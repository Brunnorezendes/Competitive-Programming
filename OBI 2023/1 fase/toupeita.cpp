#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int adj[maxn][maxn];

int main(){
    int n, m, i, a, b, p, c, j, resp = 0, flag;
    cin >> n >> m;
    for(i=0;i<m;i++){
        cin >> a >> b;
        a--;b--;
        adj[a][b] = adj[b][a] = 1;
    }
    cin >> p;
    for(i=0;i<p;i++){
        cin >> c;
        flag = 0;
        for(j=0;j<c;j++){
            cin >> a;
            a--;
            if(j && !adj[b][a]) flag = 1;
            b = a;
        }
        if(!flag) resp++;
    }
    cout << resp << endl;
    return (0);
}