/*
状压dp 板子题
dp[i][j]：从第1行考虑到第i行，第i行放置方式为j，的方案总数

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=10+5;
const int INF=0x3f3f3f3f;
const int MOD=1e9;

int m,n,sum,g[MAXN],state[MAXN];
ll dp[MAXN][1<<MAXN];

void solve(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			int tmp;
			scanf("%d",&tmp);
			g[i]|=tmp<<j;
		}
	sum=1<<n;

	for(int i=0;i<m;i++){
		for(int j=0;j<sum;j++){
			if(!(j&(j<<1))&&!(j&(j>>1))&&((g[i]&j)==j)){
				if(i==0){
					dp[i][j]=1;
					continue;
				}
				for(int k=0;k<sum;k++){
					if(!(k&j)){
						dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<sum;i++)ans=(ans+dp[m-1][i])%MOD;
	printf("%lld",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}