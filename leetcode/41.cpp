class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = (int)nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= N && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        // if there's an i in nums, nums[i - 1] will be equal to i
        int result = 1;
        while (result <= N && nums[result - 1] == result)
            ++result;
        return result;
    }
};
