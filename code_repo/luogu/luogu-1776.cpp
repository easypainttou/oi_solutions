/*

多重背包
单调队列优化

dp[u+j*v]=max(dp[u+k*v]+j*w-k*w)  j-c<=k<=j

用单调队列维护 dp[u+k*v]-k*w 的最大值就行

*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;

int N,V,v,w,s,dp[MAXN],ans,q[MAXN],q2[MAXN],head,tail;

void solve(){
	scanf("%d%d",&N,&V);
	for(int i=1;i<=N;i++){
		scanf("%d%d%d",&w,&v,&s);
		if(v==0){
			ans+=s*w;
			continue;
		}
		s=min(s,V/v);
		for(int i=0;i<v;i++){
			head=1,tail=0;
			int p=(V-i)/v;
			for(int j=0;j<=p;j++){
				int now=dp[i+j*v]-j*w;
				while(head<=tail&&q[head]<j-s)++head;
				while(head<=tail&&q2[tail]<=now)--tail;
				q[++tail]=j;
				q2[tail]=now;
				dp[i+j*v]=max(dp[i+j*v],q2[head]+j*w);
			}
		}
	}
	printf("%d",ans+dp[V]);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}