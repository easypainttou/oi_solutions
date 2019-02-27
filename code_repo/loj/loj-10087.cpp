/*
...待研究求出的解？qwq
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
const int maxn=5e4+5;
const int maxm=2e5+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct edge{
	int v,w,next;
}es[maxm];
int head[maxn],n,tot,dis[maxn],vis[maxn],maxnum,minnum;

void addEdge(int u,int v,int w){
	es[++tot].v=v,es[tot].w=w,es[tot].next=head[u],head[u]=tot;
}

void spfa(){
	queue<int>q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push(maxnum);
	dis[maxnum]=0;
	vis[maxnum]=1;
	while(!q.empty()){
		int now=q.front();q.pop();
		vis[now]=0;
		for(int i=head[now];i;i=es[i].next){
			int v=es[i].v,w=es[i].w;
			if(dis[v]>dis[now]+w){
				dis[v]=dis[now]+w;
				if(!vis[v])q.push(v),vis[v]=1;
			}
		}
	}
}

void solve(){
	maxnum=0,minnum=maxn;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addEdge(b+2,a-1+2,-c);
		maxnum=max(maxnum,b+2);
		minnum=min(minnum,a+1);
	}
	for(int i=minnum;i<=maxnum;i++){
		addEdge(i,i-1,0),addEdge(i-1,i,1);
	}
	spfa();
	printf("%d",-dis[minnum]);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}