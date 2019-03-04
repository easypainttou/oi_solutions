/*
floyd求闭包，然后排序
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e2+5;
const int inf=0x3f3f3f3f;
typedef long long ll;

int n,p[maxn],g[maxn][maxn],vis[maxn],np[maxn];
char str[maxn];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	p[n+1]=inf;
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		for(int j=1;j<=n;j++)g[i][j]=((str[j]=='1')?1:0);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=(g[i][j]|g[i][k]&g[k][j]);
	for(int i=1;i<=n;i++){
		int tmp=(vis[i]?(n+1):i);
		for(int j=1;j<=n;j++)
			if(!vis[j]&&g[i][j]&&p[j]<p[tmp])tmp=j;
		np[i]=p[tmp];
		vis[tmp]=1;
	}
	for(int i=1;i<=n;i++)printf("%d ",np[i]);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}