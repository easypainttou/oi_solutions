/*
做法1：枚举b1的约数
由题目得
gcd(x,a0)=a1
gcd(x,b0)=x*b0/b1
推出
gcd(x/a1,a0/a1)=1
gcd(b1/b0,b1/x)=1

做法2：枚举b1/a1的约数
由
gcd(x/a1,a0/a1)=1
gcd(b1/b0,b1/x)=1
推出
x/a1和b1/x是b1/a1的约数，于是直接枚举b1/a1的约数
更快。。。
详细见ch-3201

*/

#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

ll n,a0,a1,b0,b1,ans;

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

void solve(){
	scanf("%lld",&n);
	while(n--){
		ans=0;
		scanf("%lld%lld%lld%lld",&a0,&a1,&b0,&b1);
		ll p=a0/a1,q=b1/b0;
		for(ll i=1;i*i<=b1;i++){
			if(b1%i!=0)continue;
			ll x=i;
			if(x%a1==0&&gcd(x/a1,p)==1&&gcd(q,b1/x)==1)++ans;
			x=b1/i;
			if(x==i)continue;
			if(x%a1==0&&gcd(x/a1,p)==1&&gcd(q,b1/x)==1)++ans;		
		}
		printf("%lld\n",ans);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 