/*

题意：把n分成k个2的幂的和，要求在最大的幂最小的条件下，字典序最大

解：首先确定最小的最大幂，然后每次取最小的幂k的分成2个k-1。。。
是个水题qwq

*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 500 + 10;
const int MAX_M = 3e4 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

LL n, k, m;
multiset<LL> st;
map<LL, LL> cnt;

void solve() {
    scanf("%I64d%I64d", &n, &k);
    inc(i, 0, 62) {
        if (n & 1) cnt[i]++, m++;
        n >>= 1;
    }
    if (k < m) {
        puts("No");
        return;
    }
    dec(i, 62, -62) {
        if (m + cnt[i] <= k) {
            cnt[i - 1] += 2 * cnt[i], m += cnt[i], cnt[i] = 0;
        } else break;
    }
    dec(i, 62, -62) inc(j, 1, cnt[i]) st.insert(i);
    while (st.size() < k) {
        LL u = *st.begin();
        st.erase(st.begin());
        st.insert(u - 1);
        st.insert(u - 1);
    }
    puts("Yes");
    for (multiset<LL>::reverse_iterator it = st.rbegin(); it!=st.rend(); it++) {
        printf("%I64d ", *it);
    } 
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    solve();
    return 0;
}