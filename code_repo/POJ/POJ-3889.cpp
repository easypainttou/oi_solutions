/*
...qwq
*/
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=3e6+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
const int mod=9901;
typedef long long ll;

ll T,n,h,o;

void dfs(ll &x,ll &y,ll N,ll id){
	if(N==0){
		x=y=5;
		return;
	}
	ll len=10*(1<<N-1),num=1<<2*N-2,a=id/num,b=id%num,dx,dy;
	if(a==0){
		dfs(dx,dy,N-1,num-b-1);
		x=len-dy,y=dx;
	}else if(a==1){
		dfs(dx,dy,N-1,b);
		x=len+dx,y=dy;
	}else if(a==2){
		dfs(dx,dy,N-1,b);
		x=len+dx,y=len+dy;
	}else if(a==3){
		dfs(dx,dy,N-1,num-b-1);
		x=dy,y=2*len-dx;
	}
}

void solve(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&h,&o);
		ll hx,hy,ox,oy;
		dfs(hx,hy,n,h-1);
		dfs(ox,oy,n,o-1);
		printf("%lld\n",ll(0.5+sqrt((double)(hx-ox)*(hx-ox)+(hy-oy)*(hy-oy))));
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}