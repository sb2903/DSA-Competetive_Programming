class Solution {
private:
    bool knows(vector<vector<int> >& mat,int a,int b,int n){
        if(mat[a][b]==1){
            return true;
        }
        else{
            return false;
        }
    }
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int>s;
        for(int i=0;i<mat.size();i++){
            s.push(i);
        }
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(knows(mat,a,b,mat.size())){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        //step 3 single element
        int candidate=s.top();
        bool rowCheck=false;
        int zeroCount=0;
        for(int i=0;i<mat.size();i++){
            if(i!=candidate && mat[candidate][i]==0){
                zeroCount++;
            }
        }
        if(zeroCount==mat.size()-1){
            rowCheck=true;
        }
        bool colCheck=false;
        int oneCount=0;
        for(int i=0;i<mat.size();i++){
            if(i!= candidate && mat[i][candidate]==1){
                oneCount++;
            }
        }
        if(oneCount==mat.size()-1){
            colCheck=true;
        }
        if(rowCheck==true && colCheck==true){
            return candidate;
        }
        else{
            return -1;
        }
        
        
    }
};