/*
...
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=2e3+10;
const int MAXM=6e3+10;
const int MOD=999911659;

struct edge{
	int v,next;
}es[MAXM];
int n,m,k,ans,head[MAXN],tot,ind[MAXN],topo[MAXN],cnt,sg[MAXN];
queue<int>q;
bool vis[MAXN];

void topoSort(){
	for(int i=1;i<=n;i++)if(!ind[i])q.push(i),vis[i]=1,topo[++cnt]=i;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=es[i].next){
			int v=es[i].v;
			if(--ind[v]==0)q.push(v),vis[v]=1,topo[++cnt]=v;
		}
	}
}

inline void addEdge(int u,int v){
	es[++tot].v=v,es[tot].next=head[u],head[u]=tot;
}

void solve(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		addEdge(x,y);
		++ind[y];
	}
	topoSort();
	for(int i=n;i>=1;i--){
		memset(vis,0,sizeof(vis));
		int u=topo[i],mx=0;
		for(int j=head[u];j;j=es[j].next){
			mx=max(mx,sg[es[j].v]);
			vis[sg[es[j].v]]=1;
		}
		for(int j=0;j<=mx+1;j++)if(!vis[j]){sg[u]=j;break;}
	}
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		ans^=sg[x];
	}
	if(ans)puts("win");
	else puts("lose");
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}