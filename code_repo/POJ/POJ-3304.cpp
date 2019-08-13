/*

题意：有n个线段，是否存在一条直线，使投影在这条直线上的n个线段有公共点

解：也就是是否有一条直线和这些线段都相交，相当于是否存在过这些线段的某2个端点的直线和这些线段都相交

*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <iostream>


#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 100 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

int sgn(double x) {
    if (fabs(x) < EPS) return 0;
    if (x < 0) return -1;
    return 1;
}

struct Point {
    double x, y;

    Point(double x = 0, double y = 0): x(x), y(y) {}

    Point operator-(const Point & a)const {
        return Point(x - a.x, y - a.y);
    }

    double operator*(const Point & a) {
        return x * a.x + y * a.y;
    }

    double operator^(const Point & a) {
        return x * a.y - y * a.x;
    }
};

struct Line {
    Point s, t;

    Line(Point s = Point(), Point t = Point()): s(s), t(t) {}
} ls[MAX_N];

int T, n;

double xMul(Point p0, Point p1, Point p2) {
    return (p1 - p0) ^ (p2 - p0);
}

bool intersect(const Line & a, const Line & b) {
    Point v1 = a.t - a.s, v2 = b.s - a.s, v3 = b.t - a.s;
    Point u1 = b.t - b.s, u2 = a.s - b.s, u3 = a.t - b.s;
    if (sgn((v1 ^ v2) * (v1 ^ v3)) <= 0 && sgn((u1 ^ u2) * (u1 ^ u3)) <= 0) return 1;
    return 0; 
}

bool intersct(const Line & a, const Line & b) {
    return sgn(xMul(b.s, a.s, a.t)) * sgn(xMul(b.t, a.s, a.t)) <= 0;
}

double dist(Point a, Point b) {
    Point v = b - a;
    return sqrt(v * v);
}

inline bool check(const Line & L) {
    if (!sgn(dist(L.s, L.t))) return 0;
    inc(i, 1, n) {
        if (!intersct(L, ls[i])) return 0;
    }
    return 1;
}

void solve() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        inc(i, 1, n) {
            scanf("%lf%lf%lf%lf", &ls[i].s.x, &ls[i].s.y, &ls[i].t.x, &ls[i].t.y);
        }
        bool f = 0;
        inc(i, 1, n) {
            inc(j, i , n) {
                if(check(Line(ls[i].s, ls[j].s)) 
                    || check(Line(ls[i].s, ls[j].t))
                    || check(Line(ls[i].t, ls[j].s))
                    || check(Line(ls[i].t, ls[j].t))) {
                    f = 1;
                    break;
                }
            }
        }
        if (f) puts("Yes!");
        else puts("No!");
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    solve();
    return 0;
}