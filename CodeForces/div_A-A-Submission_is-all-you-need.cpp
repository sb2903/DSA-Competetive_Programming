#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        long long sum = 0;
        int zero = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            if (x == 0){ 
                zero++;
            } 
        }
        cout << (sum + zero) << endl;
    }
    return 0;
}
