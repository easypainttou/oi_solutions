/*

题意：求1~n的一个排列，使逆序数为m且字典序最小

解：可以考虑子问题：已经考虑了1~i-1的放置，考虑i的放置，i+1~n的排列最多产生tmp=(n-i)*(n-i-1)/2个逆序数，若m<=tmp，i在i~n的排列中，放在最前面是最优的，因为字典序小；若m>tmp，i在i~n的排列中，放在最后面是最优的，因为可以使后面的数字尽量不产生逆序，相对位置尽量不变，字典序就更小。

*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN=5e4+5;
const int MAXM=1e6+5;
const int INF=0x3f3f3f3f;
const int MOD=10007;

ll n,m,ans[MAXN],head,tail;

void solve(){
	scanf("%lld%lld",&n,&m);
	head=0,tail=n+1;
	for(ll i=1;i<=n;i++){
		ll tmp=(n-i)*(n-i-1)/2;
		if(m<=tmp)ans[++head]=i;
		else ans[--tail]=i,m-=n-i;
	}
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
