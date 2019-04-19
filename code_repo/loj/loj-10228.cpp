/*
lucas定理 板子
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=200+10;
const int MAXM=(1<<9)+10;

int T;
ll n,m,p;

ll qPow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}

ll getC(ll n,ll m){
	ll a=1,b=1;
	for(ll i=1;i<=m;i++)b=b*(n-i+1)%p,a=a*i%p;
	ll inv=qPow(a,p-2);
	return b*inv%p;
}

ll lucas(ll n,ll m){
	if(!m)return 1;
	return getC(n%p,m%p)*lucas(n/p,m/p)%p;
}

void solve(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&p);
		printf("%lld\n",lucas(n,m));
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}