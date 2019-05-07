/*
...
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LS (rt<<1)
#define RS (rt<<1|1)
using namespace std;
typedef long long ll;

const int MAXN=2e4+10;
const int INF=0x3f3f3f3f;

struct node{
	ll lz,dat;
}tree[MAXN<<2];

struct line{
	ll y,x1,x2,k;
	line(ll y=0,ll x1=0,ll x2=0,ll k=0):y(y),x1(x1),x2(x2),k(k){}
}ls[MAXN];

bool operator<(const line&a,const line&b){
	if(a.y==b.y)return a.k<b.k;
	return a.y<b.y;
}

ll n,W,H,tot,preX[MAXN],ans;

inline ll getNewX(ll x){
	return lower_bound(preX+1,preX+tot+1,x)-preX; //一直re在这里，离散化后的x包含0，qwq
}

inline void pushDown(ll rt){
	if(tree[rt].lz){
		tree[LS].lz+=tree[rt].lz,tree[RS].lz+=tree[rt].lz;
		tree[LS].dat+=tree[rt].lz,tree[RS].dat+=tree[rt].lz;
		tree[rt].lz=0;
	}
}

inline void pushUp(ll rt){
	tree[rt].dat=max(tree[LS].dat,tree[RS].dat);
}

void update(ll rt,ll L,ll R,ll s,ll t,ll k){
	if(s<=L&&R<=t){
		tree[rt].lz+=k;
		tree[rt].dat+=k;
		return;
	}
	pushDown(rt);
	ll mid=(L+R)>>1;
	if(s<=mid)update(LS,L,mid,s,t,k);
	if(t>mid)update(RS,mid+1,R,s,t,k);
	pushUp(rt);
}

void solve(){
	while(~scanf("%lld%lld%lld",&n,&W,&H)){
		ans=0;
		memset(tree,0,sizeof(tree));
		ll x,y,c;
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&x,&y,&c);
			ls[(i<<1)-1]=line(y,x,x+W,c);
			ls[i<<1]=line(y+H,x,x+W,-c);
			preX[(i<<1)-1]=x;
			preX[i<<1]=x+W;
		}
		sort(ls+1,ls+(n<<1)+1);
		sort(preX+1,preX+(n<<1)+1);
		tot=unique(preX+1,preX+(n<<1)+1)-preX-1;
		for(ll i=1;i<n<<1;i++){
			update(1,1,tot-1,getNewX(ls[i].x1),getNewX(ls[i].x2)-1,ls[i].k);
			ans=max(ans,tree[1].dat);
		}
		printf("%lld\n",ans);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 