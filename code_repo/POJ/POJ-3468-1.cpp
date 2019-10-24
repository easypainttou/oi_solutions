/*
区间加k，区间和查询

可以：
树状数组
分块
线段树

以下分块
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#define LS (rt<<1)
#define RS (rt<<1|1)
using namespace std;
typedef long long ll;

const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;

int n,q,T,L[MAXN],R[MAXN],pos[MAXN];
ll A[MAXN],sum[MAXN],b[MAXN];

inline void init(){
	T=sqrt(n);
	for(int i=1;i<=T;i++){
		L[i]=(i-1)*T+1;R[i]=i*T;
	}
	if(R[T]<n)T++,L[T]=R[T-1]+1,R[T]=n;
	for(int i=1;i<=T;i++){
		for(int j=L[i];j<=R[i];j++){
			pos[j]=i;
			sum[i]+=A[j];
		}
	}
}

inline void add(int s,int t,int k){
	if(pos[s]==pos[t]){
		for(int i=s;i<=t;i++)A[i]+=k;
		sum[pos[s]]+=(t-s+1)*k;
	}else{
		for(int i=pos[s]+1;i<=pos[t]-1;i++)b[i]+=k;
		for(int i=s;i<=R[pos[s]];i++)A[i]+=k;
		sum[pos[s]]+=(R[pos[s]]-s+1)*k;
		for(int i=L[pos[t]];i<=t;i++)A[i]+=k;
		sum[pos[t]]+=(t-L[pos[t]]+1)*k;
	}
}

inline ll query(int s,int t){
	ll res=0;
	if(pos[s]==pos[t]){
		for(int i=s;i<=t;i++)res+=A[i];
		res+=(t-s+1)*b[pos[s]];
	}else{
		for(int i=pos[s]+1;i<=pos[t]-1;i++)res+=sum[i]+(R[i]-L[i]+1)*b[i];
		for(int i=s;i<=R[pos[s]];i++)res+=A[i];
		res+=(R[pos[s]]-s+1)*b[pos[s]];
		for(int i=L[pos[t]];i<=t;i++)res+=A[i];
		res+=(t-L[pos[t]]+1)*b[pos[t]];
	}
	return res;
}

void solve(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lld",A+i);
	init();
	while(q--){
		char s[5];
		int a,b,c;
		scanf("%s%d%d",s,&a,&b);
		if(s[0]=='C'){
			scanf("%d",&c);
			add(a,b,c);
		}else{
			printf("%lld\n",query(a,b));
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 