/*

考虑顺时针的情况

a[n+i]=a[i]=p[i]-d[i]  1<=i<=n

s[i]=s[i-1]+a[i]  1<=i<2n

从第i个车站出发，min(s[i], ..., s[i+n-1])-s[i-1]>=0，则能够成功周游一圈，否则不能

min(s[i], ..., s[i+n-1])用单调队列维护就行

以上是顺时针，逆时针需要修改一下qwq

时间复杂度O(n)

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e6+5;
const int MAXM=200+10;
const int INF=0x3f3f3f3f;
const int MOD=1e9;

bool ans[MAXN];
int n,p[MAXN],d[MAXN],a[MAXN<<1],q[MAXN],head,tail;
ll s[MAXN<<1];

int read(){
	int res=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())res=res*10+ch-'0';
	return res*f;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)p[i]=read(),d[i]=read();	
	d[0]=d[n];
	for(int i=1;i<=n;i++)a[i]=a[n+i]=p[i]-d[i];
	for(int i=1;i<n<<1;i++)s[i]=s[i-1]+a[i];
	head=1,tail=0;
	for(int i=1;i<n<<1;i++){
		while(head<=tail&&i-n>=q[head])++head;
		while(head<=tail&&s[q[tail]]>=s[i])--tail;
		q[++tail]=i;
		if(i>=n&&s[q[head]]>=s[i-n])ans[i-n+1]=1;
	}
	
	for(int i=1;i<=n;i++)a[i]=a[i+n]=p[n-i+1]-d[n-i];
	for(int i=1;i<n<<1;i++)s[i]=s[i-1]+a[i];
	head=1,tail=0;
	for(int i=1;i<n<<1;i++){
		while(head<=tail&&i-n>=q[head])++head;
		while(head<=tail&&s[q[tail]]>=s[i])--tail;
		q[++tail]=i;
		if(i>=n&&s[q[head]]>=s[i-n])ans[(n<<1)-i]=1;
	}
	for(int i=1;i<=n;i++){
		if(ans[i])puts("TAK");
		else puts("NIE");
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}