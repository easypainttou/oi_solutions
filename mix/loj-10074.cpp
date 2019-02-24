/*
...
*/
#include<queue>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e3+5;
const int maxm=4e3+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct edge{
	int v,w,next;
}es[maxm];
int head[maxn],n,p,k,dis[maxn],vis[maxn],tot;

void addEdge(int u,int v,int w){
	es[++tot].v=v,es[tot].w=w,es[tot].next=head[u],head[u]=tot;
}

bool dijkstra(int x){
	priority_queue< pair<int,int> >q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push(make_pair(0,1));
	dis[1]=0;
	while(!q.empty()){
		int now=q.top().second;
		q.pop();
		if(vis[now])continue;
		vis[now]=1;
		for(int i=head[now];i;i=es[i].next){
			int v=es[i].v,w=((es[i].w>x)?1:0);
			if(dis[v]>dis[now]+w){
				dis[v]=dis[now]+w;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
	return dis[n]<=k;
}

void solve(){
	int l=0,r=0;
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=p;i++){
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		addEdge(a,b,l),addEdge(b,a,l);
		r=max(r,l);
	}
	if(!dijkstra(r)){puts("-1");return;}
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(dijkstra(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}