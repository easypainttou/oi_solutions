/*

题意&解：https://www.luogu.org/blog/JustinRochester/solution-p2158

*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN=4e4+5;
const int MAXM=1e6+5;
const int INF=0x3f3f3f3f;
const int MOD=10007;

int p[MAXN],cnt,phi[MAXN],n;
bool vis[MAXN];

void getPrime(){
	for(int i=2;i<=n;i++){
		if(!vis[i])p[++cnt]=i,phi[i]=i-1;
		for(int j=1;j<=cnt&&i*p[j]<=n;j++){
			vis[i*p[j]]=1;
			if(i%p[j]){
				phi[i*p[j]]=phi[i]*(p[j]-1);
			}else{
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
		}
	}
}

void solve(){
	scanf("%d",&n);
	if(n==1){printf("0");return;}
	getPrime();
	int ans=0;
	for(int i=2;i<=n-1;i++){
		ans+=phi[i];
	}
	ans=2*ans+3;
	printf("%d",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
