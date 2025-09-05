#include <iostream>
#include<vector>
using namespace std;
using ll = long long;
struct Interval {
    int start, end, w;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<ll> results(t);
    vector<vector<int>> all_a(t);
    vector<int> all_n(t);
    for (int ti = 0; ti < t; ++ti) {
        int n;
        cin >> n;
        all_n[ti] = n;
        all_a[ti].resize(n);
        for (int i = 0; i < n; i++) {
            cin >> all_a[ti][i];
        }
    }
    for (int ti = 0; ti < t; ++ti) {
        int n = all_n[ti];
        auto &a = all_a[ti];
        vector<vector<int>> pos(n+1);
        for (int i = 0; i < n; i++) {
            pos[a[i]].push_back(i);
        }
        vector<Interval> intervals;
        for (int x = 1; x <= n; x++) {
            int c = (int)pos[x].size();
            int maxBlocks = c / x;
            for (int j = 1; j <= maxBlocks; j++) {
                int s = pos[x][(j-1)*x];
                int e = pos[x][j*x - 1];
                intervals.push_back({s, e, x});
            }
        }
        if (intervals.empty()) {
            results[ti] = 0;
            continue;
        }
        sort(intervals.begin(), intervals.end(),
             [](const Interval &A, const Interval &B) {
                 return A.end < B.end;
             });

        int m = intervals.size();
        vector<int> ends(m);
        for (int i = 0; i < m; i++) ends[i] = intervals[i].end;
        vector<ll> dp(m+1, 0);
        for (int i = 1; i <= m; i++) {
            int s = intervals[i-1].start;
            int w = intervals[i-1].w;
            int idx = (int)(lower_bound(ends.begin(), ends.begin() + (i-1), s) - ends.begin());
            dp[i] = max(dp[i-1], dp[idx] + w);
        }

        results[ti] = dp[m];
    }
    for (ll i=0;i<results.size();i++) {
        cout << results[i] << '\n';
    }
    return 0;
}
