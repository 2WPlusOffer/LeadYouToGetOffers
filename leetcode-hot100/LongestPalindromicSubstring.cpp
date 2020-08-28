class Solution {
public:
    pair<int, int> kuosan(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int begin = 0, end = 0;
        for (int i = 0; i < n; i++) {
            auto [left, right] = kuosan(s, i, i);
            if (end - begin < right - left) {
                end = right;
                begin = left;
            }
            auto [left1, right1] = kuosan(s, i, i+1);
            if (end - begin < right1 - left1) {
                end = right1;
                begin = left1;
            }
        }
        return string(s.begin()+begin, s.begin()+end+1);
    }
};