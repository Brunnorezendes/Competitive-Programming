#include <bits/stdc++.h>

using namespace std;

char s[5] = {'a', 'e', 'i', 'o', 'u'};

int main(){
	int flag, i, d;
	char nex;
	string str;
	cin >> str;
	for(auto c:str){
		flag=0;
		for(i=0;i<5;i++){
			if(c==s[i]) flag=1;
		}
		cout << c;
		if(!flag){
			d = 30;
			for(i=0;i<5;i++){
				if(abs(c-s[i])<d){
					d = abs(c-s[i]);
					nex = s[i];
				}
			}
			printf("%c", nex);
			if(c=='z') printf("z");
			else if(c=='v') printf("x");
			else if(c=='x') printf("z");
			else{
				flag=0;
				for(i=0;i<5;i++){
					if(c+1==s[i]) flag=1;
				}
				if(flag) printf("%c", c+2);
				else printf("%c", c+1);
			}
		}
	}
	return(0);
}
