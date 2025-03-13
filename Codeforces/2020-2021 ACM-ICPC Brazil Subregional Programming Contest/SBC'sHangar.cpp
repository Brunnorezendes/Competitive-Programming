#include <bits/stdc++.h>
#define s second
#define f first

using namespace std;

typedef long long int ll;
typedef pair <ll, int> pli;

vector <pli> v[2], aux;

int main(){
    int n, k, atual=0, i, j, cont;
    ll a, b, val;
    v[0].push_back({0,0});
    for(i=0;i<n;i++){
        cin >> val;
        cont=0;
        for(j=0;j<v[atual].size();j++){
            if(v[atual][j].s<k) aux.push_back({val+v[atual][j].f, v[atual][j].s+1});
            while(cont<aux.size() && aux[cont].f<v[atual][j].f) v[!atual].push_back(aux[cont++]);
            v[!atual].push_back(v[atual][j]);
        }
        while(cont<aux.size()) v[!atual].push_back(aux[cont++]);
        v[atual].clear();
        aux.clear();
        atual = !atual;
    }
    for(i=0;i<v[atual].size();i++){
        cout << v[atual][i].f << " ";
    }
    cout << endl;
    return (0);
}