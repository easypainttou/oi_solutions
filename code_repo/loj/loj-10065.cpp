/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=500+5;
const int maxm=2e5;

struct edge{
	int u,v;
	double w;
	edge(int u=0,int v=0,double w=0):u(u),v(v),w(w){}
	bool operator<(const edge &a)const{
		return w<a.w;
	}
}es[maxm];

int n,k,x[maxn],y[maxn],tot,fa[maxn],cnt,ts[maxm];

inline double calDis(int a,int b){
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

inline void addedge(int u,int v){
	es[++tot].u=u,es[tot].v=v,es[tot].w=calDis(u,v);
}

int find(int x){
	return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}

void solve(){
	scanf("%d%d",&n,&k);
	if(k>=n){
		printf("0.00");
		return;
	}
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			addedge(i,j);
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(es+1,es+tot+1);
	for(int i=1;i<=tot;i++){
		int u=es[i].u,v=es[i].v;
		int uf=find(u),vf=find(v);
		if(uf!=vf){
			fa[uf]=vf;
			ts[++cnt]=i;
			if(cnt==n-1)break;
		}
	}
	if(k==0||k==1){
		printf("%.2f",es[ts[cnt]].w);
	}else printf("%.2f",es[ts[cnt-k+1]].w);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}