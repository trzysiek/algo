class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int N = (int)digits.size();
        vector<int> result { (digits[N-1] + 1) % 10 };
        int shift = (digits[N-1] + 1) / 10;
        for (int i = N - 2; i >= 0; i--) {
            result.push_back((digits[i] + shift) % 10);
            shift = (digits[i] + shift) / 10;
        }
        if (shift == 1) result.push_back(1);
        reverse(result.begin(), result.end());
        return result;
    }
};
