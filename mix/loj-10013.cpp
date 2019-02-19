/*
eps卡精度。。。
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const double eps=1e-10;

int T,n,a[maxn],b[maxn],c[maxn];

double fun(double x){
	double maxnum=-inf;
	for(int i=1;i<=n;i++)maxnum=max(maxnum,a[i]*x*x+b[i]*x+c[i]);
	return maxnum;
}
void solve(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",a+i,b+i,c+i);
		double l=0,r=1000;
		while(fabs(l-r)>eps){
			double mid1=l+(r-l)/3,mid2=r-(r-l)/3;
			if(fun(mid1)<fun(mid2))r=mid2;
			else l=mid1;
		}
		printf("%.4f\n",fun(l));
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}