class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.empty()) return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        int sum, left, right;
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > 0) continue;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            right = nums.size() - 1;
            sum = -nums[i];
            left = i + 1;
            while (left < right) {
                if (nums[left] + nums[right] < sum) left++;
                else if (nums[left] + nums[right] > sum) right--;
                else{
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(right > left && nums[right] == nums[right-1]) right--;
                    while(right > left && nums[left] == nums[left+1]) left++;
                    right--;
                    left++;
                }    
            }
        }
        return ans;
    }
};