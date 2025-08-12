#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin >> t)){
        return 0;
    }
    for(int i=0;i<t;i++) {
        int n; 
        cin >> n;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                cout << -1;
            } 
            else {
                if (i == n) cout << 2;
                else cout << 3;
            }
            if(i==n){
                cout<<"\n";
            }
            else{
                cout<<" ";
            }
        }
    }
    return 0;
}
