#include<cstdio>

using namespace std;
typedef long long ll;

const int MAXN=2e5+5;
const int MAXM=(1<<16)+5;
const int INF=0x3f3f3f3f;
const int MOD=10007;

char s[MAXN];
int t,n,dp[MAXN],nxt[MAXN],ans;

void preKmp(){
	int j=nxt[1]=0;
	for(int i=1;i<n;i++){
		while(j>0&&s[j+1]!=s[i+1])j=nxt[j];
		if(s[j+1]==s[i+1])j++;
		nxt[i+1]=j;
	}
}

void solve(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,s+1);
		preKmp();
		ans=0,dp[0]=0;
		for(int i=1;i<=n;i++){
			dp[i]=(dp[nxt[i]]+1)%MOD;
			ans=(ans+dp[i])%MOD;
		}
		printf("%d\n",ans);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
