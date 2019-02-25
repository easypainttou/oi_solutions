/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const int maxm=1e6+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

int n,k,a[maxn],lg[maxn],minf[maxn][25],maxf[maxn][25];

int read(){
	int ans=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	for(;ch>='0'&&ch<='9';)ans=ans*10+ch-'0',ch=getchar();
	return ans*f;
}


void solve(){
	n=read(),k=read();
	lg[0]=-1;
	for(int i=1;i<=n;i++)a[i]=read(),lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)minf[i][0]=a[i],maxf[i][0]=a[i];
	for(int i=1;1<<i<=n;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			minf[j][i]=min(minf[j][i-1],minf[j+(1<<i-1)][i-1]),maxf[j][i]=max(maxf[j][i-1],maxf[j+(1<<i-1)][i-1]);
	for(int i=1;i+k-1<=n;i++){
		int j=lg[k];
		printf("%d %d\n",max(maxf[i][j],maxf[i+k-(1<<j)][j]),min(minf[i][j],minf[i+k-(1<<j)][j]));
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}