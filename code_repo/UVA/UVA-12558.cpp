/*
去掉res相关代码，就是一个普通埃及分数问题qwq
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+5;

ll a,b,k,dep,v[maxn],ans[maxn];
set<int>res;

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

inline ll get(ll a,ll b){
	return b/a+1;
}

bool better(){
	for(ll i=dep;i>=0;i--){
		if(ans[i]!=v[i]){
			return v[i]<ans[i] || ans[i]==-1;
		}
	}
	return 0;
}


bool dfs(ll step,ll minn,ll a,ll b){
	if(step==dep){
		if(b%a==0){
			if(res.count(b/a))return 0;
			v[step]=b/a;
			if(better())memcpy(ans,v,sizeof(v));
			return 1;
		}
		return 0;
	}
	bool ok=0;
	minn=max(minn,get(a,b));
	for(ll i=minn;;i++){
		if(res.count(i))continue;
		if(b*(dep-step+1)<=a*i)break;
		ll aa=a*i-b,bb=b*i,g=gcd(aa,bb);
		v[step]=i;
		if(dfs(step+1,i+1,aa/g,bb/g))ok=1;
	}
	return ok;
}

void solve(){
	int t;
	scanf("%d",&t);
	for(int j=1;j<=t;j++){
		res.clear();
		scanf("%d%d%d",&a,&b,&k);
		int x;
		for(int i=1;i<=k;i++)scanf("%d",&x),res.insert(x);
		for(dep=1;;dep++){
			memset(ans,0xff,sizeof(ans));
			
			if(dfs(0,get(a,b),a,b)){
				
				printf("Case %d: %lld/%lld=",j,a,b);
				for(ll i=0;i<=dep;i++){
					if(i)printf("+");
					printf("1/%lld",ans[i]);
				}
				puts("");
				break;
			}
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}