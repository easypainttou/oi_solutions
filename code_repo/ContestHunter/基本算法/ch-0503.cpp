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

int n,a[maxn],c[maxn],cnt;
ll ans,ans1;

void mergeSort(int l,int r){	//l和1还行
	if(l<r){
		int m=(l+r)>>1;
		mergeSort(l,m),mergeSort(m+1,r);
		int x=l,y=m+1,z=l;
		while(x<=m&&y<=r){
			if(a[x]>a[y]){
				c[z++]=a[y++];
				ans+=m-x+1;
			}else c[z++]=a[x++];
		}
		while(x<=m)c[z++]=a[x++];
		while(y<=r)c[z++]=a[y++];
		for(int i=l;i<=r;i++)a[i]=c[i];
	}
}


void solve(){
	while(~scanf("%d",&n)){
		int tmp;
		cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				scanf("%d",&tmp);
				if(tmp)a[++cnt]=tmp;
			}
		ans=0,mergeSort(1,cnt);
		ans1=ans;
		cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				scanf("%d",&tmp);
				if(tmp)a[++cnt]=tmp;
			}
		ans=0,mergeSort(1,cnt);
		if((ans1&1)==(ans&1))printf("TAK\n");
		else printf("NIE\n");
	}
}
 
int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}