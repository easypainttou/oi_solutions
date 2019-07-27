/*

题意：n*m的原矩阵的i行j列数字为(i-1)*m+j，改变数字位置，使原来相邻的不相邻，可行输出“YES”和解，否则“NO”

解：
解法很多。。。看到有随机化，dfs，分类讨论的
这里给出dfs

*/

#include <cstdio>
#include <iostream>

typedef long long LL;

using namespace std;

const int MAX_N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, a[MAX_N], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

inline bool check(int a1, int a2) {
	int x1 = (a1 - 1) / m + 1, y1 = (a1 - 1) % m + 1, x2 = (a2 - 1) / m + 1, y2 = (a2 - 1) % m + 1;
	for (int i = 0; i < 4; i++) {
		if (x1 + dx[i] == x2 && y1 + dy[i] == y2) return 1;
	}
	return 0;
}

bool dfs(int step) {
	if (step == n * m + 1) return 1;
	int x = (step - 1) / m + 1, y = (step - 1) % m + 1;
	for (int i = step; i <= n * m; i++) {
		swap(a[i], a[step]);
		if (x != 1 && check(a[(x - 2) * m + y], a[step])) continue;
		if (y != 1 && check(a[(x - 1) * m + y - 1], a[step])) continue;
		if (dfs(step + 1)) return 1;
		swap(a[i], a[step]);
	}
	return 0;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) a[i] = i;
	if (dfs(1)) {
		puts("YES");
		for (int i = 1; i <= n*m; i++) printf("%d%c", a[i], i % m == 0 ? '\n' : ' ');
	} else {
		puts("NO");
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}