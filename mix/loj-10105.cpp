/*
...欧拉回路板子
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const int maxm=4e5+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct edge{
	int v,next;
}es[maxm];
int t,n,m,tot=1,head[maxn],in[maxn],out[maxn];
bool vis[maxm];
vector<int>ans;


inline void addEdge(int u,int v){
	es[++tot].v=v,es[tot].next=head[u],head[u]=tot;
}

void dfs(int u){
	for(int &i=head[u];i;i=es[i].next){ //要引用，不然T，QAQ
		int e=((t==1)?(i/2):(i-1));
		int flag=((i&1)?(-1):(1));
		if(vis[e])continue;
		vis[e]=1;
		dfs(es[i].v);
		if(t==1)ans.push_back(flag*e);
		else ans.push_back(e);
	}
}

void solve(){
	scanf("%d%d%d",&t,&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		if(t==1)addEdge(v,u);
		++out[u],++in[v];
	}
	if(t==1){
		for(int i=1;i<=n;i++){
			if((in[i]+out[i]&1)==1){
				printf("NO");return;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(in[i]!=out[i]){
				printf("NO");return;
			}
		}
	}
	for(int i=1;i<=n;i++)if(head[i]){dfs(i);break;}
	if(ans.size()!=m){printf("NO");return;}
	else{
		printf("YES\n");
		for(int i=m-1;i>=0;i--)printf("%d ",ans[i]);
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}