class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ReturnArray(n, 0);
        stack<pair<int,int>> myStack; // {temp, index}

        for (int i = 0; i < n; i++) {
            while (!myStack.empty() && temperatures[i] > myStack.top().first) {
                int k = myStack.top().second;
                ReturnArray[k] = i - k;
                myStack.pop();
            }
            myStack.push({temperatures[i], i});
        }
        return ReturnArray;
    }
};