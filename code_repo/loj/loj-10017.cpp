/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const double eps=1e-10;

int ax,ay,bx,by,cx,cy,dx,dy,p,q,r;

inline double calDis(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); 
}

inline double calTime(double div1,double div2){
	double px=(bx-ax)*div1+ax,py=(by-ay)*div1+ay,qx=(cx-dx)*div2+dx,qy=(cy-dy)*div2+dy;
	double dis1=calDis(ax,ay,px,py),dis2=calDis(px,py,qx,qy),dis3=calDis(qx,qy,dx,dy);
	return dis1/p+dis2/r+dis3/q;
}

double check(double div1){
	double l=0,r=1;
	while(fabs(r-l)>eps){
		double mid1=l+(r-l)/3,mid2=r-(r-l)/3;
		if(calTime(div1,mid1)<calTime(div1,mid2))r=mid2;
		else l=mid1;
	}
	return calTime(div1,l);
}

void solve(){
	scanf("%d%d%d%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&p,&q,&r);
	double l=0,r=1;
	while(fabs(r-l)>eps){
		double mid1=l+(r-l)/3,mid2=r-(r-l)/3;
		if(check(mid1)<check(mid2))r=mid2;
		else l=mid1;
	}
	printf("%.2f",check(l));
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}