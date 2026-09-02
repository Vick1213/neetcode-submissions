class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> result;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        recurr( 0, subset,result,target, candidates);
        return result;
    }

void recurr(int i, vector<int>& subset, vector<vector<int>>& result, int target, vector<int>& candidates)
{
    if (target == 0) {
        result.push_back(subset);
        return;
    }
    if (i >= candidates.size() || target < 0) return;

    
    subset.push_back(candidates[i]);
    recurr(i + 1, subset, result, target - candidates[i], candidates);
    subset.pop_back();

  
    int j = i + 1;
    while (j < candidates.size() && candidates[j] == candidates[i]) j++;
    recurr(j, subset, result, target, candidates);
}
};
