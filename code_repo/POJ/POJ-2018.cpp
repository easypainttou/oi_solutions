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

int N,F;
double a[maxn],sum[maxn];

void solve(){
	double l=inf,r=0;
	scanf("%d%d",&N,&F);
	for(int i=1;i<=N;i++){
		scanf("%lf",a+i);
		l=min(l,a[i]),r=max(r,a[i]);
	}
	while(r-l>eps){
		double mid=(l+r)/2;
		for(int i=1;i<=N;i++)sum[i]=sum[i-1]+a[i]-mid;
		double minnum=inf,maxnum=-inf;
		for(int i=F;i<=N;i++){
			minnum=min(minnum,sum[i-F]);
			maxnum=max(maxnum,sum[i]-minnum);
		}
		if(maxnum>=0)l=mid;
		else r=mid;
	}
	printf("%d",int(r*1000));	//为何r才对qwq？
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}