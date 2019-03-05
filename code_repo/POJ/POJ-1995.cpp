/*
...
*/
#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
const int mod=9901;
const double eps=1e-5;
typedef long long ll;

ll z,m,h,a,b,ans;

ll qPow(){
	ll res=1%m;
	while(b){
		if(b&1)res=res*a%m;
		a=a*a%m;
		b>>=1;
	}
	return res%m;
}
void solve(){
	scanf("%lld",&z);
	while(z--){
		ans=0;
		scanf("%lld%lld",&m,&h);
		for(int i=1;i<=h;i++){
			scanf("%lld%lld",&a,&b);
			ans=(ans+qPow())%m;
		}
		printf("%lld\n",ans);
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}