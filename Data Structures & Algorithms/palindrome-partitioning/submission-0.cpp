class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> subset;
        recurr(ret,subset,s, 0);
        return ret;
    }

   void recurr(vector<vector<string>> &ret, vector<string> &subset, string &s, int start) {
    if (start == s.length()) {
        ret.push_back(subset);
        return;
    }
    for (int end = start; end < s.length(); end++) {
        string piece = s.substr(start, end - start + 1);
        if (isPalindrome(piece)) {        // check BEFORE recursing
            subset.push_back(piece);
            recurr(ret, subset, s, end + 1);
            subset.pop_back();            // backtrack
        }
    }
}

    bool isPalindrome(string original)
    {
        std::string reversed;
        reversed.resize(original.length());
        std::reverse_copy(original.begin(), original.end(), reversed.begin());
        if(reversed == original)
        {
            return true;
        }
        else return false;
    }
};
