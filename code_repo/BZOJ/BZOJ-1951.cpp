/*
...
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=7e4;
const int MAXM=(1<<9)+10;
const int MOD=999911659;

//lucas定理中，p为质数，999911658不是质数，所以要分解为2,3,4679,35617，就能使用lucas，然后用一下crt...
ll N,G,ps[]={2,3,4679,35617},a[4],fac[MAXN];

void init(){
	fac[0]=1;
	for(int i=1;i<=ps[3];i++)fac[i]=fac[i-1]*i%(MOD-1);
}

ll qPow(ll a,ll b,ll p){
	ll res=1;
	while(b){
		if(b&1)res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}

ll getC(ll n,ll m,ll p){
	if(n<m)return 0; //一直wa在这，qwq
	ll inv=qPow(fac[m]*fac[n-m]%p,p-2,p);
	return inv*fac[n]%p;
}

ll lucas(ll n,ll m,ll p){
	if(!m)return 1;
	return getC(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}

ll crt(){
	ll res=0,M=MOD-1;
	for(int i=0;i<4;i++){
		ll mi=M/ps[i],inv=qPow(mi,ps[i]-2,ps[i]);
		res=(res+mi*inv%M*a[i]%M)%M;
	}
	return res;
}

void solve(){
	scanf("%lld%lld",&N,&G);
	if(G%MOD==0){puts("0");return;} //wa在这，qwq
	init();
	for(int i=1;i*i<=N;i++){
		if(N%i==0){
			for(int j=0;j<4;j++)
				a[j]=(a[j]+lucas(N,i,ps[j]))%ps[j];
			if(i!=N/i)
				for(int j=0;j<4;j++)
					a[j]=(a[j]+lucas(N,N/i,ps[j]))%ps[j];
		}
	}
	printf("%lld",qPow(G,crt(),MOD));
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}