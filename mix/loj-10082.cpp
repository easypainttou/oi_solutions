/*
...WA在l初始值上？
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
const int maxn=7e2+5;
const int maxm=1e5+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct edge{
	int v,next;
	double w;
}es[maxm];
int n,head[maxn],tot,vis[maxn];
double dis[maxn];
char str[1005];

inline void addEdge(int u,int v,double w){
	es[++tot].v=v,es[tot].w=w,es[tot].next=head[u],head[u]=tot;
}

bool spfa(int x,double mid){
	vis[x]=1;
	for(int i=head[x];i;i=es[i].next){
		int v=es[i].v;
		double w=es[i].w;
		if(dis[v]<dis[x]+w-mid){
			dis[v]=dis[x]+w-mid;
			if(vis[v])return 1;
			if(spfa(v,mid))return 1;
		}
	}
	vis[x]=0;
	return 0;
}

bool check(double mid){
	for(int i=1;i<=26*26;i++){
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		if(spfa(i,mid))return 1;
	}
	return 0;
}


void solve(){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		memset(head,0,sizeof(head));
		memset(es,0,sizeof(es));
		tot=0;
		double l=1005,r=0;
		for(int i=1;i<=n;i++){
			scanf("%s",str);
			int len=strlen(str);
			if(len<2)continue;
			int u=26*(str[0]-'a')+str[1]-'a'+1,v=26*(str[len-2]-'a')+str[len-1]-'a'+1;
			addEdge(u,v,len);
			l=0,r=max(r,double(len));
		}
		double ans;
		bool f=0;
		while(fabs(l-r)>eps){
			double mid=(l+r)/2;
			if(check(mid))f=1,l=mid,ans=mid;
			else r=mid;
		}
		if(!f)printf("No solution\n");
		else printf("%f\n",ans);
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}