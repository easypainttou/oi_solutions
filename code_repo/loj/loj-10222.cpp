/*
...
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>

using namespace std;

typedef long long ll;

const int MAXN=100+10;
const int MAXM=5;
const int INF=0x3f3f3f3f;

ll n,m,f[MAXN],tmp[MAXN];
struct matrix{
	ll A[MAXN][MAXN],n;
	
	matrix(int n=0):n(n){memset(A,0,sizeof(A));}
	
	matrix operator*(const matrix&a){
		matrix res(n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					res.A[i][k]=(res.A[i][k]+A[i][j]*a.A[j][k])%m;
		return res;	
	}
	
	void mulF(){
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				tmp[i]=(tmp[i]+A[i][j]*f[j])%m;
		memcpy(f,tmp,sizeof(tmp));
	}
}am;

matrix qPow(matrix a,ll b){
	matrix res(a.n);
	for(int i=0;i<res.n;i++)res.A[i][i]=1;
	while(b){
		if(b&1)res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}

void solve(){
	scanf("%lld%lld",&n,&m);
	am.n=4,am.A[0][0]=am.A[0][1]=am.A[1][1]=am.A[1][2]=am.A[2][2]=am.A[2][3]=am.A[3][2]=1;
	f[0]=1,f[1]=2,f[2]=2,f[3]=1;
	am=qPow(am,n-1);
	am.mulF();
	printf("%lld",(((1+n)*(f[1]-f[3])-f[0])%m+m)%m);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}