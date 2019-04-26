/*
...
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int MAXN=200+10;
const int MAXM=30;
const int INF=0x3f3f3f3f;

int W,H,sg[MAXN][MAXN];
bool vis[MAXN];

int dfs(int w,int h){
	if(sg[w][h]!=-1)return sg[w][h];
	int mx=0;
	memset(vis,0,sizeof(vis));
	for(int i=2;i<=w-i;i++){
		int sg1=dfs(i,h),sg2=dfs(w-i,h);
		mx=max(mx,sg1^sg2),vis[sg1^sg2]=1;
	}
	for(int i=2;i<=h-i;i++){
		int sg1=dfs(w,i),sg2=dfs(w,h-i);
		mx=max(mx,sg1^sg2),vis[sg1^sg2]=1;
	}
	for(int i=0;i<=mx+1;i++){
		if(!vis[i]){
			sg[w][h]=i;
			break;
		}
	}
	return sg[w][h];
}

void solve(){
	memset(sg,0xff,sizeof(sg));
	sg[2][3]=sg[3][2]=sg[2][2]=0;
	while(~scanf("%d%d",&W,&H)){
		if(dfs(W,H))puts("WIN");
		else puts("LOSE");
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}