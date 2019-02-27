/*
...
*/
#include<bits/stdc++.h>
#define lson p<<1
#define rson p<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const int maxm=1e6+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct edge{
	int v,next;
}es[2*maxn];
int n,q,tot,head[maxn],fa[maxn][25],dep[maxn];

int read(){
	int ans=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())ans=ans*10+ch-'0';
	return ans*f;
}

inline void addEdge(int u,int v){
	es[++tot].v=v,es[tot].next=head[u],head[u]=tot;
}

void dfs(int u,int f){
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(int i=1;i<=20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=es[i].next){
		int v=es[i].v;
		if(v==f)continue;
		dfs(v,u);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
		if(x==y)return x;
	}
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i],y=fa[y][i];
		}
	}
	return fa[x][0];
}

void solve(){
	n=read();
	int x,y;
	for(int i=1;i<=n-1;i++)x=read(),y=read(),addEdge(x,y),addEdge(y,x);
	dfs(1,0);
	q=read();
	while(q--){
		x=read(),y=read();
		printf("%d\n",dep[x]+dep[y]-2*dep[lca(x,y)]);
	}
	
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}