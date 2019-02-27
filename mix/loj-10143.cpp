/*
...
*/
#include<bits/stdc++.h>
#define lson p<<1
#define rson p<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef set<int>::iterator it;
const int inf=0x3f3f3f3f;
const int maxn=4e4+5;
const int maxm=3e5+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

int n,rt,tot,fa[maxn],ch[maxn][2],val[maxn],cnt[maxn],sz[maxn];

inline void maintain(int x){sz[x]=cnt[x]+sz[ch[x][0]]+sz[ch[x][1]];}
inline int get(int x){return x==ch[fa[x]][1];}

int read(){
	int res=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())res=res*10+ch-'0';
	return res*f;
}


void rotate(int x){
	int y=fa[x],z=fa[y],chk=get(x);
	ch[y][chk]=ch[x][chk^1];
	fa[ch[x][chk^1]]=y;
	ch[x][chk^1]=y;
	fa[y]=x;
	fa[x]=z;
	if(z)ch[z][ch[z][1]==y]=x;
	maintain(y);
	maintain(x);
}

void splay(int x){
	for(int f;f=fa[x],f;rotate(x)){
		if(fa[f])rotate((get(x)==get(f)?f:x));
	}
	rt=x;
}

void ins(int k){
	if(!rt){
		rt=++tot;
		val[tot]=k;
		++cnt[tot];
		maintain(tot);
		return;
	}
	int crt=rt,f=0;
	while(1){
		if(val[crt]==k){
			++cnt[crt];
			maintain(crt);
			maintain(f);
			splay(crt);
			return;
		}
		f=crt,crt=ch[crt][k>val[crt]];
		if(!crt){
			fa[++tot]=f;
			ch[f][k>val[f]]=tot;
			val[tot]=k;
			++cnt[tot];
			maintain(tot);
			maintain(f);
			splay(tot);
			return;
		}
	}
}

int pre(){
	int crt=ch[rt][0];
	while(ch[crt][1])crt=ch[crt][1];
	return crt;
}

int nxt(){
	int crt=ch[rt][1];
	while(ch[crt][0])crt=ch[crt][0];
	return crt;
}

void solve(){
	int n=read(),ans=0;
	for(int i=1;i<=n;i++){
		int m=read();
		ins(m);
		if(i==1){ans+=m;continue;}
		if(cnt[rt]>1)continue;
		int p=pre(),min1=inf,min2=inf;
		if(p)min1=m-val[p];
		p=nxt();
		if(p)min2=val[p]-m;
		ans+=min(min1,min2);
	}
	printf("%d\n",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}