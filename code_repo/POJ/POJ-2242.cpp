#include<cstdio>
#include<cmath>
//#include<iostream>

using namespace std;
const double pi=acos(-1);

inline double dis(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

inline double area2(double x1,double y1,double x2,double y2,double x3,double y3){
	return fabs(x1*y2-y1*x2+x2*y3-y2*x3+x3*y1-y3*x1);
}
void solve(){
	double x1,y1,x2,y2,x3,y3,d;
	while(~scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)){
		d=dis(x1,y1,x2,y2)*dis(x1,y1,x3,y3)*dis(x3,y3,x2,y2)/area2(x1,y1,x2,y2,x3,y3);
		printf("%.2f\n",pi*d);
	}
}

int main(){
	//freopen("out","w",stdout);
	solve();
	return 0;
}