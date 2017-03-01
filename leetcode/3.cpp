class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool letters_used[150];
        for (int i = 0; i < 150; ++i)
            letters_used[i] = 0;
        int result = 0;
        int beg = 0; // [beg, end) interval is the longest ending in end)
        for (int end = 0; end < (int)s.size(); ++end) {
            while (letters_used[s[end]])
                letters_used[s[beg++]] = 0;
            
            // [beg, end] - longest good substring ending in end
            letters_used[s[end]] = 1;
            result = max(result, end - beg + 1);
        }
        return result;
    }
};
