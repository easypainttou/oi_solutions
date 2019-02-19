/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e2+5;

int n,H,fn[maxn],dn[maxn],T[maxn],ans;
priority_queue< pair<int,int> >q;
void solve(){
	scanf("%d%d",&n,&H);
	for(int i=1;i<=n;i++)scanf("%d",fn+i);
	for(int i=1;i<=n;i++)scanf("%d",dn+i);
	for(int i=1;i<=n-1;i++)scanf("%d",T+i);
	for(int i=1;i<=n;i++){
		int now=H*60,num=0;
		if(!q.empty())q.pop();
		for(int j=1;j<=i;j++)q.push(make_pair(fn[j],j));
		for(int j=1;j<i;j++)now-=T[j]*5;
		while(!q.empty()&&now>0){
			int cf=q.top().first,cp=q.top().second;
			q.pop();
			num+=cf;
			if(cf-dn[cp]>0)q.push(make_pair(cf-dn[cp],cp));
			now-=5;
		}
		ans=max(ans,num);
	}
	printf("%d",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}