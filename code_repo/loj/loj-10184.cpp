/*

sT是T的前缀和，sC是C的前缀和

考虑前i个任务，分成j批，的最小费用  dp[i][j]=min(dp[k][j-1]+(S*j+sT[i])*(sC[i]-sC[k]))  0<=k<=i-1
时间复杂度：O(n^3)

考虑前i个任务（考虑S对这一批及之后全部任务的贡献），的最小费用  dp[i]=min(dp[k]+sT[i]*(sC[i]-sC[k])+S*(sC[n]-sC[k]))  0<=k<=i-1
时间复杂度：O(n^2)

*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e3+5;
const int MAXM=2e4+10;

int n,s,t,c,st[MAXN],sc[MAXN],dp[MAXN];

void solve(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)scanf("%d%d",&t,&c),st[i]=st[i-1]+t,sc[i]=sc[i-1]+c;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			dp[i]=min(dp[i],dp[j]+st[i]*(sc[i]-sc[j])+s*(sc[n]-sc[j]));
		}
	}
	printf("%d",dp[n]);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}