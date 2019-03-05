/*
...
*/
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1e5+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
const int mod=9901;
const double eps=1e-5;
typedef long long ll;

int s,n,m;
priority_queue<int>minq,maxq;
vector<int>ans;

void solve(){
	scanf("%d",&s);
	while(s--){
		scanf("%d%d",&n,&m);
		ans.clear();
		while(!minq.empty())minq.pop();
		while(!maxq.empty())maxq.pop();
		minq.push(-inf),maxq.push(-inf);
		for(int a,i=1;i<=m;i++){
			scanf("%d",&a);
			if(a<-minq.top())maxq.push(a);
			else minq.push(-a);
			int minsz=minq.size(),maxsz=maxq.size();
			if(minsz<maxsz)minq.push(-maxq.top()),maxq.pop();
			else if(minsz>maxsz+1)maxq.push(-minq.top()),minq.pop();
			if(i&1)ans.push_back(-minq.top());
		}
		printf("%d %d",n,m+1>>1);
		for(int i=0;i<ans.size();i++){
			if(i%10==0)puts("");
			printf("%d ",ans[i]);
		}
		puts("");
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}