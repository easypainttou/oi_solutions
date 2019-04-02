/*
...
线性同余方程模板题

*/

#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=3e3+10;
const int inf=0x3f3f3f3f;
//const int mod=1e9+7;

ll a,b;

ll exGcd(ll a,ll b,ll&x,ll&y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll d=exGcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

void solve(){
	scanf("%lld%lld",&a,&b);
	ll x0,y0,d=exGcd(a,b,x0,y0);
	ll mod=b/d;
	printf("%lld",(x0%mod+mod)%mod);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 