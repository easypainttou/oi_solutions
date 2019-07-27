/*

题意：小写字母组成的字符串被表示成一些分块，一个分块是li个ci字符，给出以上方法表示的字符串t和s，求s在t中出现的次数

解：
先合并相同的字符，使相邻分块的字符都不相同
然后s为1或2个分块时，暴力
s为3个及以上分块，使用kmp匹配，模式串为去掉第1和第m个分块后的s，主串为去掉第1和第n个分块后的t，然后如果某处匹配再检测去掉的2个分块

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 2e5 + 5;

struct node {
	LL l;
	char c;
	bool operator==(const node& a)const {
		return c == a.c && l == a.l;
	}
	bool operator<=(const node& a)const {
		return c == a.c && l <= a.l;
	}
} s[MAX_N], t[MAX_N];

LL n, m, ans, nxt[MAX_N];

void compress(node* a, LL& len) {
	LL tot = 0;
	for (int i = 1; i <= len; i++) {
		if (tot == 0 || a[tot].c != a[i].c) a[++tot] = a[i];
		else a[tot].l += a[i].l;		
	}
	len = tot;
}

void preKmp(int m, node* s) {
	LL j = nxt[1] = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && !(s[j + 1] == s[i + 1])) j = nxt[j];
		if (s[j + 1] == s[i + 1]) j++;
		nxt[i + 1] = j;
	}
}

void kmp(int n, int m, node* t, node* s) {
	preKmp(m, s);
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && !(s[j + 1] == t[i + 1])) j = nxt[j];
		if (s[j + 1] == t[i + 1]) {
			j++;
		}
		if (j == m) {
			int L = i + 1 - m, R = i + 2;
			if (s[0] <= t[L] && s[m + 1] <= t[R]) ans++;
			j = nxt[j];
		}
	}
}

void solve() {
	scanf("%I64d%I64d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%I64d-%c", &t[i].l, &t[i].c);
	for (int i = 1; i <= m; i++) scanf("%I64d-%c", &s[i].l, &s[i].c);
	compress(t, n);
	compress(s, m);
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			if (s[1] <= t[i]) {
				ans += t[i].l - s[1].l + 1;
			}
		}
	} else if (m == 2) {
		for (int i = 1; i <= n - 1; i++) {
			if (s[1] <= t[i] && s[2] <= t[i + 1]) {
				ans++;
			}
		}
	} else {
		kmp(n - 2, m - 2, t + 1, s + 1);
	}
	printf("%I64d", ans);
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}