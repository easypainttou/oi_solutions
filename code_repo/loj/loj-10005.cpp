/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=0;

priority_queue<int>minq;
priority_queue<int>maxq;

void solve(){
	int t,n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&t),minq.push(-t),maxq.push(t);
	for(int i=1;i<=n-1;i++){
		int a=minq.top();minq.pop();
		int b=minq.top();minq.pop();
		minq.push(-a*b-1);
		a=maxq.top();maxq.pop();
		b=maxq.top();maxq.pop();
		maxq.push(a*b+1);
	}
	printf("%d",-minq.top()-maxq.top());
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}