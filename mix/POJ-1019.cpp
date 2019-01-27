#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll M=31269;
//const ll lim=2147483647;
ll a[M],s[M];

void getTab(){
	a[1]=s[1]=1;
	for(ll i=2;i<=M;i++){
		a[i]=a[i-1]+log10(i)+1;
		s[i]=s[i-1]+a[i];
	}
}

int main(){
	getTab();
	int i,t,n,a,b,c;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(a=1;s[a]<n;a++);
		b=n-s[a-1],c=0;
		for(i=1;c<b;i++)c+=log10(i)+1;
		printf("%d\n",int((i-1)/pow(10,c-b))%10);
	}
	return 0;
}