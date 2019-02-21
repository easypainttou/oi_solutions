/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e5+10;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct node{
	int dic[10],bk;
}ns[maxn];
int tot,root,T,n;
char str[15];
bool ans;

void insertTrie(){
	int now=root,len=strlen(str);
	bool upd=0;
	for(int i=0;i<len;i++){
		int c=str[i]-'0';
		if(ns[now].dic[c]==0)upd=1,ns[now].dic[c]=++tot;
		now=ns[now].dic[c];
		if(ns[now].bk)ans=1;
	}
	ns[now].bk++;
	if(!upd)ans=1;
}

void solve(){
	scanf("%d",&T);
	while(T--){
		memset(ns,0,sizeof(ns));
		ans=0,tot=0;
		root=++tot;
		scanf("%d",&n);
		while(n--){
			scanf("%s",str);
			insertTrie();	
		}
		if(!ans)printf("YES\n");
		else printf("NO\n");
	}
}

int main(){
	freopen("in.txt","r",stdin);
	solve();
	return 0;
}