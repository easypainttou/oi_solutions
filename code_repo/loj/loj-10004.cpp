/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=500+5;

int m,n,id[maxn],t[maxn],w[maxn];
bool bk[maxn];

bool com(int a,int b){
	return w[a]>w[b];
}

void solve(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)scanf("%d",t+i),id[i]=i;
	for(int i=1;i<=n;i++)scanf("%d",w+i);
	sort(id+1,id+n+1,com);
	int ans=0;
	for(int i=1;i<=n;i++){
		int cur=id[i],j;
		for(j=t[cur];j>=1;j--)if(!bk[j])break;
		if(j==0)ans+=w[cur];
		else bk[j]=1;
	}
	printf("%d",m-ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}