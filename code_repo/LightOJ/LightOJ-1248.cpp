/*

题意：一个n面的骰子，求看到所有面的期望扔的次数

解：
Em指在已经看到m-1个不同面的条件下，看到第m个不同面的期望
Em=(m-1)/n*(Em+1)+(n-m+1)/n
得到 Em=n/(n-m+1)
答案是E1+...+En

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAX_N=1e5+10;
const int MAX_M=200+10;
const int inf=0x3f3f3f3f;

int T, n;
double ans;

void solve() {
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			ans += 1.0 * n / i;
		}
		printf("Case %d: %f\n", kase, ans);
	}
}

int main(){
//	ios::sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}