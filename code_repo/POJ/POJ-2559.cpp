/*
...
*/
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
const int maxm=1e6+5;
const int inf=0x3f3f3f3f;
const double eps=1e-5;
typedef long long ll;

int n,stk[maxn],w[maxn],p;
ll ans;

void solve(){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		p=ans=0;
		for(int i=1;i<=n;i++){
			int h;
			scanf("%d",&h);
			if(h>stk[p]){
				stk[++p]=h,w[p]=1;
			}else{
				int tmpw=0;
				while(h<=stk[p]&&p>0){	//不判断栈空会RE qwq
					tmpw+=w[p];
					ans=max(ans,(ll)tmpw*stk[p--]);
				}
				stk[++p]=h,w[p]=tmpw+1;
			}
		}
		int tmpw=0;
		while(stk[p]>0){
			tmpw+=w[p];
			ans=max(ans,(ll)tmpw*stk[p--]);
		}
		printf("%lld\n",ans);
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}