/*
...qwq
*/
#include<bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
const int mod=9901;
const double eps=1e-5;
typedef long long ll;

int n,m,a,cnt=-1,id,c[maxn];
map<int,int>mp;
vector<int>ans;

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if(mp.find(a)==mp.end())mp[a]=1;
		else ++mp[a];
	}
	scanf("%d",&m);	//当然也可以以mp[b[i]]第一关键词，mp[c[i]]第二关键词排序qwq
	for(int i=1;i<=m;i++){
		scanf("%d",&a);
		if(mp[a]>cnt)ans.clear(),cnt=mp[a],ans.push_back(i);
		else if(mp[a]==cnt)ans.push_back(i);
	}
	for(int i=1;i<=m;i++)scanf("%d",c+i);
	for(cnt=-1,int i=0;i<ans.size();i++){
		if(mp[c[ans[i]]]>cnt)cnt=mp[c[ans[i]]],id=ans[i];
	}
	printf("%d",id);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}