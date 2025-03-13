#include <bits/stdc++.h>
#define maxn 103

using namespace std;

int dp[maxn][maxn];

int main(){
    int i, n, a, b, j, k, resp=0;
    cin >> n;
    dp[0][1] = 1;
    dp[1][0]= 1;
    dp[1][1]= 1;
    for (i = 2; i < 101; i++) {
        for (j = ; j <= i; j++) {
            for (k = 1; k <= j; k++)
                dp[i][j]|= !dp[i][j-k];
            for (k = 1; k <= i; k++)
                dp[i][j]|= !dp[i-k][j];
            for (k = 1; k <= j; k++)
                dp[i][j]|= !dp[i-k][j-k];
            dp[j][i] = dp[i][j];
        }
    }
    for(i=0;i<n;i++){
        cin >> a >> b;
        //if(a>b) swap(a, b);
        resp ^= dp[a][b];
    }
    if(resp) cout << "Y\n";
    else cout << "N\n";
    return (0);
}