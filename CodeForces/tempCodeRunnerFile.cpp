#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int canonicalResidue(int x, int k) {
    int r = x % k;
    if (r == 0) {
        return 0;
    } else {
        if (r < k - r) {
            return r;
        } else {
            return k - r;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n;
        int k;
        cin >> n >> k;
        vector<int> S(n);
        vector<int> T(n);
        for (int i = 0; i < n; i++) {
            cin >> S[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> T[i];
        }
        vector<int>canonS(n);
        vector<int>canonT(n);
        for (int i = 0; i < n; i++) {
            canonS[i] = canonicalResidue(S[i], k);
        }
        for (int i = 0; i < n; i++) {
            canonT[i] = canonicalResidue(T[i], k);
        }
        sort(canonS.begin(), canonS.end());
        sort(canonT.begin(), canonT.end());
        if (canonS == canonT) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
