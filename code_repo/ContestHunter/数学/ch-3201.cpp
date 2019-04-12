/*
枚举b1/a1的约数
由
gcd(x/a1,a0/a1)=1
gcd(b1/b0,b1/x)=1
推出
x/a1和b1/x是b1/a1的约数，于是直接枚举b1/a1的约数

*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;

int n,a0,a1,b0,b1,ans;

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

void solve(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		if(b1%a1){
			puts("0");
			continue;
		}
		ans=0;
		int k=b1/a1,p=a0/a1,q=b1/b0;
		for(int i=1;i*i<=k;i++){
			if(k%i)continue;
			int t=k/i;
			if(b1%t==0&&gcd(i,p)==1&&gcd(q,t)==1)++ans;
			if(i==t)continue;
			if(b1%i==0&&gcd(t,p)==1&&gcd(q,i)==1)++ans;
		}
		printf("%d\n",ans);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}