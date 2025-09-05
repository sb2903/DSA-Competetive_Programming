#include <iostream>
using namespace std;

bool ifPossible(int x, int y) {
    int mx = max(x,y), mn = min(x,y);
    if(mx <= 2*(mn + 1)){
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int A2 = c - a, B2 = d - b;
        if (ifPossible(a,b) && ifPossible(A2,B2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
