class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (i > max_jump) return false;
            max_jump = max(max_jump, i + nums[i]);
        }
        return true;
    }
};
