/*
...x y 数组用于查重边qwq防T
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const int maxm=1e6+5;
const double eps=1e-10;
const int base=131;
//const int mod=1e9+7;

struct edge{
	int v,next;
}es[maxm];
int n,m,mod,tot,ans,head[maxn],cnt,dfn[maxn],low[maxn],instack[maxn],cc,col[maxn],colcnt[maxn],ind[maxn],sum[maxn],dp[maxn],x[maxm],y[maxm],nu[maxm];
stack<int>s;
queue<int>q;

int read(){
	int ans=0;
	char ch;
	ch=getchar();
	for(;ch<'0'||ch>'9';)ch=getchar();
	for(;ch>='0'&&ch<='9';)ans=ans*10+ch-'0',ch=getchar();
	return ans;
}

inline void addEdge(int u,int v){es[++tot].v=v,es[tot].next=head[u],head[u]=tot;}

void tarjan(int x){
	dfn[x]=low[x]=++cnt;
	s.push(x),instack[x]=1;
	for(int i=head[x];i;i=es[i].next){
		int v=es[i].v;
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}else if(instack[v]){
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(dfn[x]==low[x]){
		++cc;
		int crt;
		do{
			crt=s.top();s.pop();
			instack[crt]=0;
			col[crt]=cc;
			colcnt[cc]++;
		}while(crt!=x);
	}
}

bool cmp(int a,int b){
	if(x[a]==x[b])return y[a]<y[b];
	return x[a]<x[b];
}

void solve(){
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=1;i<=m;i++){
		nu[i]=i,x[i]=read(),y[i]=read();
		addEdge(x[i],y[i]);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	memset(es,0,sizeof(es));
	memset(head,0,sizeof(head));
	tot=0;
	for(int i=1;i<=m;i++)x[i]=col[x[i]],y[i]=col[y[i]];
	sort(nu+1,nu+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(x[nu[i]]!=y[nu[i]]&&(x[nu[i]]!=x[nu[i-1]]||y[nu[i]]!=y[nu[i-1]])){
			int u=x[nu[i]],v=y[nu[i]];
			addEdge(u,v);
			ind[v]++;
		}
	}	
	for(int i=1;i<=cc;i++)if(!ind[i]){
		q.push(i),sum[i]=1,dp[i]=colcnt[i];
		if(dp[i]>dp[ans])ans=i;
	}
	while(!q.empty()){
		int u=q.front();q.pop();	
		for(int i=head[u];i;i=es[i].next){
			int v=es[i].v;
			if(dp[v]<dp[u]+colcnt[v]){
				dp[v]=dp[u]+colcnt[v];
				sum[v]=sum[u];
			}else if(dp[v]==dp[u]+colcnt[v]){
				sum[v]=(sum[v]+sum[u])%mod;
			}
			if(dp[v]>dp[ans])ans=v;
			if(--ind[v]==0)q.push(v);
		}
	}
	int ssum=0;
	for(int i=1;i<=cc;i++)if(dp[ans]==dp[i])ssum=(ssum+sum[i])%mod;
	printf("%d\n%d",dp[ans]%mod,ssum%mod);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}