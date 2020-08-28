class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, left = 0, right = nums.size()-1;
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (nums[left] <= nums[mid]) {
                if (target <= nums[mid] && nums[left] <= target)
                    right = mid;
                else left = mid + 1;
            }else {
                if (target <= nums[mid] || target >= nums[left]) right = mid;
                else left = mid + 1;
            }
        }
        return nums[left] == target? left: -1;
    }
};