/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e6+5;
const int maxm=4e5+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

ll c[maxn];
int n,q;

int read(){
	int ans=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	for(;ch>='0'&&ch<='9';)ans=ans*10+ch-'0',ch=getchar();
	return ans*f;
}

int lowbit(int x){return x&(-x);}

void add(int x,int y){
	while(x<=n){
		c[x]+=y;
		x+=lowbit(x);
	}
}

ll query(int x){
	ll ans=0;
	while(x>=1){
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

void solve(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		int x;
		x=read();
		add(i,x);
	}
	while(q--){
		int x,y,z;
		x=read(),y=read(),z=read();
		if(x==1){
			add(y,z);
		}else{
			printf("%lld\n",query(z)-query(y-1));
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}