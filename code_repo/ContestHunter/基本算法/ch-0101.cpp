/*
...
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
typedef long long ll;

ll a,b,p,ans=1;

void qPow(){
	while(b){
		if(b&1)ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
}

void solve(){
	scanf("%lld%lld%lld",&a,&b,&p);
	qPow();
	printf("%lld",ans%p);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}