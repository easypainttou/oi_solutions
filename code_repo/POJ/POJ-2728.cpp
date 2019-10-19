/*

题意：给定N个平面上的点的坐标和它们的权值，任意两点之间的边的价值是它们的距离，费用是两点权值之差的绝对值，求该图的一棵生成树，使得该树所有边的费用之和与价值之和的比值最小（只需求这个比值即可）

解：01分数规划
sum(cost[i]) / sum(len[i]) <= x
sum(cost[i]) - sum(len[i]) * x <= 0
所以以cost[i] - len[i] * x作为边权求最小生成树判断边权和是否<=0作为二分的判断
qwq
卡时间的毒瘤题

*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e3 + 10;
const int MAX_M = 3e4 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;

int n, x[MAX_N], y[MAX_N], z[MAX_N];
double len[MAX_N][MAX_N], dis[MAX_N];
bool vis[MAX_N];

//堆优化的会T 绝了 
bool prim(double x) {
	double sum = 0;
	inc(i, 1, n) vis[i] = 0, dis[i] = INF;
	dis[1] = 0;
	inc(i, 1, n) {
		double mn = INF;
		int pos = -1;
		inc(j, 1, n) {
			if (!vis[j] && dis[j] < mn) mn = dis[j], pos = j;
		}
		if (pos == -1) break;
		vis[pos] = 1;
		sum += mn;
		inc(j, 1, n) {
			if (!vis[j] && dis[j] > fabs(z[j] - z[pos]) - x * len[j][pos]) {
				dis[j] = fabs(z[j] - z[pos]) - x * len[j][pos];
			}
		}
	}
	return sum <= 0;
}

void solve() {
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		inc(i, 1, n) scanf("%d%d%d", x + i, y + i, z + i);
		inc(i, 1, n) {
			inc(j, i, n) {
				len[i][j] = len[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
				//cost[i][j] = cost[j][i] = fabs(z[i] - z[j]);
				//这样会T↑ 绝了 
			}
		}
		double L = 0, R = 100; //
		while (fabs(R - L) >= EPS) {
			double mid = (L + R) / 2;
			if (prim(mid)) R = mid;
			else L = mid;
		}
		printf("%.3f\n", R);
	}
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    solve();
    return 0;
}