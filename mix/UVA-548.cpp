#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
const int inf=0x3f3f3f3f;

int l[maxn],r[maxn],cnt,in_o[maxn],post_o[maxn],ansp,ans;
char str[6*maxn];

int getTree(int inl,int inr,int postl,int postr){
	if(inl>inr)return 0;
	int ipos,rt=post_o[postr];
	for(ipos=inl;ipos<=inr;ipos++){
		if(in_o[ipos]==rt)break;
	}
	l[rt]=getTree(inl,ipos-1,postl,postl+ipos-inl-1);
	r[rt]=getTree(ipos+1,inr,postl+ipos-inl,postr-1);
	return rt;
}

void dfs(int rt,int num){
	num+=rt;
	if(!l[rt]&&!r[rt]){
		if(num<ans||num==ans&&rt<ansp)ansp=rt,ans=num;
		return;
	}
	if(l[rt])dfs(l[rt],num);
	if(r[rt])dfs(r[rt],num);
}

void solve(){
	while(gets(str)){
		cnt=0,ans=ansp=inf;
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		int num=0,len=strlen(str);
		for(int i=0;i<len;i++){
			if(str[i]==' ')in_o[++cnt]=num,num=0;
			else num=num*10+str[i]-'0';
		}
		in_o[++cnt]=num;
		
		for(int i=1;i<=cnt;i++){
			scanf("%d",post_o+i);
		}
		getchar();
		
		getTree(1,cnt,1,cnt);
		dfs(post_o[cnt],0);
		printf("%d\n",ansp);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}