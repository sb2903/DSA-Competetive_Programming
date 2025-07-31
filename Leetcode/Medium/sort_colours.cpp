class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ZeroCount=0;
        int oneCount=0;
        int twoCount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ZeroCount++;
            }
            else if(nums[i]==1){
                oneCount++;
            }
            else if(nums[i]==2){
                twoCount++;
            }
        }
        int index = 0;
        for (int i = 0; i < ZeroCount; i++) {
            nums[index++] = 0;
        }
        for (int i = 0; i < oneCount; i++) {
            nums[index++] = 1;
        }
        for (int i = 0; i < twoCount; i++) {
            nums[index++] = 2;
        }
    }
};