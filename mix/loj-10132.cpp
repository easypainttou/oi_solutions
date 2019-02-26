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
const int maxm=2e5+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct edge{
	int v,w,next;
}es[maxm];
int head[maxn],tot,n,m,fa[maxn][25],dep[maxn],dfn[maxn],id[maxn],cnt;
ll ans,dis[maxn];
set<int> st;

int read(){
	int ans=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())ans=ans*10+ch-'0';
	return ans*f;
}

inline void addEdge(int u,int v,int w){
	es[++tot].v=v,es[tot].w=w,es[tot].next=head[u],head[u]=tot;
}

void dfs1(int u,int f){
	fa[u][0]=f;
	dep[u]=dep[f]+1;
	for(int i=1;i<=20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=es[i].next){
		int v=es[i].v,w=es[i].w;
		if(f==v)continue;
		dis[v]=dis[u]+w;
		dfs1(v,u);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
		if(x==y)return x;
	}
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}

inline ll qDis(int x,int y){
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}

void dfs2(int u){
	dfn[u]=++cnt;
	id[dfn[u]]=u;
	for(int i=head[u];i;i=es[i].next){
		int v=es[i].v;
		if(v==fa[u][0])continue;
		dfs2(v);
	}
}

void solve(){
	n=read();
	int x,y,z;
	for(int i=1;i<=n-1;i++)x=read(),y=read(),z=read(),addEdge(x,y,z),addEdge(y,x,z);
	dfs1(1,0),dfs2(1);
	m=read();
	while(m--){
		char ch[5];
		scanf("%s",ch);
		if(ch[0]=='+'){
			x=read();
			st.insert(dfn[x]);
			it p=st.find(dfn[x]),l=p,r=p;
			if(l==st.begin())l=--st.end();
			else l--;
			if(r==--st.end())r=st.begin();
			else r++;
			int le=*l,re=*r;
			ans=ans-qDis(id[le],id[re])+qDis(id[le],x)+qDis(x,id[re]);
		}
		else if(ch[0]=='-'){
			x=read();
			it p=st.find(dfn[x]),l=p,r=p;
			if(l==st.begin())l=--st.end();
			else l--;
			if(r==--st.end())r=st.begin();
			else r++;
			int le=*l,re=*r;
			st.erase(dfn[x]);
			ans=ans+qDis(id[le],id[re])-(qDis(id[le],x)+qDis(x,id[re]));
		}
		else if(ch[0]=='?'){
			printf("%lld\n",ans/2);
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}