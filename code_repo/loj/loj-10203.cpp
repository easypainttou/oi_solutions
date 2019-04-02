#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

ll n,ans,ansC,pri[11]={0,2,3,5,7,11,13,17,19,23,29};

void dfs(ll dep,ll tmp,ll num,ll up){
	if(dep==10){
		if(num>ansC||num==ansC&&ans>tmp){
			ansC=num,ans=tmp;
		}
		return;
	}
	for(ll i=0;i<=up;i++){
		if(tmp>n)break;
		dfs(dep+1,tmp,num*(i+1),i);
		tmp*=pri[dep+1];
	}
}

void solve(){
	scanf("%lld",&n);
	dfs(0,1,1,64);
	printf("%lld",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 