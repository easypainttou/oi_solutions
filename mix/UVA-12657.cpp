#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
bool inv;
int n,m,l[maxn],r[maxn];

inline void link(int a,int b){
	r[a]=b,l[b]=a;
}

void solve(){
	int cnt=0;
	while(~scanf("%d%d",&n,&m)){
		++cnt;
		for(int i=0;i<=n;i++){
			link(i,(i+1)%(n+1));
		}
		int a,x,y;
		inv=0;
		while(m--){
			scanf("%d",&a);
			if(a==4)inv^=1;
			else{
				scanf("%d%d",&x,&y);
				if(a==3&&r[y]==x)swap(x,y);
				if(inv&&(a==1||a==2))a=3-a;
				if(a==1&&x==l[y])continue;
				if(a==2&&x==r[y])continue;
				
				int xl=l[x],xr=r[x],yl=l[y],yr=r[y];
				if(a==1)link(xl,xr),link(yl,x),link(x,y);
				else if(a==2)link(xl,xr),link(y,x),link(x,yr);
				else if(a==3){
					if(r[x]==y)link(xl,y),link(y,x),link(x,yr);
					else link(xl,y),link(y,xr),link(yl,x),link(x,yr);
				}
			}
		}
		long long ans=0;
		int k=1;
		for(int i=r[0];i;i=r[i]){
			if(k&1)ans+=i;
			++k;
		}
		if(((n&1)==0)&&inv)ans=(long long)n*(1+n)/2-ans;
		printf("Case %d: %lld\n",cnt,ans);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}