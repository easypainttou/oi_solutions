/*

题意：n+1辆车，编号0~n，车长li，距离停车线si，速度vi。不能超车，也就是后一辆车距离前一辆车距离为0时速度变成前一辆的速度，求第0辆车到停车线需要的最少时间

解：第0辆的速度最后一定是第i（i=0~n）辆的速度，所以直接枚举最后的速度，算出第0辆到停车线的时间，每次取大

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, l[MAX_N], s[MAX_N], v[MAX_N], lSum;
double ans;

void solve() {
	while (~scanf("%d", &n)) {
		ans = lSum = 0;
		for (int i = 0; i <= n; i++) scanf("%d", l + i);
		for (int i = 0; i <= n; i++) scanf("%d", s + i);
		for (int i = 0; i <= n; i++) scanf("%d", v + i);
		for (int i = 0; i <= n; i++) {
			if (i) lSum += l[i];
			double tmp = 1.0 * (s[i] + lSum) / v[i];
			ans = max(ans, tmp);
		}
		printf("%f\n", ans);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}