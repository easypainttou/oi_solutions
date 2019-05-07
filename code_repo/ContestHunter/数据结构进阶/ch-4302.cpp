/*
...
*/
#include<cstdio>
#include<cstdlib>
#include<map>

#define LS (rt<<1)
#define RS (rt<<1|1)
using namespace std;
typedef long long ll;

const int MAXN=5e5+5;
const int INF=0x3f3f3f3f;

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

ll n,m,a[MAXN],c[MAXN],g[MAXN<<2];

inline ll lowbit(ll x){return x&(-x);}

void add(ll p,ll k){
	for(;p<=n;p+=lowbit(p))c[p]+=k;
}

ll ask(ll p){
	ll res=0;
	for(;p>0;p-=lowbit(p))res+=c[p];
	return res;
}

inline void pushUp(ll rt){
	g[rt]=gcd(g[LS],g[RS]);
}

void build(ll rt,ll L,ll R){
	if(L==R){
		g[rt]=a[L]-a[L-1];
		return ;
	}
	ll mid=(L+R)>>1;
	build(LS,L,mid);
	build(RS,mid+1,R);
	pushUp(rt);
}

void update(ll rt,ll L,ll R,ll p,ll k){
	if(L==R){
		g[rt]+=k;
		return;
	}
	ll mid=(L+R)>>1;
	if(p<=mid)update(LS,L,mid,p,k);
	else update(RS,mid+1,R,p,k);
	pushUp(rt);
}

ll query(ll rt,ll L,ll R,ll s,ll t){
	if(s<=L&&R<=t){
		return g[rt];
	}
	ll mid=(L+R)>>1,res=0;
	if(s<=mid)res=gcd(res,query(LS,L,mid,s,t));
	if(t>mid)res=gcd(res,query(RS,mid+1,R,s,t));
	return res;
}

void solve(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		char s[5];
		ll l,r,d;
		scanf("%s%lld%lld",s,&l,&r);
		if(s[0]=='C'){
			scanf("%lld",&d);
			add(l,d);
			if(r<n)add(r+1,-d);
			update(1,1,n,l,d);
			if(r<n)update(1,1,n,r+1,-d);
		}else{
			ll ans=gcd(a[l]+ask(l),query(1,1,n,l+1,r));
			printf("%lld\n",abs(ans));
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 