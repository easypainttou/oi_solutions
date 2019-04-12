/*
...
mi互质
使用CRT
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const int mod=9901;

ll n,a[15],b[15];

ll exGcd(ll a,ll b,ll&x,ll&y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll d=exGcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

ll crt(){
	ll ans=0,M=1;
	for(int i=1;i<=n;i++)M*=a[i];
	for(int i=1;i<=n;i++){
		ll m=M/a[i],x,y;
		exGcd(m,a[i],x,y);
		ll inv=(x%a[i]+a[i])%a[i];
		ans=(ans+m*inv%M*b[i]%M)%M;		
	}
	return ans;
}

void solve(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",a+i,b+i);
	printf("%lld",crt());
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 