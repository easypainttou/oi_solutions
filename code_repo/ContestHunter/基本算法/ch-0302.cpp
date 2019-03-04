/*
...
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
typedef long long ll;

int n,m;
vector<int>ans;

void dfs(int step){
	int num=ans.size();
	if(num>m||m>num+n-step)return;
	if(step==n){
		if(num==m){
			for(int i=0;i<num;i++){
				if(i)printf(" ");
				printf("%d",ans[i]);
			}
			puts("");
		}
		return;
	}
	ans.push_back(step+1);
	dfs(step+1);
	ans.pop_back();
	dfs(step+1);
}
void solve(){
	scanf("%d%d",&n,&m);
	dfs(0);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}