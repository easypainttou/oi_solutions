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
const int maxn=3e4+5;
const int maxm=3e5+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct edge{
	int v,next;
}es[2*maxn];
struct node{
	int maxnum,sum;
}tree[4*maxn];
int n,tot,cnt,head[maxn],pw[maxn],q,dep[maxn],fa[maxn],size[maxn],son[maxn],id[maxn],w[maxn],top[maxn];

int read(){
	int res=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())res=res*10+ch-'0';
	return res*f;
}

inline void addEdge(int u,int v){
	es[++tot].v=v,es[tot].next=head[u],head[u]=tot;
}

inline void pushup(int p){
	tree[p].maxnum=max(tree[lson].maxnum,tree[rson].maxnum);
	tree[p].sum=tree[lson].sum+tree[rson].sum;
}

void build(int s,int t,int p){
	if(s==t){
		tree[p].maxnum=tree[p].sum=w[s];
		return;
	}
	int m=(s+t)>>1;
	build(s,m,lson);
	build(m+1,t,rson);
	pushup(p);
}

void upd(int x,int c,int s,int t,int p){
	if(s==x&&t==x){
		tree[p].maxnum=tree[p].sum=c;
		return;
	}
	int m=(s+t)>>1;
	if(x<=m)upd(x,c,s,m,lson);
	if(x>m)upd(x,c,m+1,t,rson);
	pushup(p);
}

int qMax(int l,int r,int s,int t,int p){
	if(l<=s&&t<=r){
		return tree[p].maxnum;
	}
	int m=(s+t)>>1,res=-maxn;
	if(l<=m)res=max(res,qMax(l,r,s,m,lson));
	if(r>m)res=max(res,qMax(l,r,m+1,t,rson));
	return res;
}

int qSum(int l,int r,int s,int t,int p){
	if(l<=s&&t<=r){
		return tree[p].sum;
	}
	int m=(s+t)>>1,res=0;
	if(l<=m)res+=qSum(l,r,s,m,lson);
	if(r>m)res+=qSum(l,r,m+1,t,rson);
	return res;
}

void dfs1(int u,int f){
	dep[u]=dep[f]+1;
	fa[u]=f;
	size[u]=1;
	for(int i=head[u];i;i=es[i].next){
		int v=es[i].v;
		if(f==v)continue;
		dfs1(v,u);
		size[u]+=size[v];
		if(size[son[u]]<size[v])son[u]=v;
	}
}

void dfs2(int u,int t){
	id[u]=++cnt;
	w[id[u]]=pw[u];
	top[u]=t;
	if(!son[u])return;
	dfs2(son[u],t);
	for(int i=head[u];i;i=es[i].next){
		int v=es[i].v;
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}

int qRangeMax(int x,int y){
	int res=-maxn;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		res=max(res,qMax(id[top[x]],id[x],1,n,1));
		x=fa[top[x]];
	}
	if(dep[x]<dep[y])swap(x,y);
	res=max(res,qMax(id[y],id[x],1,n,1));
	return res;
}

int qRangeSum(int x,int y){
	int res=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		res+=qSum(id[top[x]],id[x],1,n,1);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y])swap(x,y);
	res+=qSum(id[y],id[x],1,n,1);
	return res;
}

void solve(){
	n=read();
	int a,b;
	for(int i=1;i<=n-1;i++)a=read(),b=read(),addEdge(a,b),addEdge(b,a);
	for(int i=1;i<=n;i++)pw[i]=read();
	dfs1(1,0),dfs2(1,1),build(1,n,1);
	q=read();
	char s[10];
	int u,v;
	while(q--){
		scanf("%s",s);
		u=read(),v=read();
		if(s[1]=='H'){
			upd(id[u],v,1,n,1);
		}else if(s[1]=='M'){
			printf("%d\n",qRangeMax(u,v));
		}else if(s[1]=='S'){
			printf("%d\n",qRangeSum(u,v));
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}