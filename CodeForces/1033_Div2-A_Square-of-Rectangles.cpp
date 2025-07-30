#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<string>result;
    
    
    while(t>=1){
        int l1,b1,l2,b2,l3,b3;
        cin>>l1>>b1>>l2>>b2>>l3>>b3;
        string res="no";
        //case1
        if(l1==l2 && l2==l3 && l3==l1 && b1+b2+b3==l1){
            res="yes";
        
        }
        //case2
        else if(b1==b2 && b2==b3 && b3==b1 && l1+l2+l3==b1){
            res="yes";
            
        }
        //case 3
        else if((l2+l3==l1)&& (b3==b2) && (b1+b2)==l1){
            res="yes";
            
        }
        //case 4
        else if((b2+b3==b1)&&(l2==l3)&&(l1+l2==b1)){
            res="yes";
            
        }
        result.push_back(res);
        t--;
    }
    for(const string& ans:result){
        cout<<ans<<"\n";
    }
 
 
    return 0;
}