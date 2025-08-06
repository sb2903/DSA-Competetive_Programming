class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;
        int count=0;
        //Initializing the Indexes
        int startingRow=0;
        int endingRow=row-1;
        int startingCol=0;
        int endingCol=col-1;
        while(count<total){
            //Print the 1st row
            for(int index=startingCol;index <= endingCol && count<total;index++){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            //Print the ending Column
            for(int index=startingRow;index<=endingRow && count<total;index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            //print the last row
            for(int index=endingCol;index>=startingCol && count<total;index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            //printing the starting column
            for(int index=endingRow;index>=startingRow && count<total;index--){
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
        
        
    }
};