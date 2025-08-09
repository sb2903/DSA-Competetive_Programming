#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int count=0;
        for(int i=0;i<n/2;i++){
            if(s[i]==s[n-i-1]){
                count++;
            }
        }
        if(k<=){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        
    }
    

    return 0;
}