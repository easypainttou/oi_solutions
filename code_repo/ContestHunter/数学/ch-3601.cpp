/*
...
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const int maxm=15;
const int inf=0x3f3f3f3f;
const int mod=10007;

ll a,b,k,n,m,c[maxn][maxn];

ll qPow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

void solve(){
	scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
	//递推求组合数
	for(int i=1;i<=k;i++){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	printf("%lld",qPow(a,n)*qPow(b,m)%mod*c[k][m]%mod);
	
	
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}