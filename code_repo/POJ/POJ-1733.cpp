/*
even： 1~x-1和1~y 1的个数的奇偶性相同
odd： 1~x-1和1~y 1的个数的奇偶性不同

还是带权并查集 种类并查集...
*/
#include<cstdio>
#include<map>
using namespace std;

typedef long long ll;

const int MAXN=1e4+10;
const int MAXM=30;
const int INF=0x3f3f3f3f;

int n,m,tot,ans,rk[MAXN],fa[MAXN];
map<int,int>mp;

inline void init(){
	for(int i=1;i<=m<<1;i++)fa[i]=i;
}

int getFa(int x){
	if(x==fa[x])return x;
	int pf=fa[x];
	fa[x]=getFa(fa[x]);
	rk[x]^=rk[pf];
	return fa[x];
}

bool check(int x,int y,int d){
	int xf=getFa(x),yf=getFa(y);
	if(xf==yf){
		if(rk[x]^rk[y]==d)return 0;
		else return 1;
	}
	fa[yf]=xf;
	rk[yf]=rk[x]^rk[y]^d;
	return 0;
}

void solve(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=m;i++){
		int x,y,d;
		char s[5];
		scanf("%d%d%s",&x,&y,s),--x;
		if(!mp.count(x))mp[x]=++tot;
		if(!mp.count(y))mp[y]=++tot;
		if(s[0]=='e')d=0;
		else d=1;
		if(!ans&&check(mp[x],mp[y],d))ans=i-1;
	}
	printf("%d",ans?ans:m);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}