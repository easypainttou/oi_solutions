/*

题意：n个点m条边的无向图，第i个点的点权为vi。如果图上存在一条路径使得点i可以走到点j，则称i,j是带劲的，记f(i,j)=1；否则f(i,j)=0。显然有f(i,j)=f(j,i)。求∑(i=1,n−1)∑(j=i+1,n)f(i,j)×max(vi,vj)×(vi&vj)

解：使用并查集将点分到不同的集合，然后对于每一个集合中的点从小到大进行排序。集合中的任意两点的f(i,j)=1，需要求出max(v[i],v[j])因为已经排序了，所以答案就是v[j]，还需要求出所有的v[i]&v[j]，这是一个套路，对于二进制的每一位统计出有多少个点在这一位上是1，对于每一位分开计算贡献。

*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <iostream>


#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int T, n, m, v[MAX_N], fa[MAX_N];
LL ans;
vector<int> g[MAX_N];

int findFa(int x) {
    return fa[x] == x ? x : fa[x] = findFa(fa[x]);
}

void solve() {
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d%d", &n, &m);
        inc(i, 1, n) fa[i] = i, g[i].clear(), scanf("%d", v + i);
        inc(i, 1, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            int uf = findFa(u), vf = findFa(v);
            if (uf != vf) {
                fa[uf] = vf;
            }
        }
        inc(i, 1, n) g[findFa(i)].push_back(v[i]);
        inc(i, 1, n) {
            int sz = g[i].size();
            if (!sz) continue;
            sort(g[i].begin(), g[i].end());
            inc(j, 0, 30) {
                int cnt = 0;
                inc (k, 0, sz - 1) {
                    if (g[i][k] >> j & 1) {
                        cnt++;
                    }
                }
                dec (k, sz - 1, 0) {
                    if(g[i][k] >> j & 1) {
                       cnt--;
                       ans = (ans + (LL)cnt * (1 << j) % MOD * g[i][k] % MOD) % MOD;
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    solve();
    return 0;
}