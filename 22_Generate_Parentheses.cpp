class Solution {
public:
    vector<string> ans;
    void recurse(string s,int open,int close,int n){
        // Base case
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }
        // If we can add an open bracket
        if(open < n){
            recurse(s + '(', open + 1, close, n);
        }
        // If we can add a close bracket
        if(close < open){
            recurse(s + ')', open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        recurse("", 0, 0, n);
        return ans;
    }
};
