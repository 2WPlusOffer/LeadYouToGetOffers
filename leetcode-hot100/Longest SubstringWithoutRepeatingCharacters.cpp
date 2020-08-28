class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int ans = 1, cur;
        unordered_map<char, int> pos_dict;
        pos_dict[s[0]] = 0;
        int left = 0;
        for (int i = 1; i < n; i++) {
            auto it = pos_dict.find(s[i]);
            if (it != pos_dict.end()) left = max(left, it->second + 1);
            cur = i - left + 1;
            ans = max(ans, cur);
            pos_dict[s[i]] = i;
        }
        return ans;
    }
};