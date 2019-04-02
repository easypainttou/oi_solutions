#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int n,cnt,pri[maxn];
bool vis[maxn];
ll divv,ans=1;

void getPrime(){
	for(int i=2;i<=n;i++){
		if(!vis[i])pri[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(i*pri[j]>n)break;
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}

void solve(){
	scanf("%d",&n);
	getPrime();
	for(int i=1;i<=cnt;i++){
		divv=0;
		for(ll j=pri[i];j<=n;j*=pri[i])divv=(ll)(divv+n/j%mod)%mod;
		ans=(ll)ans*((2*divv+1)%mod)%mod;
	}
	printf("%lld",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 