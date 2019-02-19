/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+5;

ll n,a[maxn];

void solve(){
	scanf("%lld",&n);
	ll ave=0;
	for(ll i=1;i<=n;i++)scanf("%lld",a+i),ave+=a[i];
	ave/=n;
	for(ll i=1;i<=n;i++)a[i]+=a[i-1]-ave;
	sort(a+1,a+n+1);
	ll ans=0,k=(1+n)/2;
	for(ll i=1;i<=n;i++)ans+=abs(a[i]-a[k]);
	printf("%lld",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}