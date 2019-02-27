/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const double eps=1e-10;

int T;
double H,h,D;

double fun(double x){
	return x+(H*x-D*h)/(x-D);
}

void solve(){
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf",&H,&h,&D);
		double l=0,r=D*h/H;
		while(fabs(r-l)>eps){
			double mid1=l+(r-l)/3,mid2=r-(r-l)/3;
			if(fun(mid1)>fun(mid2))r=mid2;
			else l=mid1;
		}
		printf("%.3f\n",fun(l));
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}