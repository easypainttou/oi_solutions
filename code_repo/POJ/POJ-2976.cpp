/*

题意：选择n-k个i，使100*sum(ai)/sum(bi)最大

解：01分数规划 板子题

*/

#include <cstdio>
#include <cmath>
#include <algorithm>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e3 + 10;
const int MAX_M = 3e4 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;

int n, k, a[MAX_N], b[MAX_N];
double tmp[MAX_N];

inline bool check(double x) {
	double res = 0;
	inc(i, 1, n) tmp[i] = a[i] - x * b[i];
	sort(tmp + 1, tmp + n + 1);
	inc(i, k + 1, n) res += tmp[i];
	return res >= 0;
}

void solve() {
	while (1) {
		scanf("%d%d", &n, &k);
		if (!n && !k) break;
		inc(i, 1, n) scanf("%d", a + i);
		inc(i, 1, n) scanf("%d", b + i);
		double L = 0, R = INF, ans = 0;
		while (fabs(R - L) >= EPS) {
			double mid = (L + R) / 2;
			if (check(mid)) L = ans = mid;
			else R = mid;
		}
		printf("%d\n", int(100 * ans + 0.5));
	}
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    solve();
    return 0;
}