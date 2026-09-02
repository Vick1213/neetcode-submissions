class Solution {
public:
vector<vector<int>> results;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        recurr(nums,0,subset);
        return results;
    }
    void recurr(vector<int>& nums, int count, vector<int> &subset){
        if(count == nums.size())
        {
            results.push_back(subset);
            return;
        }
        subset.push_back(nums[count]);
        recurr(nums,count+1, subset);
        subset.pop_back();
        recurr(nums,count+1,subset);
    }
};