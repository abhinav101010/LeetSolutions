class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            if(i==0) result.push_back(nums[i]);
            if(result[result.size()-1] != nums[i]) result.push_back(nums[i]);
        }
        nums = result;
        return result.size();
    }
};