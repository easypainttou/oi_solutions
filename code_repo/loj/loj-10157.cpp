/*
dp[i][0]:i点有人，i点安全，i的儿子为根的子树都安全，的以i为根的子树的最小经费
dp[i][1]:i点无人，i点安全，i的儿子为根的子树都安全，的以i为根的子树的最小经费
dp[i][2]:i点无人，i点不安全，i的儿子为根的子树都安全，的以i为根的子树的最小经费

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1500+10;
const int INF=0x3f3f3f3f;

struct edge{
	int v,next;
}es[MAXN<<1];
int tot,head[MAXN],n;
ll w[MAXN],dp[MAXN][3];

inline void addEdge(int u,int v){
	es[++tot].v=v,es[tot].next=head[u],head[u]=tot;
}

void dfs(int u,int fa){
	
	ll k=INF; //这里如果INF用0x3f3f3f3f在int范围会溢出，所以用long long 或者改小点，qwq
	dp[u][0]=w[u];
	for(int i=head[u];i;i=es[i].next){
		int v=es[i].v;
		if(fa==v)continue;
		dfs(v,u);
		dp[u][0]+=min(dp[v][0],min(dp[v][1],dp[v][2]));
		dp[u][1]+=min(dp[v][0],dp[v][1]);
		dp[u][2]+=dp[v][1];
		
		k=min(k,dp[v][0]-min(dp[v][0],dp[v][1]));
	}
	dp[u][1]+=k;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int u,tmp,m;
		scanf("%d%d%d",&u,&tmp,&m);
		w[u]=tmp;
		for(int j=1;j<=m;j++){
			int r;
			scanf("%d",&r);
			addEdge(u,r);
			addEdge(r,u);
		}
	}
	dfs(1,0);
	printf("%lld",min(dp[1][0],dp[1][1]));
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 