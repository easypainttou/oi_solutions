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

ll n,m,t,s1[maxn],s2[maxn],ans;

void calc(ll &n,ll s[]){
	ll ave=t/n;
	for(int i=1;i<=n;i++)s[i]-=ave;
	for(int i=1;i<=n;i++)s[i]+=s[i-1];
	sort(s+1,s+n+1);
	int pos=((n&1)?((n>>1)+1):(n>>1));
	for(int i=1;i<=n;i++)ans+=abs(s[pos]-s[i]);
}


void solve(){
	scanf("%lld%lld%lld",&n,&m,&t);
	int x,y;
	for(int i=1;i<=t;i++){
		scanf("%d%d",&x,&y);
		++s1[x],++s2[y];
	}
	if(t%n==0&&t%m==0){
		calc(n,s1),calc(m,s2);
		printf("both %lld",ans);
	}
	else if(t%n==0){
		calc(n,s1);
		printf("row %lld",ans);
	}else if(t%m==0){
		calc(m,s2);
		printf("column %lld",ans);
	}else{
		printf("impossible");
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}