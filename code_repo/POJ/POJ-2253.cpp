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
const int maxn=2e2+5;
const int maxm=4e4+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct edge{
	int v,next;
	double w;
}es[maxm];
int n,head[maxn],tot,x[maxn],y[maxn];
double dis[maxn];
bool vis[maxn];

inline double getDis(int a,int b){
	return sqrt((double)(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

inline void addEdge(int u,int v,double w){
	es[++tot].v=v,es[tot].w=w,es[tot].next=head[u],head[u]=tot;
}

void dijkstra(){
	//memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i]=inf;
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	priority_queue< pair<double,int> >q;
	while(!q.empty())q.pop();
	q.push(make_pair(0,1));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=es[i].next){
			int v=es[i].v;
			double w=es[i].w;
			if(!vis[v]&&dis[v]>max(dis[u],w)){
				dis[v]=max(dis[u],w);
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}

void solve(){
	int cnt=0;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		++cnt;
		memset(es,0,sizeof(es));
		memset(head,0,sizeof(head));
		tot=0;
		for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				double d=getDis(i,j);
				addEdge(i,j,d),addEdge(j,i,d);
			}
		dijkstra();
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",cnt,dis[2]);
		
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}