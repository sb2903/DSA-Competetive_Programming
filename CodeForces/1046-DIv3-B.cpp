#include <iostream>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<bool> possible(t);
    vector<vector<int>> permutations(t);

    for (int ti = 0; ti < t; ++ti) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int maxRun = 0, curRun = 0;
        for (char c : s) {
            if (c == '1') {
                ++curRun;
                maxRun = max(maxRun, curRun);
            } else {
                curRun = 0;
            }
        }
        if (maxRun >= k) {
            possible[ti] = false;
            continue;
        }
        possible[ti] = true;
        vector<int> p(n);
        int nextSmall = 1, nextLarge = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                p[i] = nextSmall++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                p[i] = nextSmall++;
            }
        }
        permutations[ti] = move(p);
    }
    for (int ti = 0; ti < t; ++ti) {
        if (!possible[ti]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int x : permutations[ti]) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
