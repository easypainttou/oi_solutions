/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;

int n,m,x[maxn];

bool check(int dis){
	int cnt=1,p=1;
	for(int i=2;i<=n;i++){
		if(x[i]-x[p]>=dis)cnt++,p=i;
	}
	return cnt>=m;
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",x+i);
	sort(x+1,x+n+1);
	int ans,l=0,r=inf;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}