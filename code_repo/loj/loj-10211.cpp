/*
...
*/

#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=5e7+10;
const int inf=0x3f3f3f3f;
const int mod=9901;

ll ans=1,a,b,divN[maxn],cnt[maxn],tot;

ll exGcd(ll a,ll b,ll&x,ll&y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll d=exGcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

ll qPow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

void getDiv(){
	ll tmp=a;
	for(ll i=2;i*i<=a;i++){
		if(tmp%i==0){
			divN[++tot]=i;
			while(tmp%i==0)++cnt[tot],tmp/=i;
		}
	}
	if(tmp>1)divN[++tot]=tmp,++cnt[tot];
}

void solve(){
	scanf("%lld%lld",&a,&b);
	getDiv();
	for(int i=1;i<=tot;i++){
		ll x0,y0,d=exGcd(divN[i]-1,mod,x0,y0);
		ans=ans*(qPow(divN[i],cnt[i]*b+1)-1)%mod*(x0%mod+mod)%mod;
	}
	printf("%lld",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 