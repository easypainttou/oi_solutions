/*
n*m数码

问题：n行m列，局面a是否可以变化到局面b
解：
逆序对数为把数码写在一行的数列的逆序对数
1.m为奇数，“a的逆序对数”和“b的逆序对数”的奇偶性相同，则可以
2.m为偶数，“a的逆序对数和b的逆序对数之差”和“a的空格所在行和b的空格所在行之差”的奇偶性相同，则可以

*/
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1e6+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
const int mod=9901;
const double eps=1e-5;
typedef long long ll;

int n,m,a[maxn],c[maxn],cnt,row;
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
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)break;
		cnt=ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				int tmp;
				scanf("%d",&tmp);
				if(tmp)a[++cnt]=tmp;
				else row=i;
			}
		mergeSort(1,cnt);
		if((m&1)==0){
			if((n-row&1)==(ans&1))printf("YES\n");
			else printf("NO\n");
		}else{
			if(ans&1)printf("NO\n");
			else printf("YES\n");
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}