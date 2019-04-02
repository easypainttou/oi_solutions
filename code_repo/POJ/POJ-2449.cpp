#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e3+10;
const int maxm=1e5+10;

struct node{
	int u,g;
	node(int u,int g):u(u),g(g){}
};
struct edge{
	int v,w,next;
}es[maxm],rEs[maxm];
int n,m,s,t,k,tot,head[maxn],rHead[maxn],dis[maxn];
bool vis[maxn];

bool operator<(const node&a,const node&b){
	int fa=a.g+dis[a.u],fb=b.g+dis[b.u];
	if(fa==fb)return a.g>b.g;	//要这样比较，不然WA。。
	return fa>fb;
}

int read(){
	int f=1,res=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())res=res*10+ch-'0';
	return res*f;
}

inline void addEdge(int u,int v,int w){
	es[++tot].v=v,es[tot].w=w,es[tot].next=head[u],head[u]=tot;
	rEs[tot].v=u,rEs[tot].w=w,rEs[tot].next=rHead[v],rHead[v]=tot;//反向加边，最短路需要
}

void dijkstra(){//跑的是反向边qwq
	priority_queue< pair<int,int> >q;
	memset(dis,0x3f,sizeof(dis));
	dis[t]=0;
	q.push(make_pair(0,t));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=rHead[u];i;i=rEs[i].next){
			int v=rEs[i].v,w=rEs[i].w;
			if(vis[v])continue;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}

void aStar(){
	priority_queue<node>q;
	q.push(node(s,0));
	int cnt=0;
	if(s==t)++k;//WA点，qwq
	while(!q.empty()){
		node now=q.top();q.pop();
		int u=now.u;
		if(u==t)++cnt;
		if(cnt==k){
			printf("%d",now.g);
			return;
		}
		for(int i=head[u];i;i=es[i].next){
			int v=es[i].v,w=es[i].w;
			q.push(node(v,now.g+w));
		}
	}
	printf("-1");
}

void solve(){
	scanf("%d%d",&n,&m);
	int a,b,c;
	for(int i=1;i<=m;i++){
		a=read(),b=read(),c=read();
		addEdge(a,b,c);
	}
	scanf("%d%d%d",&s,&t,&k);
	dijkstra();
	aStar();
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}