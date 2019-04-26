/*
带权并查集
连通块是同一列
sz 是一列的战舰数，存在这一列的fa里
pre 是一列中，某一战舰前面有多少战舰
*/
#include<cstdio>
#include<cstdlib> //这个库里有int的abs，cmath里面都是对于实数的，qwq

using namespace std;

typedef long long ll;

const int MAXN=3e4+10;
const int MAXM=30;
const int INF=0x3f3f3f3f;

int T,fa[MAXN],sz[MAXN],pre[MAXN];

inline void init(){
	for(int i=1;i<=30000;i++)fa[i]=i,sz[i]=1;
}

int getFa(int x){
	if(x==fa[x])return x;
	int pf=fa[x];
	fa[x]=getFa(fa[x]);
	pre[x]+=pre[pf];
	return fa[x];
}

void solve(){
	init();
	scanf("%d",&T);
	while(T--){
		char s[5];
		int x,y;
		scanf("%s%d%d",s,&x,&y);
		if(s[0]=='M'){
			int xf=getFa(x),yf=getFa(y);
			fa[xf]=yf;
			pre[xf]+=sz[yf];
			sz[yf]+=sz[xf];
		}else if(s[0]=='C'){
			int xf=getFa(x),yf=getFa(y);
			if(xf==yf)printf("%d\n",abs(pre[x]-pre[y])-1);
			else puts("-1");
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}