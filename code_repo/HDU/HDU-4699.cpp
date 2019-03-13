/*
...
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
const double eps=1e-5;
typedef long long ll;

int q,stk1[maxn],stk2[maxn],p1,p2,sum[maxn],f[maxn];
char str[5];

void solve(){
	while(~scanf("%d",&q)){
		p1=p2=0;
		f[0]=-inf;
		while(q--){
			scanf("%s",str);
			if(str[0]=='I'){
				int x;
				scanf("%d",&x);
				stk1[++p1]=x;
				sum[p1]=sum[p1-1]+x;
				f[p1]=max(f[p1-1],sum[p1]);
			}else if(str[0]=='D'){
				--p1;
			}else if(str[0]=='L'){
				if(p1==0)continue;
				int x=stk1[p1--];
				stk2[++p2]=x;
			}else if(str[0]=='R'){
				if(p2==0)continue;
				int x=stk2[p2--];
				stk1[++p1]=x;
				sum[p1]=sum[p1-1]+x;
				f[p1]=max(f[p1-1],sum[p1]);
			}else{
				int k;
				scanf("%d",&k);
				printf("%d\n",f[k]);
			}
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}