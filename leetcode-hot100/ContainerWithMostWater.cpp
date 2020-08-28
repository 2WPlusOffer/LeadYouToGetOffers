class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0, cur;
        while (left < right) {
            cur = (right - left) * min(height[left], height[right]);
            ans = max(ans, cur);
            if (height[left] < height[right]) left++;
            else right--;
        }
        return ans;
    }
};