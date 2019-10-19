/*
半平面交 板子
只有空集才为NO
qwq
*/

#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_V = 200 + 5;
const double EPS = 1e-8;

struct Point {
	double x, y;
	
	Point(double x = 0, double y = 0):x(x), y(y) {}
};

struct Segment {
	Point s, t;
};

Point ps[MAX_V], qps[MAX_V];
Segment ss[MAX_V], q[MAX_V];
int T, n;

int sgn(double x) {
	if (fabs(x) < EPS) return 0;
	if (x < 0) return -1;
	return 1;
}

Point operator-(const Point & a, const Point & b) {
	return Point(a.x - b.x, a.y - b.y);
}
	
double operator^(const Point & a, const Point & b) {
	return a.x * b.y - a.y * b.x;
}
	
bool isLeft(const Point & p, const Point & s, const Point & t) {
	return sgn((t - s) ^ (p - s)) >= 0; //在线上和左边
}

bool operator==(const Segment & a, const Segment & b) {
	Point ap = a.t - a.s, bp = b.t - b.s;
	double t1 = atan2(ap.y, ap.x), t2 = atan2(bp.y, bp.x);
	return sgn(t1 - t2) == 0;
}

Point intersect(const Segment & a, const Segment & b) {
	if (sgn((a.t - a.s) ^ (b.t - b.s)) == 0) { //防止无穷多个交点
		return Point(a.t.x, a.t.y);
	}
	Point v1 = a.t - a.s, v2 = b.t - b.s, v3 = a.t - b.t;
	double T = (v3 ^ v2) / (v1 ^ v2);
	return a.t - Point(T * v1.x, T * v1.y);
}

bool cmp(const Segment & a, const Segment & b) {
	Point ap = a.t - a.s, bp = b.t - b.s;
	double t1 = atan2(ap.y, ap.x), t2 = atan2(bp.y, bp.x);
	if (sgn(t1 - t2)) {
		return t1 < t2;
	}
	return isLeft(a.s, b.s, b.t);
}

bool halfPlaneIntersection() {
	int L = 1, R = 0;
	sort(ss + 1, ss + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		if (ss[i - 1] == ss[i]) continue;
		while (R - L >= 1 && !isLeft(qps[R], ss[i].s, ss[i].t)) --R;
		while (R - L >= 1 && !isLeft(qps[L + 1], ss[i].s, ss[i].t)) ++L; //注意是qps[L + 1]，qwq
		q[++R] = ss[i];
		if (R - L >= 1) qps[R] = intersect(q[R - 1], q[R]);
	}
	while (R - L >= 1 && !isLeft(qps[R], q[L].s, q[L].t)) --R;
	if (R - L >= 1) qps[R + 1] = intersect(q[R], q[L]);
	if (R - L <= 1 ) return 0; //判断是否是空集
	return 1;
}

void solve() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			ps[i].x = x, ps[i].y = y;
		}
		for (int i = 1; i <= n; ++i) {
			ss[i].s = ps[i % n + 1], ss[i].t = ps[i];
		}
		if (halfPlaneIntersection()) puts("YES");
		else puts("NO");
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}