#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;

const int MAXN=1e5+5;
const int MAXM=(1<<16)+5;
const int INF=0x3f3f3f3f;
const int MOD=10007;

char tab1[30],tab2[30],s1[MAXN],s[MAXN];
int t,n,nxt[MAXN];

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
		scanf("%s%s",tab1,s1+1);
		for(int i=0;i<26;i++)tab2[tab1[i]-'a']=i+'a';
		n=strlen(s1+1);
		for(int i=1;i<=n+1>>1;i++)s[i]=tab2[s1[i]-'a'];
		for(int i=(n+1>>1)+1;i<=n;i++)s[i]=s1[i];
		s[n+1]=0;
		preKmp();
		int i;
		for(i=nxt[n];i;i=nxt[i])if(i<=n>>1)break;
		printf("%s",s1+1);
		for(int j=i+1;j<=n-i;j++)printf("%c",tab2[s1[j]-'a']);puts("");
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
