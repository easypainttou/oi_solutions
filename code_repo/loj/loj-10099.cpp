/*
...先找割点
然后qwq
1.点双连通图 ans=2
2.删除割点是一些点双连通子图
连通块相邻的割点有1个 ans+=1
割点≥1个 ans+=0
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e3+5;
const int maxm=5e2+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct edge{
	int v,next;
}es[maxm];
int T,n,m,head[maxn],nodes[maxn],tot,dfn[maxn],low[maxn],cnt,num;
ll size;
bool bk[maxn],vis[maxn],cut;

inline void init(){
	++T;
	cut=tot=cnt=m=0;
	memset(es,0,sizeof(es));
	memset(head,0,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(bk,0,sizeof(bk));
	memset(vis,0,sizeof(vis));
}

inline void addEdge(int u,int v){
	es[++tot].v=v,es[tot].next=head[u],head[u]=tot;
}

void tarjan(int x,int fa){
	dfn[x]=low[x]=++cnt;
	int child=0;
	for(int i=head[x];i;i=es[i].next){
		int v=es[i].v;
		if(!dfn[v]){
			child++;
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
			if(!bk[x]&&fa!=x&&dfn[x]<=low[v]){
				bk[x]=1;cut=1;
			}
		}else if(fa!=v)low[x]=min(low[x],dfn[v]);
	}
	if(x==fa&&child>=2){
		bk[x]=1;cut=1;
	}
}

void dfs(int u){
	vis[u]=1;
	if(bk[u]){
		num++;
		return;
	}
	size++;
	for(int i=head[u];i;i=es[i].next){
		int v=es[i].v;
		if(!vis[v]){
			dfs(v);
		}
	}
}


void solve(){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		init();
		for(int i=1;i<=n;i++){
			int s,t;
			scanf("%d%d",&s,&t);
			addEdge(s,t),addEdge(t,s);
			nodes[++m]=s,nodes[++m]=t;
		}
		sort(nodes+1,nodes+m+1);
		m=unique(nodes+1,nodes+m+1)-nodes-1;
		for(int i=1;i<=m;i++)if(!dfn[nodes[i]])tarjan(nodes[i],nodes[i]);
		if(!cut){
			printf("Case %d: 2 %lld\n",T,(ll)m*(m-1)/2);
			continue;
		}
		int ans=0;
		ll ssum=1;
		for(int i=1;i<=m;i++)if(!vis[nodes[i]]&&!bk[nodes[i]]){
			num=0,size=0;
			dfs(nodes[i]);
			if(num==1)ans++,ssum*=size;
			for(int j=1;j<=m;j++)if(bk[nodes[j]])vis[nodes[j]]=0;
		}
		printf("Case %d: %d %lld\n",T,ans,ssum);
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}