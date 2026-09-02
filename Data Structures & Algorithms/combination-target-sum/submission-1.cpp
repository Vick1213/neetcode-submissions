class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) { 

        
        vector<vector<int>> result;
        vector<int> subset;
        recurr(0,target,result,subset,nums);
        return result;
    }

   void recurr(int count, int target, vector<vector<int>> &result, vector<int> & subset, vector<int>& nums)
    {
         int sum = std::accumulate(subset.begin(), subset.end(), 0);
        if( sum == target)
        {
            result.push_back(subset);
            return;
        }
        if (count == nums.size() || sum>target) return;

        subset.push_back(nums[count]);
        recurr(count,target,result,subset,nums);
        subset.pop_back();
        recurr(count+1,target,result,subset,nums);
    }
};
