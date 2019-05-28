/*

题意：在1~n中选择k个数，使它们的gcd最大，输出它们的gcd

解：若答案为g，则取出的k个数满足g,2*g,...,k*g，k*g应尽量接近n，所以g为[n/k]

*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN=1e5+5;
const int MAXM=1e6+5;
const int INF=0x3f3f3f3f;
const int MOD=10007;

int n,k;

void solve(){
	scanf("%d%d",&n,&k);
	printf("%d",n/k);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
