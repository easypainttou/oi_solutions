/*

dp[u][i]:以u为根的子树保留i个树枝（i个树枝一定是包含u的连通块）的最多苹果数

初值都是0
若有左子树，左子树根为lc dp[u][i]=max(dp[u][i],dp[lc][i-1]+w[lc])
若有右子树，右子树根为rc dp[u][i]=max(dp[u][i],dp[rc][i-1]+w[rc])
若有左子树且有右子树 dp[u][i]=max(dp[u][i],dp[lc][j-1]+w[lc]+dp[rc][i-j-1]+w[rc])

目标：dp[1][q]		

具体看代码qwq...

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=100+10;
const int INF=0x3f3f3f3f;

struct edge{
	int v,w,next;
}es[MAXN<<1];
int n,q,tot,head[MAXN],dp[MAXN][MAXN],sz[MAXN];
bool vis[MAXN];

inline void addEdge(int u,int v,int w){
	es[++tot].v=v,es[tot].w=w,es[tot].next=head[u],head[u]=tot;
}

void dfs(int u,int fa){
	vis[u]=1;
	sz[u]=1;
	int lc=-1,rc=-1,w1,w2;
	for(int i=head[u];i;i=es[i].next){
		int v=es[i].v,w=es[i].w;
		if(v==fa||vis[v])continue;
		if(lc==-1)lc=v,w1=w;
		else rc=v,w2=w;
		dfs(v,u);
		sz[u]+=sz[v];
	}
	
	//sz[u]-1 相当于u为根的子树中，除了u，所有的结点和它们的父结点作为端点的边的数量，也就是u为根的子树的树枝数 qwq
	for(int i=1;i<=sz[u]-1;i++){
		if(lc!=-1)dp[u][i]=max(dp[u][i],dp[lc][i-1]+w1);
		if(rc!=-1)dp[u][i]=max(dp[u][i],dp[rc][i-1]+w2);
		if(lc==-1||rc==-1)continue;
		for(int j=1;j<=i-1;j++)dp[u][i]=max(dp[u][i],dp[lc][j-1]+w1+dp[rc][i-j-1]+w2);
	}
}

void solve(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		addEdge(x,y,z);
		addEdge(y,x,z);
	}
	dfs(1,0);
	printf("%d",dp[1][q]);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}