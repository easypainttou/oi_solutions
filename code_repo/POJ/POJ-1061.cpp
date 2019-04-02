/*
...
*/

#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=3e3+10;
const int inf=0x3f3f3f3f;
//const int mod=1e9+7;

ll x,y,m,n,L;

ll exGcd(ll a,ll b,ll&x,ll&y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll d=exGcd(b,a%b,y,x);
	y-=x*(a/b); //注意这里的括号，a要除b取整，qwq
	return d;
}

void solve(){
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L);
	if(n==m){ //x不等于y，出现n==m就gg
		printf("Impossible");
		return;
	}
	if(n<m)swap(n,m),swap(x,y); //exgcd中的a不要是负数qwq
	ll x0,y0;
	ll d=exGcd(n-m,L,x0,y0);
	if((x-y)%d!=0){
		printf("Impossible");
	}else{
		ll mod=L/d;
		printf("%lld",((x-y)/d*x0%mod+mod)%mod);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 