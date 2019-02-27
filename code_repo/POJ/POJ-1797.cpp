/*
...
*/
#include<cstdio>
#include<queue>
#include<cstring>
#define lson p<<1
#define rson p<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//typedef set<int>::iterator it;
const int inf=0x3f3f3f3f;
const int maxn=1e3+5;
const int maxm=2e6+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct edge{
	int v,w,next;
}es[maxm];
int T,n,m,head[maxn],tot,dis[maxn];
bool vis[maxn];

inline void addEdge(int u,int v,int w){
	es[++tot].v=v,es[tot].w=w,es[tot].next=head[u],head[u]=tot;
}

int read(){
	int res=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())res=res*10+ch-'0';
	return res*f;
}

void dijkstra(){
	priority_queue< pair<int,int> >q;
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	dis[1]=inf;
	q.push(make_pair(inf,1));
	while(!q.empty()){
		int now=q.top().second;
		q.pop();
		if(vis[now])continue;
		vis[now]=1;
		for(int i=head[now];i;i=es[i].next){
			int v=es[i].v,w=es[i].w;
			if(!vis[v]&&dis[v]<min(dis[now],w)){
				dis[v]=min(dis[now],w);
				q.push(make_pair(dis[v],v));
			}
		}
	}
}

void solve(){
	T=read();
	for(int i=1;i<=T;i++){
		memset(es,0,sizeof(es));
		memset(head,0,sizeof(head));
		tot=0;
		n=read(),m=read();
		int x,y,z;
		for(int j=1;j<=m;j++)x=read(),y=read(),z=read(),addEdge(x,y,z),addEdge(y,x,z);
		dijkstra();
		printf("Scenario #%d:\n%d\n\n",i,dis[n]);
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}