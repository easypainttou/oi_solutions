/*
...
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
const int mod=9901;
typedef long long ll;

ll a,b,p[maxn],c[maxn],cnt;

ll qPow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}

ll sum(ll p,ll c){
	if(c==0)return 1%mod;
	if(c&1){
		ll tmp=sum(p,c-1>>1);
		return (tmp+qPow(p,c+1>>1)*tmp%mod)%mod;
	}else{
		ll tmp=sum(p,c>>1);
		return ((tmp+qPow(p,(c>>1)+1)*tmp%mod)%mod-qPow(p,c+1)+mod)%mod;
	}
}

void solve(){
	scanf("%lld%lld",&a,&b);
	for(ll i=2;i*i<=a;i++){
		if(a%i==0){
			p[++cnt]=i;
			while(a%i==0){
				a/=i;
				c[cnt]++;
			}
		}
	}
	if(a>1)p[++cnt]=a,c[cnt]++;
	ll ans=1;
	for(int i=1;i<=cnt;i++){
		ans=ans*sum(p[i],c[i]*b)%mod;
	}
	printf("%lld",ans%mod);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}