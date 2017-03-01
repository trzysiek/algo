class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> M;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            auto it2 = M.find(target - *it);
            if (it2 != M.end())
                return {it2->second, it - nums.begin()};
            M[*it] = it - nums.begin();
        }
    }
};
