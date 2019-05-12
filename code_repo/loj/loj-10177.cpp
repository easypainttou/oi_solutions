/*


从第1个考虑到第i个奶牛，不放第i个奶牛，的最大效率 dp[i][0]=max(dp[i-1][0],dp[i-1][1])
从第1个考虑到第i个奶牛，放第i个奶牛，的最大效率 dp[i][1]=max(dp[j][0]-s[j])+s[i]   max(i-k,0)<=j<i

再用单调队列优化max(dp[j][0]-s[j])  max(i-k,0)<=j<i 
时间复杂度就为O(n)

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e5+5;
const int MAXM=200+10;
const int INF=0x3f3f3f3f;
const int MOD=1e9;

int n,k,q[MAXN],head,tail;
ll s[MAXN],dp[MAXN][2];

void solve(){
	scanf("%d%d",&n,&k);
	ll tmp;
	for(int i=1;i<=n;i++){
		scanf("%lld",&tmp);
		s[i]=s[i-1]+tmp;
	}
	head=tail=1,q[tail]=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		while(head<=tail&&q[head]<i-k)++head;
		dp[i][1]=dp[q[head]][0]-s[q[head]]+s[i];
		while(head<=tail&&dp[q[tail]][0]-s[q[tail]]<=dp[i][0]-s[i])--tail;
		q[++tail]=i;
	}
	printf("%lld",max(dp[n][0],dp[n][1]));
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}