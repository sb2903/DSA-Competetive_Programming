#include <iostream>
#include <cmath>
using namespace std;

bool perfect(int n,int root) {
    if(root*root==n){
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int root=ceil(sqrt(n));
        if (perfect(n,root)){
            cout << 0 << " " << root << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
