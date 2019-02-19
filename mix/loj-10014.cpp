/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const double eps=1e-10;

int n,m,a[maxn];

bool check(int lim){
	int cnt=1,now=0;
	for(int i=1;i<=n;i++){
		if(now+a[i]>lim)now=a[i],++cnt;
		else now+=a[i];
	}
	return cnt>m;
}

void solve(){
	scanf("%d%d",&n,&m);
	int l=0,r=0,ans;
	for(int i=1;i<=n;i++)scanf("%d",a+i),l=max(l,a[i]),r+=a[i];
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1,ans=mid;
	}
	printf("%d",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}