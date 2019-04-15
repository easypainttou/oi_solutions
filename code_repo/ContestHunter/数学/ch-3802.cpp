/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int maxm=2e5+10;
const int inf=0x3f3f3f3f;

struct edge{
	int v,w,next;
}es[maxm];
int head[maxn],tot,n,m,ind[maxn],outd[maxn];
double prob[maxn],ans;
queue<int>q;

inline void addEdge(int u,int v,int w){
	es[++tot].v=v,es[tot].w=w,es[tot].next=head[u],head[u]=tot;
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addEdge(a,b,c);
		++outd[a],++ind[b];
	}
	prob[1]=1,q.push(1);
	while(!q.empty()){
		int u=q.front();q.pop();
		double nowProb=prob[u]*1.0/outd[u];
		for(int i=head[u];i;i=es[i].next){
			int v=es[i].v,w=es[i].w;
			ans+=w*nowProb;
			prob[v]+=nowProb;
			if(--ind[v]==0)q.push(v);
		}
	}
	printf("%.2lf",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}