class Solution {
public:
    void backtrace(vector<string> &res, string &path, int lc, int rc, int n) {
        if (lc > n || rc > lc) return;
        if (lc == rc && lc == n) res.push_back(path);
        else {
            path.push_back('(');
            backtrace(res, path, lc+1, rc, n);
            path.pop_back();
            path.push_back(')');
            backtrace(res, path, lc, rc+1, n);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int lc = 0, rc = 0;
        string path;
        backtrace(ans, path, lc, rc, n);
        return ans;
    }
};