/*
使用dfs，并查集判断连通性
fleury也行？
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int NODE=30;
const int MAXN=1e3+10;
const int MAXM=1e5+10;

struct edge{
	int v,next;
}es[MAXM];
int a,b,t,n,tot,head[NODE],ind[NODE],outd[NODE],fa[NODE];
char str[MAXN];
bool f;

inline void init(){
	f=a=b=tot=0;
	memset(es,0,sizeof(es));
	memset(head,0,sizeof(head));
	memset(ind,0,sizeof(ind));
	memset(outd,0,sizeof(outd));
	for(int i=1;i<=26;i++)fa[i]=i;
}

inline void addEdge(int u,int v){
	es[++tot].v=v,es[tot].next=head[u],head[u]=tot;
}

int findFa(int x){
	if(fa[x]==x)return x;
	return fa[x]=findFa(fa[x]);
}

inline void merge(int x,int y){
	int xf=findFa(x),yf=findFa(y);
	if(xf!=yf)fa[xf]=yf;
}

void solve(){
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",str);
			int x=str[0]-'a'+1,y=str[strlen(str)-1]-'a'+1;
			addEdge(x,y),++ind[y],++outd[x];
			merge(x,y);
		}
		for(int i=1;i<=26;i++){
			if(ind[i]!=outd[i]){
				if(ind[i]-outd[i]==1&&!a)a=i;
				else if(ind[i]-outd[i]==-1&&!b)b=i;
				else f=1;
			}
		}
		if(!(!a&&!b||a&&b))f=1;
		int pre=-1;
		for(int i=1;i<=26;i++){
			if(ind[i]||outd[i]){
				if(pre==-1)pre=findFa(i);
				else if(pre!=findFa(i)){f=1;break;}
			}
		}
		if(!f)puts("Ordering is possible.");
		else puts("The door cannot be opened.");		
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}