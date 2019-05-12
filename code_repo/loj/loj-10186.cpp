/*

dp[j]=(sT[i]+S)*sC[j]+dp[i]-sT[i]*sC[i]-S*sC[n]

和上一题相比，sT[i]+S不是单调的，单调队列中连接相邻2点的线段的斜率是单调的，所以二分出下凸点就行

qwq具体看代码

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=3e5+5;
const int MAXM=2e4+10;

ll n,s,t,c,st[MAXN],sc[MAXN],dp[MAXN],head,tail,q[MAXN];

ll read(){
	ll res=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())res=res*10+ch-'0';
	return res*f;
}

ll bSearch(ll k){
	ll L=head,R=tail,ans;
	if(L==R)return q[head];
	while(L<=R){ //这里的mid+1不会越界吗 qwq？
		ll mid=(L+R)>>1;
		if((dp[q[mid+1]]-dp[q[mid]])>=k*(sc[q[mid+1]]-sc[q[mid]]))ans=mid,R=mid-1;
		else L=mid+1;
	}
	return q[ans];
}

void solve(){
	scanf("%lld%lld",&n,&s);
	for(int i=1;i<=n;i++)t=read(),c=read(),st[i]=st[i-1]+t,sc[i]=sc[i-1]+c;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0,head=1,tail=1,q[1]=0;
	for(int i=1;i<=n;i++){
		ll pos=bSearch(st[i]+s);	
		dp[i]=dp[pos]+st[i]*(sc[i]-sc[pos])+s*(sc[n]-sc[pos]);
		while(head<tail&&(dp[i]-dp[q[tail]])*(sc[q[tail]]-sc[q[tail-1]])<=(dp[q[tail]]-dp[q[tail-1]])*(sc[i]-sc[q[tail]]))--tail;
		q[++tail]=i;
	}
	printf("%lld",dp[n]);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}