/*

多重背包
二进制优化

*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=200+5;
const int MAXM=2e4+10;

int n,b[MAXN],c[MAXN],k,newB[MAXN*20],newC[MAXN*20],newN,dp[MAXM];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	scanf("%d",&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c[i];j<<=1){
			newB[++newN]=j*b[i];
			newC[newN]=j;
			c[i]-=j;
		}
		if(c[i]){
			newB[++newN]=c[i]*b[i];
			newC[newN]=c[i];
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=newN;i++){
		for(int j=k;j>=newB[i];j--){
			dp[j]=min(dp[j],dp[j-newB[i]]+newC[i]);
		}
	}
	printf("%d",dp[k]);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}