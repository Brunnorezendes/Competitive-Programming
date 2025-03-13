#include<bits/stdc++.h>

using namespace std;
vector<int> h(100,0); 

int main(){
    int N,d,l,r,c,maxi;
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>d>>l>>r>>c;
        r--;c--;
        if(d==0){
            if(c+l>10){
                cout<<"N\n";
                return 0;
            }
            for(int j = 0; j<l;j++)
                h[10*(r)+c+j] = h[10*(r)+c+j] +1; 
        }
        else{
            if(r+l>10){
                cout<<"N\n";
                return 0;
            }
            for(int j = 0; j<l;j++)
                h[10*(r+j)+c] = h[10*(r+j)+c] + 1; 
        }
    }
    maxi=0;
    for(int i = 0; i< h.size(); i++)
        if(h[i]>maxi)
            maxi = h[i];
    if(maxi>1)
        cout<<"N\n";
    else
        cout<<"Y\n";
    return 0;
}