/*
...
loj10004为O(n^2)

以下为O(nlogn)

用并查集实现O(n)：
http://www.neptuuz.com/wordpress/?p=421
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+5;

int n,id[maxn],t[maxn],v[maxn];
priority_queue<int>q;

bool com(int a,int b){
	return t[a]<t[b];
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",t+i,v+i);
		id[i]=i;
	}
	sort(id+1,id+n+1,com);
	
	int ans=0;
	for(int i=1;i<=n;i++){
		int cur=id[i];
		if(q.size()<t[cur]){
			q.push(-v[cur]);
			ans+=v[cur];
		}else if(-q.top()<v[cur]){
			ans+=q.top();
			q.pop();
			q.push(-v[cur]);
			ans+=v[cur];
		}
	}
	printf("%d",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}