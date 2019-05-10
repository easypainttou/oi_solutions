/*
dp[i][j][q]：从第1行考虑到第i行，第i行放置方式为j，从第1行到第i行总共放置了q个国王，的方案总数
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=10+5;
const int MAXM=200+10;
const int INF=0x3f3f3f3f;
const int MOD=1e9;

int n,k,sum,cnt,num[MAXM],state[MAXM];
ll dp[MAXN][MAXM][MAXN*MAXN];

void solve(){
	scanf("%d%d",&n,&k);
	sum=1<<n;
	for(int i=0;i<sum;i++){
		if(!(!(i&i<<1)&&!(i&i>>1)))continue;
		int tot=0;
		for(int j=0;j<n;j++){
			tot+=(i>>j)&1;
		}
		state[++cnt]=i;
		num[cnt]=tot;
		
	}
	dp[0][1][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			for(int p=1;p<=cnt;p++){
				if(!(!(state[j]&state[p])&&!(state[j]<<1&state[p])&&!(state[j]>>1&state[p])))continue;
				for(int q=0;q<=k;q++){
					if(q<num[j])continue;
					dp[i][j][q]+=dp[i-1][p][q-num[j]];
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=cnt;i++)ans+=dp[n][i][k];
	printf("%lld",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}