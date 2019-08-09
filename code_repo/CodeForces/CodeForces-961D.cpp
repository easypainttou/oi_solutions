/*

题意：给出直角坐标系中的n个点，坐标都是整数，每个点都不同，是否存在2条直线，所有点都落在这2条直线上

解：枚举前3个点的关系，然后判断共线。。。

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

const int MAX_N = 1e5 + 5;
const int MAX_M = 2e5 + 5;
const int INF = 0x3f3f3f3f;

struct Point {
	LL x, y;

	Point(LL x = 0, LL y = 0): x(x), y(y) {}

	Point operator-(const Point & a) {
		return Point(x - a.x, y - a.y);
	}

	LL operator*(const Point & a) {
		return x * a.y - y * a.x;
	}
} ps1[MAX_N], ps2[MAX_N];

LL n, m, onLine[MAX_N];

void getLine(Point ps[], LL tot, LL a, LL b) {
	memset(onLine, 0, sizeof(onLine));
	Point v = ps[a] - ps[b];
	onLine[a] = onLine[b] = 1;
	inc(i, 1, tot) {
		if (i == a || i == b) continue;
		Point v0 = ps[a] - ps[i];
		if (v * v0 == 0) {
			onLine[i] = 1;
		}
	}
}

bool check(LL a, LL b) {
	m = 0;
	getLine(ps1, n, a, b);
	inc(i, 1, n) {
		if (!onLine[i]) ps2[++m] = ps1[i];
	}
	if (m <= 2) {
		return 1;
	}
	getLine(ps2, m, 1, 2);
	inc(i, 1, m) {
		if (!onLine[i]) return 0;
	}
	return 1;
}

void solve() {
	scanf("%I64d", &n);
	inc(i, 1, n) {
		scanf("%I64d%I64d", &ps1[i].x, &ps1[i].y);
	}
	if (n <= 3) {
		puts("YES");
		return;
	}
	if (check(1, 2) || check(1, 3) || check(2, 3)) {
		puts("YES");
	} else {
		puts("NO");
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}