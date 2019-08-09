/*

题意：求2个字符串的最长公共子串

解：后缀数组 板子题

*/

#include <cstdio>
#include <algorithm>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 2e5 + 5;
const int MAX_M = 2e5 + 5;
const int INF = 0x3f3f3f3f;

char tmp[MAX_N], s[MAX_N];
int n, m, sa[MAX_N], rk[MAX_N], tax[MAX_N], tp[MAX_N], p, height[MAX_N], pos, ans;

void countSort() {
	inc(i, 1, m) tax[i] = 0;
	inc(i, 1, n) tax[rk[i]]++;
	inc(i, 1, m) tax[i] += tax[i - 1];
	dec(i, n, 1) sa[tax[rk[tp[i]]]--] = tp[i];
}

void getSA() {
	m = 127;
	inc(i, 1, n) rk[i] = s[i] - '0' + 1, tp[i] = i;
	countSort();
	for (int p = 0, b = 1; p < n; m = p, b <<= 1) {
		p = 0;
		inc(i, n - b + 1, n) tp[++p] = i;
		inc(i, 1, n) if (sa[i] > b) tp[++p] = sa[i] - b;
		countSort();
		swap(rk, tp);
		rk[sa[1]] = p = 1;
		inc(i, 2, n) {
			int x = (sa[i] + b > n ? -1 : tp[sa[i] + b]);
			int y = (sa[i - 1] + b > n ? -1 : tp[sa[i - 1] + b]);
			rk[sa[i]] = (tp[sa[i]] == tp[sa[i - 1]] && x == y ? p : ++p);
		}
	}
}

void getHeight() {
	int k = 0;
	inc(i, 1, n) {
		if (rk[i] == 1) continue;
		if (k) k--;
		int j = sa[rk[i] - 1];
		while (j + k <= n && i + k <= n && s[j + k] == s[i + k]) k++;
		height[rk[i]] = k;
	}
}

void solve() {
	scanf("%s", tmp + 1);
	for (int i = 1; tmp[i]; i++) {
		s[++n] = tmp[i];
	}
	s[++n] = '0';
	pos = n;
	scanf("%s", tmp + 1);
	for (int i = 1; tmp[i]; i++) {
		s[++n] = tmp[i];
	}
	getSA();
	getHeight();
	inc(i, 2, n) {
		if (sa[i] < pos && sa[i - 1] > pos || sa[i - 1] < pos && sa[i] > pos) {
			ans = max(ans, height[i]);
		}
	}
	printf("%d", ans);
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}