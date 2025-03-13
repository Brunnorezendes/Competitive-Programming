#include <bits/stdc++.h>
#define maxc 41

using namespace std;

char m[maxc][maxc];
string word;
int v[maxc][maxc], expe[27], atual[27];
int fsize;

void add(char let){
    if(let>='A'){
        atual[let-'A']++;
    }
}

void remove(char let){
    if(let>='A'){
        atual[let-'A']--;
    }
}

void clear(){
    for(int i=0;i<26;i++) atual[i] = 0;
}

bool verify(){
    bool resp = true;
    for(int i=0;i<26;i++){
        resp = resp & (expe[i]==atual[i]);
    }
    return resp;
}

void mark(int k, int tp, int d, int a, int b){
    if(!tp){
        for(int i=a;i<=b;i++) v[d][i] |= 1<<k;
    }
    else if(tp==1){
        for(int i=a;i<=b;i++) v[i][d] |= 1<<k;
    }
    else if(tp==2){
        for(int i=a;i<=b;i++) v[d+i][i] |= 1<<k;
    }
    else if(tp==3){
        for(int i=a;i<=b;i++) v[i][d+i] |= 1<<k;
    }
    else if(tp==4){
        for(int i=a;i<=b;i++) v[d-i][i] |= 1<<k;
    }
    else{
        for(int i=a;i<=b;i++) v[i][d-i] |= 1<<k;
    }
}

int main(){
    int l, c, i, j, k, n, resp=0, x;
    cin >> l >> c;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            cin >> m[i][j];
        }
    }
    cin >> n;
    for(k=0;k<n;k++){
        cin >> word;
        for(i=0;i<word.size();i++){
            expe[word[i]-'A']++;
        }
        fsize = word.size();
        if(fsize<=c){
            for(i=0;i<l;i++){
                for(j=0;j<fsize;j++){
                    add(m[i][j]);
                }
                if(verify())mark(k, 0, i, 0, fsize-1);
                for(j=fsize;j<c;j++){
                    remove(m[i][j-fsize]);
                    add(m[i][j]);
                    if(verify())mark(k, 0, i, j-fsize+1, j);
                }
                clear();
            }
            for(i=0;i<=l-fsize;i++){
            for(j=0;j<fsize;j++){
                add(m[i+j][j]);
            }
            if(verify())mark(k, 2, i, 0, fsize-1);
            for(j=fsize;j<min(l-i, c);j++){
                remove(m[i+j-fsize][j-fsize]);
                add(m[i+j][j]);
                if(verify())mark(k, 2, i, j-fsize+1, j);
            }
            clear();
            }
            for(i=0;i<=l-fsize;i++){
            for(j=0;j<fsize;j++){
                add(m[l-1-i-j][j]);
            }
            if(verify())mark(k, 4, l-1-i, 0, fsize-1);
            for(j=fsize;j<min(l-i, c);j++){
                remove(m[l-1-i-j+fsize][j-fsize]);
                add(m[l-1-i-j][j]);
                if(verify())mark(k, 4, l-1-i, j-fsize+1, j);
            }
            clear();
            }
        }
        if(fsize<=l){
            for(i=0;i<c;i++){
                for(j=0;j<fsize;j++){
                    add(m[j][i]);
                }
                if(verify())mark(k, 1, i, 0, fsize-1);
                for(j=fsize;j<l;j++){
                    remove(m[j-fsize][i]);
                    add(m[j][i]);
                    if(verify())mark(k, 1, i, j-fsize+1, j);
                }
                clear();
            }
            for(i=0;i<=c-fsize;i++){
            for(j=0;j<fsize;j++){
                add(m[j][c-1-i-j]);
            }
            if(verify())mark(k, 5, l-1-i, 0, fsize-1);
            for(j=fsize;j<min(c-i, l);j++){
                remove(m[j-fsize][c-1-i-j+fsize]);
                add(m[j][c-1-i-j]);
                if(verify())mark(k, 5, c-1-i, j-fsize+1, j);
            }
            clear();
            }
            for(i=0;i<=c-fsize;i++){
            for(j=0;j<fsize;j++){
                add(m[j][i+j]);
            }
            if(verify())mark(k, 3, i, 0, fsize-1);
            for(j=fsize;j<min(c-i, l);j++){
                remove(m[j-fsize][i+j-fsize]);
                add(m[j][i+j]);
                if(verify())mark(k, 3, i, j-fsize+1, j);
            }
            clear();
            }
        }
        
        for(i=0;i<26;i++) expe[i] = 0;
    }
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            x = v[i][j];
            if(x-(x&(-x))) resp++;
        }
    }
    cout << resp << endl;
    return (0);
}