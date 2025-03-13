#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, i, resp = 100, num = 100, a;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a;
        num += a;
        resp = max(num, resp);
    }
    cout << resp << endl;
    return (0);
}