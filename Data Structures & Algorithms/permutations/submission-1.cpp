class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> subset;
        vector<vector<int>> result;
        vector<bool> track(nums.size(),false);
        recurr(nums,subset,result, track);
        return result;
    }

    void recurr(vector<int>& nums,vector<int> & subset, vector<vector<int>> & result, vector<bool> & track )
    {
        
        if(subset.size() == nums.size())
        {
            result.push_back(subset);
            return;
        }



            for(int j = 0; j<nums.size();j++)
            {
                if(!track[j]){
                subset.push_back(nums[j]);
                track[j] = true;
                recurr(nums,subset,result,track);
                track[j] = false;
                subset.pop_back();
                }
            }
    }



};
