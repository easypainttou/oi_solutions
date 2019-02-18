/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;

int n,m;

void solve(){
	scanf("%d%d",&n,&m);
	int x,ans=0,now=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(now+x>m)ans++,now=x;
		else now+=x;
	}
	ans++;
	printf("%d",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}