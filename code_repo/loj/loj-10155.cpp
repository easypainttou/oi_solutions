/*

不太理解...
从1开始一定能找到最长链，其他连通块不行qwq？

*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;

const int N=5e4+10;
const int M=40;
const int INF=0x3f3f3f3f;

struct edge{
	int v,next;
}eS[N<<1];
int n,head[N],tot,maxLen,maxId;
bool vis[N];

inline void addEdge(int u,int v){
	eS[++tot].v=v,eS[tot].next=head[u],head[u]=tot;
}

void dfs(int x,int num){
	vis[x]=1;
	if(num>maxLen){
		maxLen=num;
		maxId=x;
	}
	for(int i=head[x];i;i=eS[i].next){
		int v=eS[i].v;
		if(vis[v])continue;
		dfs(v,num+1);
	}
}

void solve(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int sum=1,sqr=sqrt(i);
		for(int j=2;j<=sqr;j++){
			if(i%j)continue;
			int tmp=i/j;
			if(j!=tmp)sum+=tmp;
			sum+=j;
		}
		if(sum>=i)continue;
		addEdge(i,sum);
		addEdge(sum,i);
	}
	dfs(1,0);
	maxLen=0;
	memset(vis,0,sizeof(vis));
	dfs(maxId,0);
	printf("%d",maxLen);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 