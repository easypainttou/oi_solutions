/*
贪心 模拟
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
typedef long long ll;

int n,m,w[maxn],day[maxm],stk[maxn],stkd,ans;
bool vis[maxn];

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",w+i);
	for(int i=1;i<=m;i++){
		scanf("%d",day+i);
		if(!vis[day[i]]){
			stk[++stkd]=day[i];
			vis[day[i]]=1;
		}
	}
	for(int i=1;i<=n;i++)if(!vis[i])stk[++stkd]=i;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(stk[j]==day[i]){
				for(int k=j;k>1;k--)stk[k]=stk[k-1];
				stk[1]=day[i];
				break;
			}else{
				ans+=w[stk[j]];
			}
		}
	}
	printf("%d",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}