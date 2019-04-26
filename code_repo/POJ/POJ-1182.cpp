/*
带权并查集 种类并查集 板子

一个连通块内的关系是确定的，不同的连通块关系不确定
一个连通块的fa的rank为0...

*/
#include<cstdio>
#include<cctype>
using namespace std;

typedef long long ll;

const int MAXN=5e4+10;
const int MAXM=30;
const int INF=0x3f3f3f3f;

int n,k,ans,fa[MAXN],rank[MAXN];

int read(){
	int res=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())res=res*10+ch-'0';
	return res*f;
}

inline void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int getFa(int x){
	if(x==fa[x])return x;
	int pf=fa[x];
	fa[x]=getFa(fa[x]);
	rank[x]=(rank[x]+rank[pf])%3;
	return fa[x];
}

bool check(int x,int y,int d){
	int xf=getFa(x),yf=getFa(y);
	if(xf==yf){
		if((rank[x]+d)%3==rank[y])return 0;
		else return 1;
	}
	fa[yf]=xf;
	rank[yf]=((d-rank[y])%3+3+rank[x])%3;
	return 0;
}

void solve(){
	scanf("%d%d",&n,&k);
	init();
	while(k--){
		int d,x,y;
		d=read(),x=read(),y=read();
		if(x==y&&d==2)++ans;
		else if(x>n||y>n)++ans;
		else if(check(x,y,d-1))++ans;
	}
	printf("%d",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}