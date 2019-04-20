/*
区间dp 环形合并石子 板子题
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=200+10;
const int MAXM=30;
const int INF=0x3f3f3f3f;

int n,mn,mx,a[MAXN<<1],sum[MAXN<<1],dp1[MAXN][MAXN],dp2[MAXN][MAXN];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),a[n+i]=a[i];
	for(int i=1;i<=n<<1;i++)sum[i]=sum[i-1]+a[i];
	for(int i=2;i<=n;i++){
		for(int j=1;j+i-1<=n<<1;j++){
			int L=j,R=j+i-1;
			dp1[L][R]=INF;
			for(int k=L;k+1<=R;k++){
				dp1[L][R]=min(dp1[L][R],dp1[L][k]+dp1[k+1][R]);
				dp2[L][R]=max(dp2[L][R],dp2[L][k]+dp2[k+1][R]);
			}
			dp1[L][R]+=sum[R]-sum[L-1];
			dp2[L][R]+=sum[R]-sum[L-1];
		}
	}
	mn=INF,mx=0;
	for(int i=1;i+n-1<=n<<1;i++){
		mn=min(mn,dp1[i][i+n-1]);
		mx=max(mx,dp2[i][i+n-1]);
	}
	printf("%d\n%d",mn,mx);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}