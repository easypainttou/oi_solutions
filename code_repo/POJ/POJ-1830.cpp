/*
...
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=35;
const int maxm=15;
const int inf=0x3f3f3f3f;

int k,n,a[maxn];

void Gauss(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)if(a[j]>a[i])swap(a[i],a[j]);
		if(!a[i]){
			printf("%d\n",1<<(n-i+1));
			return;
		}
		if(a[i]==1){
			printf("Oh,it's impossible~!!\n");
			return;
		}
		for(int j=n-i+1;j>=1;j--){
			if(a[i]>>j&1){
				for(int k=i+1;k<=n;k++){
					if(a[k]>>j&1)a[k]^=a[i];
				}
				break;
			}
		}
	}
	printf("1\n");
}

void solve(){
	scanf("%d",&k);
	while(k--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int b,i=1;i<=n;i++)scanf("%d",&b),a[i]^=b,a[i]|=1<<i; //这样存放增广矩阵，未知数就是一个向量从xn到x1的顺序存放
		while(1){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x==0&&y==0)break;
			a[y]^=1<<x;
		}
		Gauss();
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}