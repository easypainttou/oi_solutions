/*

题意：有N个格子，一开始在第1个。现在在位置i扔一个6面骰子，若得到x，则到位置i+x，若i+x>n则重新扔。每到位置i，获得xi黄金。问到位置N的期望的黄金

解：dp[i]指从i到N的期望的黄金，dp[i]=1/k(dp[i+1]+...+dp[i+k])+x[i]

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAX_N=1e5+10;
const int MAX_M=200+10;
const int inf=0x3f3f3f3f;

int T, n, x[MAX_N];
double dp[MAX_N];

void solve() {
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", x + i);
		}
		for (int i = n; i >= 1; --i) {
			dp[i] = x[i];
			int q = min(6, n - i);
			for (int j = 1; j <= q; ++j) {
				dp[i] += 1.0 / q * dp[i + j];
			}
		}
		printf("Case %d: %f\n", kase, dp[1]);
	}
}

int main(){
//	ios::sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}