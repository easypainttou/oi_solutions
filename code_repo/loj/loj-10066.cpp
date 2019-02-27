/*
...
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
const int maxn=300+5;
const int maxm=(1<<10)+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

int n,g[maxn][maxn],dis[maxn],vis[maxn];

int prim(){
	int ans=0;
	memset(dis,0x3f,sizeof(dis));
	priority_queue< pair<int,int> >q;
	q.push(make_pair(0,1));
	dis[1]=0;
	while(!q.empty()){
		int now=q.top().second;q.pop();
		if(vis[now])continue;
		vis[now]=1;
		ans+=dis[now];
		for(int i=1;i<=n+1;i++){
			if(vis[i])continue;
			if(g[now][i]<dis[i]){
				dis[i]=g[now][i];
				q.push(make_pair(-dis[i],i));
			}
		}
	}
	return ans;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&g[i][n+1]),g[n+1][i]=g[i][n+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
	printf("%d",prim());	
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}