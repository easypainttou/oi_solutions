/*
...矩阵快速幂板子
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

ll n,m,F[MAXN],tmp[MAXN];

struct matrix{
	ll A[MAXN][MAXN],n;
	
	matrix(ll n=0):n(n){
		memset(A,0,sizeof(A));
	}
	
	matrix operator*(const matrix & a){
		matrix tmp(n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					tmp.A[i][k]=(tmp.A[i][k]+A[i][j]*a.A[j][k])%m;
		return tmp;
	}
	
	void mulF(ll f[]){
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				tmp[i]=(tmp[i]+A[i][j]*f[j])%m;
		memcpy(f,tmp,sizeof(tmp));
	}
	
	void output(){
		for(int i=0;i<n;i++,puts(""))
			for(int j=0;j<n;j++)
				printf("%lld ",A[i][j]);
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
	if(n==1||n==2){printf("%lld",1%m);return;}
	F[0]=F[1]=1,am.n=2,am.A[0][0]=am.A[0][1]=am.A[1][0]=1,am.A[1][1]=0;
	am=qPow(am,n-1);
	am.mulF(F);
	printf("%lld",F[1]);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}