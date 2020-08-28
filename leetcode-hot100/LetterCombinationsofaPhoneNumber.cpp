class Solution {
public:
    void backtrace(vector<string> &combinations, unordered_map<char, string> &hashMap, string &digits, int index, string &combination) {
        if (index == digits.size()) combinations.push_back(combination);
        else {
            string letters = hashMap[digits[index]];
            for (auto letter: letters) {
                combination.push_back(letter);
                backtrace(combinations, hashMap, digits, index+1, combination);
                combination.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() == 0) return ans;
        unordered_map<char, string> hashMap {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination;
        backtrace(ans, hashMap, digits, 0, combination);
        return ans;
    }
};