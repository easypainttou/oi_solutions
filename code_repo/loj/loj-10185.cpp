/*

考虑前i个任务（考虑S对这一批及之后全部任务的贡献），的最小费用  dp[i]=min(dp[k]+sT[i]*(sC[i]-sC[k])+S*(sC[n]-sC[k]))  0<=k<=i-1
时间复杂度：O(n^2)

斜率优化：
决策点j在直线上：dp[j]=(sT[i]+S)*sC[j]+dp[i]-sT[i]*sC[i]-S*sC[n]
将dp[j]作为纵坐标，sC[j]作为横坐标，dp[i]最小就是截距最小，在一个下凸点取到
sC[j]是单调递增的，sT[i]+S是单调递增的
所以用单调队列维护斜率恰好大于sT[i]+S的决策点，单调队列中的相邻2个决策点的线段的斜率是递增的，用队首更新dp[i]的最小值，然后把下一个决策点加入
时间复杂度：O(n)

qwq具体看代码

*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e4+5;
const int MAXM=2e4+10;

int n,s,t,c,st[MAXN],sc[MAXN],dp[MAXN],head,tail,q[MAXN];

void solve(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)scanf("%d%d",&t,&c),st[i]=st[i-1]+t,sc[i]=sc[i-1]+c;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0,head=1,tail=1,q[1]=0;
	for(int i=1;i<=n;i++){
		int k=st[i]+s;
		while(head<tail&&dp[q[head+1]]-dp[q[head]]<k*(sc[q[head+1]]-sc[q[head]]))++head;
		dp[i]=dp[q[head]]+st[i]*(sc[i]-sc[q[head]])+s*(sc[n]-sc[q[head]]);
		while(head<tail&&(dp[i]-dp[q[tail]])*(sc[q[tail]]-sc[q[tail-1]])<=(dp[q[tail]]-dp[q[tail-1]])*(sc[i]-sc[q[tail]]))--tail;
		q[++tail]=i;
	}
	printf("%d",dp[n]);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}