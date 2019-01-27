#include<cstdio>
#include<cstring>
//#include<iostream>
using namespace std;

char cl[75];
int cnt[26];

void solve(){
	int len,mx=0;
	for(int i=0;i<4;i++){
		gets(cl);
		len=strlen(cl);
		for(int j=0;j<len;j++){
			if(cl[j]>='A'&&cl[j]<='Z'){
				if(++cnt[cl[j]-'A']>mx)mx=cnt[cl[j]-'A'];
			}
		}
	}
	for(int i=0;i<mx;i++){
		for(int j=0;j<26;j++)printf("%c ",(cnt[j]>mx-i-1)?'*':' ');
		printf("\n");
	}
	for(int j=0;j<26;j++)printf("%c ",j+65);
}

int main(){
	//freopen("out","w",stdout);
	solve();
	return 0;
}