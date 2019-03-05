/*
...货仓选址：选择中位数的位置，距离和最小
*/
#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
const int mod=9901;
const double eps=1e-5;
typedef long long ll;

int n,a[maxn];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	int pos;
	if(n&1)pos=(n>>1)+1;
	else pos=n>>1;
	int ans=0;
	for(int i=1;i<=pos;i++)ans+=a[pos]-a[i];
	for(int i=pos+1;i<=n;i++)ans+=a[i]-a[pos];
	printf("%d",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}