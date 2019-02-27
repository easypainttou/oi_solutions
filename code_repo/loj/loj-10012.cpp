/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const double eps=1e-5;
int n,L,a[maxn];
double c[maxn];

void solve(){
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	double l=0,r=2000;
	while(fabs(l-r)>eps){
		double mid=(l+r)/2;
		c[0]=0;
		for(int i=1;i<=n;i++)c[i]=c[i-1]+a[i]-mid;
		double minnum=inf,maxnum=-inf;
		for(int i=L;i<=n;i++){
			minnum=min(minnum,c[i-L]);
			maxnum=max(maxnum,c[i]-minnum);
		}
		if(maxnum>=0)l=mid;
		else r=mid;
	}
	printf("%d",int(r*1000));
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}