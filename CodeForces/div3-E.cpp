#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAX_VAL = 1000001;
// spf[i] stores the smallest prime factor of i
int spf[MAX_VAL];

// Pre-computation using a sieve
void sieve() {
    iota(spf, spf + MAX_VAL, 0);
    for (int i = 2; i * i < MAX_VAL; ++i) {
        if (spf[i] == i) { // i is a prime number
            for (int j = i * i; j < MAX_VAL; j += i) {
                if (spf[j] == j) {
                    spf[j] = j;
                }
            }
        }
    }
}

// Gets the distinct prime factors of a number
vector<int> get_prime_factors(int n) {
    vector<int> factors;
    while (n > 1) {
        int p = spf[n];
        factors.push_back(p);
        while (n % p == 0) {
            n /= p;
        }
    }
    return factors;
}

// Global data structures needed across test cases
vector<int> pos[MAX_VAL];
bool is_used[200005];
int a_val[200005];
vector<int> unmatched_stack;

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        pos[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        is_used[i] = false;
        cin >> a_val[i];
        pos[a_val[i]].push_back(i);
    }

    unmatched_stack.clear();
    vector<pair<int, int>> pairs;

    // Iterate greedily from largest to smallest value
    for (int v = m; v >= 1; --v) {
        if (pos[v].empty()) continue;

        // Take one instance of value `v`
        int v_idx = pos[v].back();
        pos[v].pop_back();

        int partner_idx = -1;
        int best_partner_val = -1;

        // Try to find a coprime partner from the unmatched stack
        // This linear scan is okay because we cleverly remove items,
        // so we don't do n^2 work overall.
        for (int p_idx : unmatched_stack) {
            if (gcd(v, a_val[p_idx]) == 1) {
                partner_idx = p_idx;
                best_partner_val = a_val[p_idx];
                break;
            }
        }

        if (partner_idx != -1) {
            // Found a partner, form a pair
            pairs.push_back({v_idx, partner_idx});
            is_used[v_idx] = true;
            is_used[partner_idx] = true;
            
            // Rebuild the stack without the used partner
            vector<int> next_stack;
            for (int p_idx : unmatched_stack) {
                if (p_idx != partner_idx) {
                    next_stack.push_back(p_idx);
                }
            }
            unmatched_stack = next_stack;
        } else {
            // No partner found, add to stack
            unmatched_stack.push_back(v_idx);
        }
    }

    if (pairs.size() < 2) {
        cout << 0 << "\n";
    } else {
        cout << pairs[0].first << " " << pairs[1].second << " " << pairs[1].first << " " << pairs[0].second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Sieve is not strictly needed for this simpler logic but is good practice for number theory
    // sieve(); 

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}