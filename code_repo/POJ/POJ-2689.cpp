#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e5+10;
const int maxm=1e6+10;
const int inf=0x3f3f3f3f;


ll L,R,pri[maxn],cnt;
bool os[maxm],vis[maxn];

void getPrime(){
	vis[1]=1;
	for(int i=2;i<=maxn;i++){
		if(!vis[i])pri[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(i*pri[j]>maxn)break;
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}

void solve(){
	getPrime(); //1e9范围，只要筛大概1e5内的素数，然后划掉区间内的合数
	while(~scanf("%d%d",&L,&R)){
		memset(os,0,sizeof(os));
		for(int i=1;i<=cnt;i++){
			//(L-1)/pri[i]+1是L及之后第一个pri[i]的倍数
			ll a=max(2LL,(L-1)/pri[i]+1),b=R/pri[i];
			for(ll j=a;j<=b;j++)os[j*pri[i]-L+1]=1;	//1e9范围的数偏移L-1可以进行标记qwq
		}
		ll minnum=inf,maxnum=0,p1,p2,p3,p4,pre=-1;
		bool f=0;
		if(L==1)os[1]=1; //记得把1划掉qwq
		for(int i=1;i<=R-L+1;i++){
			ll now=i+L-1;
			if(!os[i]){
				if(pre!=-1){
					f=1;
					ll dis=now-pre;
					if(dis>maxnum)maxnum=dis,p3=pre,p4=now;
					if(dis<minnum)minnum=dis,p1=pre,p2=now;
				}
				pre=now;
			}
		}
		if(f)printf("%lld,%lld are closest, %lld,%lld are most distant.\n",p1,p2,p3,p4);
		else printf("There are no adjacent primes.\n");
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}