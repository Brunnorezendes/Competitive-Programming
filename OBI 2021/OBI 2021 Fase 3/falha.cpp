#include <bits/stdc++.h>
#define maxn 20001
#define fi first
#define se second

using namespace std;

// 0 = 48
// a = 97

vector <pair<int, string> > t;
int resp=0;

struct node{
	node* next[36];
	set <int> sun;
	int qtd=0;
	node(){
		memset(next, 0, sizeof(next));
	}
};

void add(string s, int ini, node* root, int flag, int u){
	int i=0;
	for(auto ch: s){
		if(i>=ini){
			if(flag && i==s.size()-1){
				if(ch<'a'){
					if(root->next[ch-'0']==NULL){
							root->next[ch-'0'] = new node;
						}
						root = root->next[ch-'0'];
				}
				else{
					if(root->next[ch-'a'+10]==NULL){
						root->next[ch-'a'+10] = new node;
					}
					root = root->next[ch-'a'+10];
				}
				resp-=root->qtd*(root->qtd-1);
				resp+=root->qtd*(root->qtd+1);
				root->qtd++;
			}
			else{
				if(ch<'a'){
					if(root->next[ch-'0']==NULL){
						root->next[ch-'0'] = new node;
					}
					root = root->next[ch-'0'];
				}
				else{
					if(root->next[ch-'a'+10]==NULL){
						root->next[ch-'a'+10] = new node;
					}
					root = root->next[ch-'a'+10];
				}
				if(root->sun.count(u)==0){
					resp+=root->qtd;
					root->sun.insert(u);
				}
			}
		}
		i++;
	}
}	

int main(){
	int i, n, j;
	node* root = new node();
	string s;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> s;
		t.push_back({s.size(), s});
	}
	sort(t.begin(), t.end());
	for(i=0;i<n;i++){
		add(t[i].se, 0, root, 1, i);
		for(j=1;j<t[i].se.size();j++){
			add(t[i].se, j, root, 0, i);
		}
	}
	cout << resp << endl;
	return (0);
}
