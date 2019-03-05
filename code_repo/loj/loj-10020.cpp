/*
...很多剪枝qwq
*/
#include<bits/stdc++.h>
#define lson p<<1
#define rson p<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//typedef set<int>::iterator it;
const int inf=0x3f3f3f3f;
const int maxn=1e3+5;
const int maxm=2e6+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;
const double pi=acos(-1);

int n,a[65],minl,maxl,len,gs;
bool ok,vis[65];

bool cmp(const int &a,const int &b){ //长度从大到小搜索，步数更少
	return a>b;
}

void dfs(int g,int nowl,int pre){
	if(nowl==len){
		++g;
		if(g==gs){
			ok=1;
			return;
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				dfs(g,a[i],i);
				vis[i]=0;
				return;
			}
		}
	}
	for(int i=pre+1;i<=n;i++){
		if(vis[i])continue;
		if(a[i]+nowl<=len){
			vis[i]=1;
			dfs(g,nowl+a[i],i);
			if(ok)return; //有答案就返回qwq
			vis[i]=0;
			while(i<n&&a[i]==a[i+1])++i; //相同的长度不重复搜索
		}
	}
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),minl=max(minl,a[i]),maxl+=a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=minl;i<=maxl;i++){ //可行性剪枝
		if(maxl%i==0){ //可行性剪枝qwq
			memset(vis,0,sizeof(vis));
			len=i;
			gs=maxl/i;
			vis[1]=1;
			dfs(0,a[1],1);
			if(ok==1){
				printf("%d",len);
				return;
			}
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}