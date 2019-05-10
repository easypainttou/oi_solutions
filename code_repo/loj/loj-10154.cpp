/*
树形背包 板子题

dp[u][j]:以u为根的子树上选择j个结点（选择的j个结点一定是包含u的连通块qwq）的最大学分


dp[u][0]=0
dp[u][1]=w[u]
dp[u][j]=max(dp[u][j-k]+dp[v][k])  写的不完整...qwq具体看代码

目标：dp[0][n+1]
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=100+10;
const int INF=0x3f3f3f3f;

struct edge{
	int v,next;
}es[MAXN];
int tot,head[MAXN],m,n,dp[MAXN][MAXN],sz[MAXN];

inline void addEdge(int u,int v){
	es[++tot].v=v,es[tot].next=head[u],head[u]=tot;
}

void dfs(int u){
	sz[u]=1;
	for(int i=head[u];i;i=es[i].next){
		int v=es[i].v;
		dfs(v);
		sz[u]+=sz[v];
		for(int j=min(n+1,sz[u]);j>=1;j--){
			for(int k=min(j-1,sz[v]);k>=0;k--){
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
			}
		}
	}
}

void solve(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		int u;
		scanf("%d%d",&u,&dp[i][1]);
		addEdge(u,i);
	}
	dfs(0);
	printf("%d",dp[0][n+1]);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 