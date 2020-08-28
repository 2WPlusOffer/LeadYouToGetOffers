class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};
        int mid, left = 0, right = n - 1;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (target <= nums[mid]) right = mid;
            else left = mid + 1; 
        }
        int start = nums[left] == target? left: -1;
        left = 0;
        right = n - 1;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (target >= nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
        int end = right >= 0 && nums[right] == target? right: -1;
        return vector<int>{start, end}; 
    }
};