#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int gellyfishHP, flowerHP, gellyfishKnightHP, flowerKnightHP;
        cin >> gellyfishHP >> flowerHP >> gellyfishKnightHP >> flowerKnightHP;
        bool canWinByAttackingPlayer = (flowerHP <= gellyfishHP && flowerHP <= gellyfishKnightHP);
        bool canWinByKillingKnight = (gellyfishHP >= flowerKnightHP && flowerKnightHP <= gellyfishKnightHP);
        if (canWinByAttackingPlayer || canWinByKillingKnight) {
            cout << "Gellyfish\n";
        } else {
            cout << "Flower\n";
        }
    }
    return 0;
}
