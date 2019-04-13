/*
(10^x-1)/9*8=k*L
(10^x-1)*8=k*9*L
d=gcd(8,9*L)=gcd(8,L)
(10^x-1)*8/d=k*9*L/d
令p=8/d，q=9*L/d
(10^x-1)*p=k*q
因为gcd(p,q)=1
(10^x-1)=0(mod q)
10^x=1(mod q)

1. 10和q互质
10^phi(q)=1(mod q)
x=phi(q)是一个解，题目要输出x最小解，这里只要从小到大枚举phi(q)的约数(？)找就行

2. 10和q不互质
无解

*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;

ll L;

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

inline ll euler(ll x){
	ll res=1;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			res*=i-1;
			x/=i;
			while(x%i==0)x/=i,res*=i;
		}
	}
	if(x>1)res*=x-1;
	return res;
}

ll qMul(ll a,ll b,ll mod){ //乘法会溢出，要用快速乘qwq
	ll res=0;
	while(b){
		if(b&1)res=(res+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return res;
}

ll qPow(ll a,ll b,ll mod){
	ll res=1%mod;
	while(b){
		if(b&1)res=qMul(res,a,mod);
		a=qMul(a,a,mod);
		b>>=1;
	}
	return res;
}

void solve(){
	int kase=0;
	while(1){
		scanf("%lld",&L);
		if(L==0)break;
		printf("Case %d: ",++kase);
		ll d=gcd(8,L);
		ll mod=9*L/d;
		if(gcd(10,mod)==1){
			ll phi=euler(mod);
			ll m=sqrt(phi);
			for(ll i=1;i<=m;i++){
				if(phi%i)continue;
				if(qPow(10,i,mod)==1){
					printf("%lld",i);
					goto end;
				}
			}
			for(ll i=m;i>=1;i--){
				if(phi%i)continue;
				ll t=phi/i;
				if(qPow(10,t,mod)==1){
					printf("%lld",t);
					goto end;
				}
			}
		}else{
			printf("0");
		}
		end:;
		puts("");
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}