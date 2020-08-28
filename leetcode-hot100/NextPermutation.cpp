class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int p = n - 1;
        while (p > 0 && nums[p] <= nums[p-1]) {
            p--;
        }
        reverse(nums.begin() + p, nums.end());
        int pos = p;
        if (pos > 0) {
            for (; pos < n-1; pos++) {
                if (nums[pos] > nums[p-1]) break;
            }
            swap(nums[pos], nums[p-1]);
        }
    }
};