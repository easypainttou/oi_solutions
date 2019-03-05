/*
...
*/
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=5e5+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
const int mod=9901;
const double eps=1e-5;
typedef long long ll;

int n,a[maxn],c[maxn];
ll ans;

void mergeSort(int l,int r){
	if(l<r){
		int m=(l+r)>>1;
		mergeSort(l,m),mergeSort(m+1,r);
		int x=l,y=m+1,z=l;
		while(x<=m&&y<=r){
			if(a[x]>a[y]){
				c[z++]=a[y++];
				ans+=m-x+1;
			}else{
				c[z++]=a[x++];
			}
		}
		while(x<=m)c[z++]=a[x++];
		while(y<=r)c[z++]=a[y++];
		for(int i=l;i<=r;i++)a[i]=c[i];
	}
}

void solve(){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		ans=0;
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		mergeSort(1,n);
		printf("%lld\n",ans);
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}