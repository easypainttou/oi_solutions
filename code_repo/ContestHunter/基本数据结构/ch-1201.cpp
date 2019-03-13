/*
...
*/
#include<bits/stdc++.h>
#define lson p<<1
#define rson p<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//typedef set<int>::iterator it;
const int inf=0x3f3f3f3f;
const int maxn=3e5+5;
const int maxm=2e6+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;
const double pi=acos(-1);

int n,m,a[maxn],s[maxn],q[maxn],l,r,ans;

int read(){
	int res=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())res=res*10+ch-'0';
	return res*f;
}


void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=read(),s[i]=s[i-1]+a[i];
	r=l=0,ans=-inf;	//...
	for(int i=1;i<=n;i++){
		while(l<=r&&i-q[l]>m)++l;
		ans=max(ans,s[i]-s[q[l]]);
		while(l<=r&&s[i]<=s[q[r]])--r;
		q[++r]=i;
	}
	printf("%d",ans);
}
 
int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}