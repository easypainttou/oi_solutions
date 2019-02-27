/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=5e3+5;
const int maxm=1e4+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct edge{
	int v,next;
}es[maxm];
int f,r,tot,dis[maxn][maxn],head[maxn],cnt,dfn[maxn],low[maxn],isB[maxm],bn,vis[maxn];

inline void addEdge(int u,int v){
	es[++tot].v=v,es[tot].next=head[u],head[u]=tot;
}

void tarjan(int x,int fa){
	dfn[x]=low[x]=++cnt;
	for(int i=head[x];i;i=es[i].next){
		int v=es[i].v;
		if(!dfn[v]){
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
			if(dfn[x]<low[v]){
				isB[i]=isB[i^1]=1;
			}
		}else if(v!=fa){
			low[x]=min(low[x],dfn[v]);
		}
	}
}

void findB(int x){
	for(int i=head[x];i;i=es[i].next){
		if(isB[i]){bn++;continue;}
		if(!vis[es[i].v]){
			vis[es[i].v]=1;
			findB(es[i].v);
		}
	}
}

void solve(){
	scanf("%d%d",&f,&r);
	tot=1;
	for(int i=1;i<=r;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		dis[a][b]=dis[b][a]=1;
	}
	for(int i=1;i<=f;i++)
		for(int j=i+1;j<=f;j++)
			if(dis[i][j])addEdge(i,j),addEdge(j,i);
	for(int i=1;i<=f;i++)if(!dfn[i])tarjan(i,-1);
	int ans=0;
	for(int i=1;i<=f;i++)if(!vis[i]){
		bn=0;
		vis[i]=1;
		findB(i);
		if(bn==1)ans++;
	}
	printf("%d",(ans+1)>>1);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}