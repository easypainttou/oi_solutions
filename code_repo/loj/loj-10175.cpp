/*
单调队列 板子题
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e6+5;
const int MAXM=200+10;
const int INF=0x3f3f3f3f;
const int MOD=1e9;

int n,k,a[MAXN],q[MAXN],head,tail,mn,mx;

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	head=1,tail=0;
	for(int i=1;i<=n;i++){
		while(head<=tail&&q[head]<i-k+1)++head;
		while(head<=tail&&a[q[tail]]>=a[i])--tail;
		q[++tail]=i;
		if(i-k>=0)printf("%d ",a[q[head]]);
	}
	puts("");
	head=1,tail=0;
	for(int i=1;i<=n;i++){
		while(head<=tail&&q[head]<i-k+1)++head;
		while(head<=tail&&a[q[tail]]<=a[i])--tail;
		q[++tail]=i;
		if(i-k>=0)printf("%d ",a[q[head]]);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}