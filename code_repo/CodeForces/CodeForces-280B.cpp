/*

题意：有一个长度为n的序列s，每个数都不一样，1<=l<r<=n，求最大的[l,r]中的最大值和次大值的异或和

解：从1~n维护一个单调递减的单调栈，再从n~1维护一个单调递减的单调栈，每次栈顶大于s[i]，就用栈顶和s[i]的异或和更新当前答案。
这样所有[l,r]中的最大值和次大值都会考虑到，时间复杂度O(n)。。。

*/

#include <bits/stdc++.h>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 5;
const int MAX_M = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int n, s[MAX_N], sp, stk[MAX_N], ans;

void solve() {
	scanf("%d", &n);
	inc(i, 1, n) scanf("%d", s + i);
	inc(i, 1, n) {
		while (sp > 0 && s[stk[sp]] < s[i]) sp--;
		if (sp > 0) ans = max(ans, s[stk[sp]] ^ s[i]);
		stk[++sp] = i;
	}
	sp = 0;
	dec(i, n, 1) {
		while (sp > 0 && s[stk[sp]] < s[i]) sp--;
		if (sp > 0) ans = max(ans, s[stk[sp]] ^ s[i]);
		stk[++sp] = i;
	}
	printf("%d\n", ans);
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}