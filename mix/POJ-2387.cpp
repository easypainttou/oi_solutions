/*
...
*/
#include<queue>
#include<cstdio>
#include<cstring>
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
int T,N,head[maxn],tot,dis[maxn];
bool vis[maxn];

void addEdge(int u,int v,int w){
	es[++tot].v=v,es[tot].w=w,es[tot].next=head[u],head[u]=tot;
}

void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	priority_queue< pair<int,int> >q;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=es[i].next){
			int v=es[i].v,w=es[i].w;
			if(!vis[v]&&dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}

void solve(){
	scanf("%d%d",&T,&N);
	for(int i=1;i<=T;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		addEdge(x,y,z),addEdge(y,x,z);
	}
	dijkstra();
	printf("%d",dis[N]);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}