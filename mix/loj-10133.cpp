/*
...
*/
#include<bits/stdc++.h>
#define lson p<<1
#define rson p<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef set<int>::iterator it;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const int maxm=3e5+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct edge{
	int v,w,next;
}es[2*maxn];
struct oedge{
	int u,v,w;
	bool operator<(const oedge & a)const{return w<a.w;}
}edges[maxm];
int n,m,head[maxn],tot,ff[maxn],fa[maxn][25],g[maxn][25][2],vis[maxm],dep[maxn],lg[maxn];
ll ans,nans;

int read(){
	int res=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())res=res*10+ch-'0';
	return res*f;
}

inline void addEdge(int u,int v,int w){
	es[++tot].v=v,es[tot].w=w,es[tot].next=head[u],head[u]=tot;
}

int find(int x){
	return (ff[x]==x)?x:(ff[x]=find(ff[x]));
}

void kruskal(){
	for(int i=1;i<=n;i++)ff[i]=i;
	sort(edges+1,edges+m+1);
	for(int j=0,i=1;i<=m;i++){
		int u=edges[i].u,v=edges[i].v,w=edges[i].w;
		int uf=find(u),vf=find(v);
		if(uf!=vf){
			vis[i]=1;
			ans+=w;
			++j;
			ff[uf]=vf;
			addEdge(u,v,w),addEdge(v,u,w);
			if(j==n-1)break;
		}
	}
}

void dfs(int u,int f){
	dep[u]=dep[f]+1;
	for(int i=1;(1<<i)+1<=dep[u];i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=1;(1<<i)+1<=dep[u];i++)g[u][i][0]=max(g[u][i-1][0],g[fa[u][i-1]][i-1][0]);
	for(int i=1;(1<<i)+1<=dep[u];i++){
		if(g[u][i-1][0]==g[fa[u][i-1]][i-1][0])g[u][i][1]=max(g[u][i-1][1],g[fa[u][i-1]][i-1][1]);
		else if(g[u][i-1][0]<g[fa[u][i-1]][i-1][0])g[u][i][1]=max(g[u][i-1][0],g[fa[u][i-1]][i-1][1]);
		else if(g[u][i-1][0]>g[fa[u][i-1]][i-1][0])g[u][i][1]=max(g[u][i-1][1],g[fa[u][i-1]][i-1][0]);
	}
	for(int i=head[u];i;i=es[i].next){
		int v=es[i].v,w=es[i].w;
		if(f==v)continue;
		fa[v][0]=u;
		g[v][0][0]=w;
		g[v][0][1]=-1;
		dfs(v,u);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=lg[dep[x]-dep[y]];i>=0;i--){
		if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
		if(x==y)return x;
	}
	for(int i=lg[dep[x]-1];i>=0;i--){
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}

inline void upd(int & max1,int &max2,int x,int i){
	if(max1==g[x][i][0])max2=max(max2,g[x][i][1]);
	else if(max1<g[x][i][0])max2=max(max1,g[x][i][1]);
	else if(max1>g[x][i][0])max2=max(max2,g[x][i][0]);
	max1=max(max1,g[x][i][0]);
}

inline void updMax(int x,int y,int &max1,int &max2){
	for(int i=lg[dep[x]-dep[y]];i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]){
			upd(max1,max2,x,i);
			x=fa[x][i];
		}
		if(x==y)break;
	}
}

void test(int x,int y,int id){
	int z=lca(x,y),xmax1=0,xmax2=0,ymax1=0,ymax2=0;
	updMax(x,z,xmax1,xmax2);
	updMax(y,z,ymax1,ymax2);
	int max1,max2;
	max1=max(xmax1,ymax1);
	if(xmax1==ymax1)max2=max(xmax2,ymax2);
	else if(xmax1<ymax1)max2=max(xmax1,ymax2);
	else if(xmax1>ymax1)max2=max(xmax2,ymax1);
	int w=edges[id].w;
	if(max1==w)nans=min(nans,ans-max2+w);
	else if(max1<w)nans=min(nans,ans-max1+w);
}

void solve(){
	n=read(),m=read();
	int x,y,z;
	for(int i=1;i<=m;i++)edges[i].u=read(),edges[i].v=read(),edges[i].w=read(),nans+=edges[i].w;
	kruskal();
	lg[0]=-1;
	for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1;
	dfs(1,0);
	for(int i=1;i<=m;i++){
		if(vis[i]||edges[i].u==edges[i-1].u&&edges[i].v==edges[i-1].v)continue;
		int x=edges[i].u,y=edges[i].v;
		test(x,y,i);
	}
	printf("%lld",nans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}