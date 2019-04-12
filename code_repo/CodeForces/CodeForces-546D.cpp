/*
...dp?
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=5e6+10;
const int inf=0x3f3f3f3f;
const int mod=9901;

ll p[maxn],cnt;
bool vis[maxn];
int t,a,b,ans[maxn];

void init(){
	for(int i=2;i<=maxn;i++){
		if(!vis[i])p[++cnt]=i;
		for(int j=1;j<=cnt;j++){
			if(i*p[j]>maxn)break;
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	for(int i=2;i<=maxn;i++){
		if(!vis[i])ans[i]=1;
		else{
			for(int j=1;j<=cnt;j++){
				if(i%p[j]==0){
					ans[i]=ans[i/p[j]]+1;
					break;
				}
			}
		}
	}
	for(int i=1;i<=maxn;i++)ans[i]+=ans[i-1];
}

void solve(){
	init();
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		printf("%d\n",ans[a]-ans[b]);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}