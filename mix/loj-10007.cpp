/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+5;

int n,id[maxn],a[maxn],b[maxn];

bool com(int x,int y){
	return b[x]<b[y];
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",a+i,b+i),id[i]=i;
	sort(id+1,id+n+1,com);
	int s=0,k=0;
	for(int i=1;i<=n;i++){
		int cur=id[i];
		if(a[cur]>=s)++k,s=b[cur];
	}
	printf("%d",k);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}