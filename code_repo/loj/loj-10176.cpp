/*

s[i]是A[i]的前缀和

ans=max(s[i]-s[k])  1<=i<=n, max(i-m,0)<=k<i  
对于固定的i，s[k]一定是[max(i-m,0),i)这个区间最小的
所以用单调队列维护区间s[k]最小值
时间复杂度为O(n)

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=2e5+5;
const int MAXM=200+10;
const int INF=0x3f3f3f3f;
const int MOD=1e9;

int n,m,s[MAXN],head,tail,q[MAXN],ans;

int read(){
	char ch=getchar();
	int res=0,f=1;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())res=res*10+ch-'0';
	return res*f;
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int tmp;
		tmp=read();
		s[i]=s[i-1]+tmp;
	}
	head=1,tail=1,q[tail]=0,ans=-INF;
	for(int i=1;i<=n;i++){
		while(head<=tail&&q[head]<i-m)++head;
		ans=max(ans,s[i]-s[q[head]]);
		while(head<=tail&&s[q[tail]]>=s[i])--tail;
		q[++tail]=i;
	}
	printf("%d",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}