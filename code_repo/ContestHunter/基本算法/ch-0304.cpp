/*
...
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
const int mod=9901;
typedef long long ll;

int n,a[maxn],b[maxn];
ll p,q;

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),b[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++){
		if(b[i]>0)p+=b[i];
		if(b[i]<0)q-=b[i];
	}
	ll sum=abs(p-q),ans=min(p,q)+sum;
	printf("%lld\n%lld",ans,sum+1);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}