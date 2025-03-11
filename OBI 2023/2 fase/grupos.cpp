#include <bits/stdc++.h>
#define maxn 1000000

using namespace std;

typedef pair<int,int> ii;

vector <ii> mm, md;
int v[maxn];

int main(){
    int e, m, d, a, b, c, i, cumpm=0, cumpd=0;
    cin >> e >> m >> d;
    for(i=0;i<m;i++){
        cin >> a >> b;
        mm.push_back({a,b});
    }
    for(i=0;i<d;i++){
        cin >> a >> b;
        md.push_back({a,b});
    }
    for(i=0;i<e/3;i++){
        cin >> a >> b >> c;
        v[a] = v[b] = v[c] = i;
    }
    for(i=0;i<m;i++){
        if(v[mm[i].first]==v[mm[i].second]) cumpm++;
    }
    for(i=0;i<d;i++){
        if(v[md[i].first]==v[md[i].second]) cumpd++;
    }
    cout << cumpd + m - cumpm << endl;
    return (0);
}