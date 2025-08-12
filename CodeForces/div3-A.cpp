#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i){ 
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i){
        cin >> b[i];
        }
        long long leftover = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]){ 
            leftover += (a[i] - b[i]);
            }
        }
        cout << (leftover + 1) << '\n';
    }
    return 0;
}
