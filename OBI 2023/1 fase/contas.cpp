#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a[3], resp;
    cin >> n >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    if(a[0]>n) resp = 0;
    else if(a[0]+a[1]>n) resp = 1;
    else if(a[0]+a[1]+a[2]>n) resp = 2;
    else resp = 3;
    cout << resp << endl;
    return (0);
}