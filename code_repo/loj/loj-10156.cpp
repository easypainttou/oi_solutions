/*

u为子树的根结点
vi为u的儿子，共k个

转移：
u点不放，以u为根的子树的最少士兵数 dp[u][0]=dp[v1][1]+...+dp[vk][1]
u点放，以u为根的子树的最少士兵数 dp[u][1]=1+min(dp[v1][0],dp[v1][1])+...+min(dp[vk][0],dp[vk][1])

目标：min(dp[1][0],dp[1][1])

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1500+10;
const int INF=0x3f3f3f3f;

struct edge{
	int v,next;
}es[MAXN*MAXN];
int tot,head[MAXN],n,dp[MAXN][2];
bool vis[MAXN];

inline void addEdge(int u,int v){
	es[++tot].v=v,es[tot].next=head[u],head[u]=tot;
}

void dfs(int u,int fa){
	vis[u]=1;
	dp[u][1]=1;
	for(int i=head[u];i;i=es[i].next){
		int v=es[i].v;
		if(v==fa||vis[v])continue;
		dfs(v,u);
		
		dp[u][0]+=dp[v][1];
		dp[u][1]+=min(dp[v][0],dp[v][1]);
	}
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		for(int j=1;j<=y;j++){
			int z;
			scanf("%d",&z);
			addEdge(i,z+1);
			addEdge(z+1,i);
		}
	}
	dfs(1,0);
	printf("%d",min(dp[1][0],dp[1][1]));
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 