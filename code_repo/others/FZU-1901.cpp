#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

const int MAXN=1e6+5;
const int MAXM=(1<<16)+5;
const int INF=0x3f3f3f3f;
const int MOD=10007;

char s[MAXN];
int t,n,nxt[MAXN],ans[MAXN],cnt;

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
	for(int j=1;j<=t;j++){
		cnt=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		preKmp();
		for(int i=nxt[n];i;i=nxt[i]){
			ans[++cnt]=n-i;
		}ans[++cnt]=n;
		printf("Case #%d: %d\n",j,cnt);
		for(int i=1;i<=cnt;i++){
			if(i!=1)printf(" ");
			printf("%d",ans[i]);
		}puts("");
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
