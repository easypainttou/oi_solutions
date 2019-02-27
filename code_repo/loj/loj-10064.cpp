/*
WA是mod写错了，long long 加LL
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxm=1e6+5;
const int maxn=1e3+5;
const ll mod=(1LL<<31)-1;
struct edge{
	int v,w,next;
	edge(int v=0,int w=0,int next=0):v(v),w(w),next(next){}
}es[maxm];
int n,m,head[maxn],tot,dis[maxn],ns[maxn];
ll ans;
bool vis[maxn];
priority_queue< pair<int,int> >q;

inline void addedge(int u,int v,int w){
	es[++tot].v=v,es[tot].w=w,es[tot].next=head[u],head[u]=tot;
}

bool com(int a,int b){
	return dis[a]<dis[b];
}

void dijkstra(){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	while(!q.empty())q.pop();
	q.push(make_pair(-dis[1],1));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=es[i].next){
			int v=es[i].v,w=es[i].w;
			if(
			//!vis[v]&&
			dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}

void solve(){
	ans=1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y,l;
		scanf("%d%d%d",&x,&y,&l);
		addedge(x,y,l),addedge(y,x,l);
	}
	dijkstra();
	for(int i=1;i<=n;i++)ns[i]=i;
	sort(ns+1,ns+1+n,com);
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	for(int i=2;i<=n;i++){
		int u=ns[i];
		ll cnt=0;
		vis[u]=1;
		for(int j=head[u];j;j=es[j].next){
			int v=es[j].v,w=es[j].w;
			if(vis[v]&&(dis[v]+w==dis[u]))cnt++;
		}
		ans=(cnt*ans)%mod;
	}
	printf("%lld",ans%mod);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}