#include<cstdio>
#include<cmath>
#define f(x,y,z) for(int x=y;x<=z;x++)
using namespace std;
const double pi=3.1415;

void solve(){
	int t,ans;
	double x,y;
	scanf("%d",&t);
	f(i,1,t){
		scanf("%lf%lf",&x,&y);
		ans=int(ceil(pi*(x*x+y*y)/100));
		printf("Property %d: This property will begin eroding in year %d.\n",i,ans);
	}
	printf("END OF OUTPUT.");
}
int main(){
	solve();
	return 0;
}