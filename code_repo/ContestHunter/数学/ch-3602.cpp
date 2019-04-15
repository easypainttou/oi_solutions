/*
对于一个有m个点的环,把它变成m个自环至少需要m−1步

然后后面的排列组合加法乘法原理推出方案数...并且需要打表找规律以降低时间复杂度
不太理解 qwq

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int maxm=2e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+9;

ll fac[maxn],facInv[maxn],ans;
int n,t,p[maxn],col[maxn],tot,sz[maxn];

ll qPow(ll a,ll b){
	if(b<=0)return 1; //这里b会出现负数qwq
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

inline void init(){
	fac[0]=fac[1]=facInv[0]=facInv[1]=1; //qwq？
	for(int i=2;i<=maxn;i++)fac[i]=fac[i-1]*i%mod,facInv[i]=qPow(fac[i],mod-2);
}

void dfs(int x,int c){
	col[x]=1,++sz[c];
	if(!col[p[x]])dfs(p[x],c);
}

void solve(){
	init();
	scanf("%d",&t);
	while(t--){
		tot=0,ans=1;
		memset(sz,0,sizeof(sz));
		memset(col,0,sizeof(col));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",p+i);
		for(int i=1;i<=n;i++)if(!col[p[i]])dfs(p[i],++tot);
		ans=ans*fac[n-tot];
		for(int i=1;i<=tot;i++){
			ans=(ans*qPow(sz[i],sz[i]-2))%mod*facInv[sz[i]-1]%mod;
		}
		printf("%lld\n",ans);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}