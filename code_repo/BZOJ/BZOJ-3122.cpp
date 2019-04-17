/*
...
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>

using namespace std;

typedef long long ll;

const int MAXN=1e5+10;
const int MAXM=62;
const int INF=0x3f3f3f3f;

int T;
ll p,a,b,x1,t;
map<ll,ll>mp;

ll qPow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}

ll BSGS(ll x,ll y){
	mp.clear(),x%=p,y%=p;
	if(!x&&y)return -1;
	ll m=ceil(sqrt(p));
	for(ll tmp=y,i=0;i<m;tmp=tmp*x%p,i++){
		if(!mp.count(tmp))mp[tmp]=i; //一直wa在此 qwq
	}
	ll q=qPow(x,m);
	for(ll tmp=q,i=1;i<=m;tmp=tmp*q%p,i++){
		if(mp.count(tmp)&&i*m-mp[tmp]>=0){
			return i*m-mp[tmp]+1; //给x +1了... 
		}
	}
	return -1;
}

void solve(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld%lld",&p,&a,&b,&x1,&t);
		if(x1==t){puts("1");continue;}
		if(a==0){
			if(t==b%p)puts("2");
			else puts("-1");
		}else if(a==1){
			if(b%p==0)puts("-1");
			else{
				ll inv=qPow(b,p-2);
				printf("%lld\n",((t-x1)%p+p)%p*inv%p+1);
			}
		}else{
			ll c=b*qPow(a-1,p-2)%p;
			if((c+x1)%p==0){puts("-1");continue;}
			ll inv=qPow(c+x1,p-2);
			printf("%lld\n",BSGS(a,inv*((c+t)%p)%p));
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}