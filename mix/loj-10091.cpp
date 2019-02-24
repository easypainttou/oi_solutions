/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e4+5;
const int maxm=5e4+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct edge{
	int v,next;
}es[maxm];
int n,m,tot,head[maxn],cnt,dfn[maxn],low[maxn],instack[maxn],cc,col[maxn],colcnt[maxn],outd[maxn];
stack<int>s;

inline void addEdge(int u,int v){
	es[++tot].v=v,es[tot].next=head[u],head[u]=tot;
}

void tarjan(int x){
	dfn[x]=low[x]=++cnt;
	s.push(x);
	instack[x]=1;
	for(int i=head[x];i;i=es[i].next){
		int v=es[i].v;
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}else if(instack[v]){
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(dfn[x]==low[x]){
		int crt;
		cc++;
		do{
			crt=s.top();s.pop();
			instack[crt]=0;
			col[crt]=cc;
			colcnt[cc]++;
		}while(crt!=x);
	}
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		addEdge(a,b);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)for(int j=head[i];j;j=es[j].next)if(col[i]!=col[es[j].v])outd[col[i]]++;//如何统计出度qwq
	int num=0,cp;
	for(int i=1;i<=cc;i++)if(!outd[i])cp=i,num++;
	if(num==1)printf("%d",colcnt[cp]);
	else puts("0");
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}