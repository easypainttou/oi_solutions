/*
...
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
typedef long long ll;

int n;
vector<int>ans;

void dfs(int step){
	if(step==n){
		int sz=ans.size();
		for(int i=0;i<sz;i++){
			if(i)printf(" ");
			printf("%d",ans[i]);
		}
		puts("");
		return;
	}
	dfs(step+1);
	ans.push_back(step+1);
	dfs(step+1);
	ans.pop_back();
}
void solve(){
	scanf("%d",&n);
	dfs(0);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}