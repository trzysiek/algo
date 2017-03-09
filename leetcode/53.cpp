class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int sum = nums[0];
        for (size_t end = 1; end != nums.size(); ++end) {
            sum = max(0, sum) + nums[end];
            result = max(result, sum);
        }
        return result;
    }
};
