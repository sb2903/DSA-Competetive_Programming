#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<vector<int>> graph(n + 1);
        vector<int> degree(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        if (n == 2) {
            cout << 0 << "\n";
            continue;
        }
        int leafCount = 0;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 1) leafCount++;
        }
        int maxLeafAdj = 0;
        for (int node = 1; node <= n; node++) {
            int leafNeighbors = 0;
            for (int nei : graph[node]) {
                if (degree[nei] == 1) leafNeighbors++;
            }
            maxLeafAdj = max(maxLeafAdj, leafNeighbors);
        }
        int ans = leafCount - maxLeafAdj;
        cout << ans << "\n";
    }

    return 0;
}
