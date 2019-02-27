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

int n,m,lg[maxn],a[maxn],f[maxn][25];

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



void init(){
	for(int i=1;i<=n;i++)f[i][0]=a[i];
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			f[j][i]=max(f[j][i-1],f[j+(1<<i-1)][i-1]);
		}
	}
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=read();
	lg[0]=-1;
	for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1;
	init();
	while(m--){
		int x,y;
		x=read(),y=read();
		int z=lg[y-x+1];
		printf("%d\n",max(f[x][z],f[y-(1<<z)+1][z]));
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}