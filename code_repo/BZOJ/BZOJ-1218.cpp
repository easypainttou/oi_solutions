/*
...qwq坐标从0开始呢
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+1;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
const int mod=9901;
typedef long long ll;

int n,R,g[maxn+5][maxn+5],ans,len;


void solve(){
	scanf("%d%d",&n,&R);
	int x,y,v;
	len=R;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&v);
		g[x+1][y+1]+=v;
		len=max(len,max(x+1,y+1));
	}
	for(int i=1;i<=len;i++)
		for(int j=1;j<=len;j++)
			g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
	for(int i=R;i<=len;i++)
		for(int j=R;j<=len;j++)
			ans=max(ans,g[i][j]-g[i-R][j]-g[i][j-R]+g[i-R][j-R]);
	printf("%d",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}