#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn=1e5+10;

int nxt[maxn],cur,lst;
char str[maxn];

void solve(){
	while(~scanf("%s",str+1)){
		int len=strlen(str+1);
		nxt[0]=cur=lst=0;
		for(int i=1;i<=len;i++){
			if(str[i]=='['){
				cur=0;
			}else if(str[i]==']'){
				cur=lst;
			}else{
				nxt[i]=nxt[cur];
				nxt[cur]=i;
				if(cur==lst)lst=i;
				cur=i;
			}
		}
		for(int i=nxt[0];i;i=nxt[i]){
			printf("%c",str[i]);
		}
		printf("\n");
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}