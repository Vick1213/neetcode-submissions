class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> results;
        sort(nums.begin(),nums.end());
        recurr(nums,subset,results,0);
        return results;
    }

    void recurr(vector<int>& nums,vector<int> & subset, vector<vector<int>>& results, int i){

        if(i == nums.size())
        {
            results.push_back(subset);
            return;
        }
        if(i>nums.size()) return;
        if(subset.size()>nums.size())
        {
            return;
        }

        subset.push_back(nums[i]);
        recurr(nums,subset,results,i+1);
        subset.pop_back();
        int j=i+1;
        while( j<nums.size() && nums[i]==nums[j]) {j++;}
        recurr(nums,subset,results,j);
     }
};
