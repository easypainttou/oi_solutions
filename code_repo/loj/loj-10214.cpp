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

int t,k;
ll y,z,p;
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

void calc(){
	if(y%p==0){puts("Orz, I cannot find x!");return;}
	ll inv=qPow(y,p-2);
	printf("%lld\n",z*inv%p);
}

void BSGS(){
	mp.clear();
	y%=p,z%=p;
	if(!y&&z){puts("Orz, I cannot find x!");return;}
	ll m=ceil(sqrt(p));
	for(ll tmp=z,i=0;i<m;tmp=tmp*y%p,i++){
		mp[tmp]=i;
	}
	ll q=qPow(y,m);
	for(ll tmp=q,j=1;j<=m;tmp=tmp*q%p,j++){
		if(mp.count(tmp)&&j*m-mp[tmp]>=0){
			printf("%lld\n",j*m-mp[tmp]);
			return;
		}
	}
	puts("Orz, I cannot find x!");
}

void solve(){
	scanf("%d%d",&t,&k);
	for(int i=1;i<=t;i++){
		scanf("%lld%lld%lld",&y,&z,&p);
		if(k==1)printf("%lld\n",qPow(y,z));
		if(k==2)calc();
		if(k==3)BSGS();
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}