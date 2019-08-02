/*

题意：有n个盒子，编号1~n，n种颜色的球，颜色编号1~n，第i种颜色有ai个，一开始所有的球都在第一个盒子里，要求把颜色i的球放到盒子i里，每次的操作是先选择一个非空的盒子，把盒子里所有的球分成k组放到k个盒子（k=2或3），每次操作的代价是选择的盒子里所有的球数，求最小代价

解：首先考虑每次分组分成3组答案更优，然后倒着想，颜色i的球已经在盒子i里，需要合并到一个盒子里，这是求一个3叉的哈夫曼树

*/

#include <cstdio>
#include <queue>

using namespace std;

typedef long long LL;

const int MAX_N = 1e4 + 5;

int n;
LL ans;
priority_queue<LL> Q;

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		LL a;
		scanf("%I64d", &a);
		Q.push(-a);
	}
	if (!(n & 1)) Q.push(0);
	for (int i = 1; i <= n >> 1; i++) {
		LL tmp = -Q.top(); Q.pop();
		tmp += -Q.top(); Q.pop();
		tmp += -Q.top(); Q.pop();
		ans += tmp;
		Q.push(-tmp);
	}
	printf("%I64d", ans);
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}