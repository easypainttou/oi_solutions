/*
思维，2点是否在直线2侧，在则cnt++
*/
#include<cstdio>
using namespace std;
const int maxn=3e4+5;
typedef long long ll;

ll x1,y1,x2,y2,n,cnt,a,b,c;

int main(){
//	freopen("in.txt","r",stdin);
	scanf("%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&n);
	while(n--){
		scanf("%lld%lld%lld",&a,&b,&c);
		ll t1=(a*x1+b*y1+c),t2=(a*x2+b*y2+c);
		if(t1>0&&t2<0||t1<0&&t2>0)cnt++; //t1和t2相乘会爆long long qwq
	}
	printf("%lld",cnt);
	return 0;
}

