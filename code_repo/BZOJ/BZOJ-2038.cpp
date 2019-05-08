/*
莫队算法 板子题
*/
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N=5e4+10;
const int M=40;
const int INF=0x3f3f3f3f;

struct Q{
	int L,R,id;
}qS[N];

struct A{
	ll dat1,dat2;
	int id;
}aS[N];

int T,n,m,c[N],pos[N];
ll num,cnt[N];

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

bool cmp1(const Q &a,const Q &b){
	if(pos[a.L]==pos[b.L])return a.R<b.R;
	return a.L<b.L;
}

bool cmp2(const A &a,const A &b){
	return a.id<b.id;
}

inline void init(){
	T=sqrt(n);
	for(int i=1;i<=n;i++)pos[i]=(i-1)/T+1;
}

inline void change(int x,int k){
	num-=cnt[x]*(cnt[x]-1);
	cnt[x]+=k;
	num+=cnt[x]*(cnt[x]-1);
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=1;i<=m;i++)scanf("%d%d",&qS[i].L,&qS[i].R),qS[i].id=i;
	init();
	sort(qS+1,qS+m+1,cmp1);
	for(int L=1,R=0,i=1;i<=m;i++){
		while(L>qS[i].L)change(c[--L],1);
		while(L<qS[i].L)change(c[L++],-1);
		while(R>qS[i].R)change(c[R--],-1);
		while(R<qS[i].R)change(c[++R],1);
		aS[i].id=qS[i].id;
		aS[i].dat1=num,aS[i].dat2=(ll)(R-L+1)*(R-L);
		if(aS[i].dat1==0){
			aS[i].dat2=1;
		}else{
			ll g=gcd(aS[i].dat1,aS[i].dat2);
			aS[i].dat1/=g;
			aS[i].dat2/=g;
		}
	}
	sort(aS+1,aS+m+1,cmp2);
	for(int i=1;i<=m;i++)printf("%lld/%lld\n",aS[i].dat1,aS[i].dat2);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 