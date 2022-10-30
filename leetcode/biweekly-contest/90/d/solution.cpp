#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define rall rbegin(a), rend(a)
#define bitcnt(x) (__builtin_popcountll(x))
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define MP make_pair

using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using VLL = std::vector<ll>;
using VI = std::vector<int>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename S>
inline bool chmax(T &a, const S &b) {
    return a < b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool chmin(T &a, const S &b) {
    return a > b ? a = b, 1 : 0;
}

#ifdef LOCAL
#include <debug.hpp>
#else
#define dbg(...)
#endif
// head

class Solution {
public:
    vector<int> secondGreaterElement(vector<int> &nums) {
        int n = int(nums.size());

        auto se = set<int>();
        auto vec = vector<pair<int, int>>();
        for (int i = 0; i < n; i++) {
            vec.push_back(make_pair(nums[i], i));
        }

        sort(all(vec));
        reverse(all(vec));

        auto res = vector<int>(n, -1);

        for (int i = 0, j = 0; i < n; i++) {
            for (; j < i && vec[j].first > vec[i].first; j++) {
                se.insert(vec[j].second);
            }

            const auto &p = vec[i];
            auto pos = se.lower_bound(p.second);
            if (pos != se.end()) {
                ++pos;
                if (pos != se.end()) {
                    res[p.second] = nums[*pos];
                }
            }
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif
