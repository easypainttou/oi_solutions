/*
...
*/
#include<bits/stdc++.h>
#define lson p<<1
#define rson p<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//typedef set<int>::iterator it;
const int inf=0x6fffffff;
const int maxn=1e3+5;
const int maxm=2e6+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

int n,k,ans;

void dfs(int pre,int remain,int step){
	if(step==k){
		if(remain==0)++ans;
		return;
	}
	for(int i=pre;(k-step)*i<=remain;i++){
		dfs(i,remain-i,step+1);
	}
}


void solve(){
	scanf("%d%d",&n,&k);
	dfs(1,n,0);
	printf("%d",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}