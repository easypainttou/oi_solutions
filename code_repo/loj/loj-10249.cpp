/*
...
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=2e3+10;
const int MAXM=500+10;

int n,m,a[MAXN],ans[MAXN];
bool bk[MAXM];

bool dfs(int s,int t,int b,int e,int dep){
	if(dep==n){
		if(s+t==a[n<<1]){
			for(int i=1;i<=n;i++)printf("%d ",ans[i]);
			return 1;
		}
		return 0;
	}
	int tmp=a[dep+1]-s;
	if(tmp>=1&&tmp<=500&&bk[tmp]){
		ans[b+1]=tmp;
		if(dfs(s+tmp,t,b+1,e,dep+1))return 1;
	}
	tmp=a[dep+1]-t;
	if(tmp>=1&&tmp<=500&&bk[tmp]){
		ans[e-1]=tmp;
		if(dfs(s,t+tmp,b,e-1,dep+1))return 1;
	}
	return 0;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n<<1;i++)scanf("%d",a+i);
	sort(a+1,a+(n<<1)+1);
	scanf("%d",&m);
	for(int tmp,i=1;i<=m;i++)scanf("%d",&tmp),bk[tmp]=1;
	dfs(0,0,0,n+1,0);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}