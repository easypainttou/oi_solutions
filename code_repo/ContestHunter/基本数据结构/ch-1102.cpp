/*
...高精度catalan
*/
#include<bits/stdc++.h>

using namespace std;
const int maxn=1e6+5;
const int maxm=2e5+5;
const int inf=0x3f3f3f3f;
const double eps=1e-5;
typedef long long ll;

int n,ans[maxn],p[maxm],pc,vis[maxm],powc[maxm],a[maxm],b[maxm];

void getPrime(){
	for(int i=2;i<=n<<1;i++){
		if(!vis[i])p[++pc]=i;
		for(int j=1;j<=pc;j++){
			if(i*p[j]>2*n)break;
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}

void getDiv(){
	for(int i=1;i<=pc;i++){
		for(int j=p[i];j<=2*n;j*=p[i])a[i]+=2*n/j;
		for(int j=p[i];j<=n;j*=p[i])b[i]+=n/j;
		powc[i]=a[i]-2*b[i];
	}
	int tmp=n+1;
	for(int i=1;i<=pc&&p[i]<=tmp;i++){
		while(tmp%p[i]==0)tmp/=p[i],--powc[i];
	}
}



/*
//对于阶乘，这个算法比较慢
void getDiv(int arr[],int num,int k){
	for(int i=1;i<=num;i++){
		int tmp=arr[i];
		for(int j=1;j<=pc&&p[j]<=tmp;j++){
			while(tmp%p[j]==0)tmp/=p[j],powc[j]+=k;
		}
	}
}
*/

void Mul(int x){
	for(int i=1;i<=ans[0];i++)ans[i]*=x;
	for(int i=1;i<=ans[0];i++){
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
		if(ans[ans[0]+1])++ans[0];
	}
}

void solve(){
	scanf("%d",&n);
	getPrime();
	getDiv();
	ans[0]=ans[1]=1;
	for(int i=1;i<=pc;i++){
		while(powc[i]>0){
			Mul(p[i]);
			--powc[i];
		}
	}
	for(int i=ans[0];i>=1;i--)printf("%d",ans[i]);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}