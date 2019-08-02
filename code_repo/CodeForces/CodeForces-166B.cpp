/*

题意：有凸多边形A和多边形B，判断B是否严格在A内部

解：2个多边形的点放在一起求凸包，凸包上的点全是A的点则YES

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

struct Point {
	LL x, y, clr;

	Point(LL x = 0, LL y = 0): x(x), y(y) {}

	bool operator<(const Point& a) {
		if (x == a.x) return y < a.y;
		return x < a.x;
	}

	Point operator-(const Point& a) {
		return Point(x - a.x, y - a.y);
	}

	LL operator*(const Point& a) {
		return x * a.y - y * a.x;
	}
} ps[MAX_N];
LL n, stk[MAX_N], top, convex[MAX_N], tot, m;
bool vis[MAX_N];

void andrew() {
	stk[++top] = 1;
	for (int i = 2; i <= n; i++) {
		while (top >= 2 && (ps[stk[top]] - ps[stk[top - 1]]) * (ps[i] - ps[stk[top]]) < 0) vis[stk[top--]] = 0;
		stk[++top] = i;
		vis[i] = 1;
	}
	for (int i = n - 1; i >= 1; i--) {
		if (vis[i]) continue;
		while (top >= 2 && (ps[stk[top]] - ps[stk[top - 1]]) * (ps[i] - ps[stk[top]]) < 0) vis[stk[top--]] = 0;
		stk[++top] = i;
		vis[i] = 1;
	}
	tot = top - 1;
	for (int i = 1; i <= tot; i++) {
		convex[i] = stk[i];
	}
}

void solve() {
	scanf("%I64d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d%I64d", &ps[i].x, &ps[i].y);
		ps[i].clr = 1;
	}
	scanf("%I64d", &m);
	for (int i = n + 1; i <= n + m; i++) {
		scanf("%I64d%I64d", &ps[i].x, &ps[i].y);
		ps[i].clr = 2;
	}
	n += m;
	bool f = 1;
	sort(ps + 1, ps + n + 1);
	andrew();
	for (int i = 1; i <= tot; i++) {
		if (ps[convex[i]].clr != 1) {
			f = 0;
			break;
		}
	}
	if (f) puts("YES");
	else puts("NO");
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}