/*

题意：n个元素，元素i有ai、bi、ci三个属性，f(i)是满足aj<=ai且bj<=bi且cj<=ci的j的数量，j!=i。对于0<=d<n，求f(i)==d的i的数量

解：CDQ分治 板子题

*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 10;
const int MAX_M = 2e5 + 5;
const int INF = 0x3f3f3f3f;

struct Node {
	int a, b, c, cnt, ans;
} ns_[MAX_N], ns[MAX_N];

bool comA(const Node & x, const Node & y) {
	if (x.a == y.a) {
		if (x.b == y.b) {
			return x.c < y.c;
		}
		return x.b < y.b;
	}
	return x.a < y.a;
}

bool comB(const Node & x, const Node & y) {
	if (x.b == y.b) {
		return x.c < y.c;
	}
	return x.b < y.b;
}

int n_, n, m, Cnt[MAX_N];

int read() {
	int res = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
}

namespace BIT{
	int c[MAX_M];

	inline int lowbit(int x) {return x & (-x);}

	void add(int x, int k) {
		while (x <= m) {
			c[x] += k;
			x += lowbit(x);
		}
	}

	int query(int x) {
		int res = 0;
		while (x >= 1) {
			res += c[x];
			x -= lowbit(x);
		}
		return res;
	}
}

void CDQ(int L, int R) {
	if (L == R) return;
	int mid = (L + R) >> 1;
	CDQ(L, mid), CDQ(mid + 1, R);
	sort(ns + L, ns + mid + 1, comB), sort(ns + mid + 1, ns + R + 1, comB);
	int i = mid + 1, j = L;
	for (; i <= R; i++) {
		for (; ns[j].b <= ns[i].b && j <= mid; j++) {
			BIT::add(ns[j].c, ns[j].cnt);
		}
		ns[i].ans += BIT::query(ns[i].c);
	}
	inc(i, L, j - 1) {
		BIT::add(ns[i].c, -ns[i].cnt);
	}
}

void solve() {
	n_ = read(), m = read();
	inc(i, 1, n_) ns_[i].a = read(), ns_[i].b = read(), ns_[i].c = read();
	sort(ns_ + 1, ns_ + n_ + 1, comA);
	int cnt = 0;
	inc(i, 1, n_) {
		cnt++;
		if (ns_[i].a != ns_[i + 1].a || ns_[i].b != ns_[i + 1].b || ns_[i].c != ns_[i + 1].c) {
			ns[++n] = ns_[i], ns[n].cnt = cnt, cnt = 0;
		}
	};
	CDQ(1, n);
	inc(i, 1, n) {
		Cnt[ns[i].ans + ns[i].cnt - 1] += ns[i].cnt;
	}
	inc(i, 0, n_ - 1) {
		printf("%d\n", Cnt[i]);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}