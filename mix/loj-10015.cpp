/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const double eps=1e-10;

int n,x[55],y[55],dis[55][55],fa[55];

inline int caldis(int a,int b){
	return abs(x[a]-x[b])+abs(y[a]-y[b]);
}

int find(int x){
	return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}

bool check(int t){
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(dis[i][j]<=2*t){
				int uf=find(i),vf=find(j);
				if(uf!=vf)fa[uf]=vf;
			}
	int cnt=0;
	for(int i=1;i<=n;i++)if(fa[i]==i)cnt++;
	if(cnt==1)return 1;
	return 0;
}


void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			dis[i][j]=dis[j][i]=caldis(i,j);
	int l=0,r=1e9,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}