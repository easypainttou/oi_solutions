#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
typedef long long ll;

const int MAXN=1e5+5;
const int MAXM=1e6+5;
const int INF=0x3f3f3f3f;
const int MOD=10007;

struct edge{
	int v,next;
	edge(int v=0,int next=0):v(v),next(next){}
}es[2][MAXM];
int n,m,p[MAXN],tot[2],head[2][MAXN],dis[2][MAXN];
bool vis[MAXN];
priority_queue< pair<int,int> >q;

void addEdge(int u,int v){
	es[0][++tot[0]].v=v;
	es[0][tot[0]].next=head[0][u];
	head[0][u]=tot[0];
	
	es[1][++tot[1]].v=u;
	es[1][tot[1]].next=head[1][v];
	head[1][v]=tot[1];
}

void dijkstra(int s,int tp){
	memset(vis,0,sizeof(vis));
	while(!q.empty())q.pop();
	dis[tp][s]=p[s];
	q.push(make_pair((tp?dis[tp][s]:(-dis[tp][s])),s));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[tp][u];i;i=es[tp][i].next){
			int v=es[tp][i].v;
			if(vis[v])continue;
			if(tp){
				if(dis[tp][v]<max(dis[tp][u],p[v])){
					dis[tp][v]=max(dis[tp][u],p[v]);
					q.push(make_pair(dis[tp][v],v));
				}
			}else{
				if(dis[tp][v]>min(dis[tp][u],p[v])){
					dis[tp][v]=min(dis[tp][u],p[v]);
					q.push(make_pair(-dis[tp][v],v));
				}
			}
		}
	}
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	for(int i=1;i<=m;i++){
		int u,v,tp;
		scanf("%d%d%d",&u,&v,&tp);
		addEdge(u,v);
		if(tp==2)addEdge(v,u);
	}
	memset(dis[0],0x3f,sizeof(dis[0]));
	memset(dis[1],0,sizeof(dis[1]));
	dijkstra(1,0),dijkstra(n,1);
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,dis[1][i]-dis[0][i]);
	printf("%d",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
