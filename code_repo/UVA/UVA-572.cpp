#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=100+5;

int m,n,cnt,bk[maxn][maxn];
char g[maxn][maxn];

void dfs(int x,int y,int cl){
	bk[x][y]=cl;
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++){
			int tx=x+i,ty=y+j;
			if(!(i==0&&j==0)
			&&(tx>=1&&tx<=m&&ty>=1&&ty<=n)
			&&g[tx][ty]=='@'&&!bk[tx][ty])
				dfs(tx,ty,cl);
		}
}

void solve(){
	while(1){
		scanf("%d%d",&m,&n);
		getchar();
		if(m==0&&n==0)break;
		cnt=0;
		memset(bk,0,sizeof(bk));
		for(int i=1;i<=m;i++)gets(g[i]+1);
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				if(g[i][j]=='@'&&!bk[i][j])dfs(i,j,++cnt);
		printf("%d\n",cnt);
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}